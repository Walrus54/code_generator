#ifndef CODEGEN_SRC_TYPES_H
#define CODEGEN_SRC_TYPES_H

// Набор модификаторов взят из источников, заданных в ТЗ:
//   - C#   — https://metanit.com/sharp/tutorial/3.2.php (модификаторы доступа);
//   - Java — http://proglang.su/java/modifiers (до п. 3.4; synchronized,
//            transient, volatile не включаются).
// Поля используют те же флаги, что и методы (static/const/final).

namespace codegen {

using Flags = unsigned int;

enum AccessModifier {
    AM_UNKNOWN            = 0,                          // package-private (Java, без слова)
    AM_PUBLIC             = 1 << 0,
    AM_PROTECTED          = 1 << 1,
    AM_PRIVATE            = 1 << 2,
    AM_PRIVATE_PROTECTED  = AM_PRIVATE | AM_PROTECTED,  // private protected — C#
    AM_INTERNAL           = 1 << 4,                     // internal — C#
    AM_PROTECTED_INTERNAL = AM_PROTECTED | AM_INTERNAL, // protected internal — C#
    AM_FILE               = 1 << 6                      // file — C# 11 (доступ в пределах файла)
};

enum MethodModifier {
    MM_UNKNOWN  = 0,
    MM_STATIC   = 1 << 0,
    MM_CONST    = 1 << 1,    // const — C++
    MM_VIRTUAL  = 1 << 2,
    MM_FINAL    = 1 << 3,    // final — Java/C# (для поля C# — readonly)
    MM_ABSTRACT = 1 << 4,

    MM_STATIC_CONST          = MM_STATIC | MM_CONST,
    MM_STATIC_VIRTUAL        = MM_STATIC | MM_VIRTUAL,
    MM_FINAL_CONST           = MM_FINAL | MM_CONST,
    MM_STATIC_FINAL          = MM_STATIC | MM_FINAL,
    MM_STATIC_ABSTRACT       = MM_STATIC | MM_ABSTRACT,
    MM_FINAL_ABSTRACT        = MM_FINAL | MM_ABSTRACT,
    MM_STATIC_FINAL_ABSTRACT = MM_STATIC | MM_FINAL | MM_ABSTRACT
};

enum ClassModifier {
    CM_UNKNOWN        = 0,
    CM_FINAL          = 1 << 7,               // final — Java (для C# трактуется как sealed)
    CM_ABSTRACT       = 1 << 8,
    CM_ABSTRACT_FINAL = CM_ABSTRACT | CM_FINAL
};

} // namespace codegen

#endif // CODEGEN_SRC_TYPES_H
