# Лабораторная работа по предмету: «Технологии программирования»

## Тема: «Абстрактная фабрика»

> 4 курс 2 семестр

## 1. Постановка задачи

Необходимо расширить реализацию генератора программ так, чтобы из единой
архитектуры порождать код на нескольких языках программирования:

- C++
- C#
- Java

Сгенерированные программы должны:

- корректно формироваться для выбранного языка;
- компилироваться без ошибок средствами соответствующего языка.

В рамках работы требуется:

- добавить модификаторы классов и методов, отсутствующие в C++, но присутствующие в C# и Java;
- для C# ориентироваться на материалы: https://metanit.com/sharp/tutorial/3.2.php;
- для Java ориентироваться на материалы: http://proglang.su/java/modifiers (до п. 3.4 включительно);
- не включать модификаторы Java: `synchronized`, `transient`, `volatile`.

Для решения задачи используется паттерн проектирования «Абстрактная фабрика».

## 2. Предлагаемое решение

### Зависимости проекта

- **CMake** ≥ 3.12
- **Стандарт C++** 17

### Архитектура решения

Узлы синтаксиса (`Unit`) и фабрика разделены на абстрактный интерфейс и
конкретные реализации под каждый язык:

```
AbstractFactory ─► createClass / createMethod / createField / createPrintOperator
      ▲
      ├── cpp::CppFactory        → CppClassUnit,    CppMethodUnit,    …
      ├── csharp::CSharpFactory  → CSharpClassUnit, CSharpMethodUnit, …
      └── java::JavaFactory      → JavaClassUnit,   JavaMethodUnit,   …
```

Основные компоненты:

- **main.cpp** — точка входа демонстрации: создаёт фабрики C++, C# и Java, собирает одни и те же спецификации классов на трёх языках и печатает результат.
- **examples.{h,cpp}** — переиспользуемые сборщики демо-программ. `buildClass(factory, spec)` принимает фабрику и спецификацию `ClassSpec` (имя, флаги класса, список методов с их флагами и модификаторами доступа).
- **src/unit.{h,cpp}** — базовый узел `Unit` (`add`, `compile`, модификатор доступа).
- **src/class_unit, method_unit, field_unit, print_operator_unit** — абстрактные узлы генерации; конкретные языки реализуют `compile()`.
- **src/factory.h** — интерфейс `AbstractFactory`: по одному фабричному методу на тип продукта. Клиентский код зависит только от этого интерфейса.
- **src/cpp / src/csharp / src/java** — реализации генерации под каждый язык (узлы + конкретная фабрика); `csharp_access.h`, `java_access.h` — раскладка модификаторов доступа.
- **src/types.h** — флаги и перечисления модификаторов (`AccessModifier`, `MethodModifier`, `ClassModifier`).

### Модификаторы, которых нет в C++

Набор модификаторов взят из источников, заданных в ТЗ, а не «по памяти»:

- C# — [metanit.com/sharp/tutorial/3.2.php](https://metanit.com/sharp/tutorial/3.2.php) (модификаторы доступа);
- Java — [proglang.su/java/modifiers](http://proglang.su/java/modifiers) (до п. 3.4; `synchronized`, `transient`, `volatile` не включаются).

| Категория | C#                                                                    | Java                                  |
| --------- | --------------------------------------------------------------------- | ------------------------------------- |
| Доступ    | `internal`, `protected internal`, `private protected`, `file` (C# 11) | package-private (без ключевого слова) |
| Класс     | `abstract`, `sealed` (из `CM_FINAL`)                                  | `abstract`, `final`                   |
| Метод     | `static`, `virtual`, `abstract`                                       | `static`, `final`, `abstract`         |
| Поле      | `static`, `readonly` (из `MM_FINAL`)                                  | `static`, `final`                     |

Один и тот же флаг рендерится по-разному в зависимости от языка; лишние для
языка флаги игнорируются.

## 3. Инструкция для пользователя

### Сборка (CMake)

<details>
<summary>Linux / macOS</summary>

```bash
cmake -S . -B build
cmake --build build
./build/code_generator
```

</details>

<details>
<summary>Windows</summary>

```powershell
cmake -S . -B build
cmake --build build
./build/code_generator
```

</details>

Без CMake:

```bash
g++ -std=c++17 -Isrc -I. -o code_generator main.cpp examples.cpp src/*.cpp src/*/*.cpp
./code_generator
```

### Демонстрация через `buildClass(...)`

Для ручной проверки генерации используется функция `codegen::buildClass(factory, spec)`
из [examples.h](./examples.h). Она принимает конкретную фабрику и спецификацию класса.

Структуры параметров:

```cpp
struct MethodSpec {
    std::string name;
    std::string returnType;
    Flags flags = 0;                  // MM_* из types.h
    AccessModifier access = AM_PUBLIC;
    std::vector<std::string> prints;  // тела print-операторов
};

struct ClassSpec {
    std::string name;
    Flags classFlags = CM_UNKNOWN;    // CM_* из types.h
    std::vector<MethodSpec> methods;
};

std::string buildClass(const AbstractFactory& factory, const ClassSpec& spec);
```

Пример заполнения:

```cpp
codegen::cpp::CppFactory factory;
codegen::ClassSpec spec{
    "DemoClass",
    codegen::CM_UNKNOWN,
    {
        { "Run", "void", 0, codegen::AM_PUBLIC, { "Hello, world!\n" } },
        { "Log", "void", codegen::MM_STATIC, codegen::AM_PRIVATE, {} },
    },
};
std::cout << codegen::buildClass( factory, spec );
```

Что делает `buildClass(...)`:

1. Создаёт класс с именем и флагами из `spec` через переданную фабрику.
2. Для каждого метода создаёт узел метода с его флагами.
3. Для каждого текста из `prints` создаёт print-оператор и добавляет его в тело метода.
4. Добавляет метод в класс с его модификатором доступа.
5. Возвращает результат `compile()`.

Достаточно передать другую конкретную фабрику (`CppFactory`, `CSharpFactory`,
`JavaFactory`) — и та же спецификация соберётся на другом языке.
