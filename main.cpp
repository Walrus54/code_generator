#include <iostream>

#include "cpp/cpp_factory.h"
#include "csharp/csharp_factory.h"
#include "examples.h"
#include "java/java_factory.h"

using namespace codegen;

namespace {

void printSection( const std::string& title, const std::string& code ) {
    std::cout << "// ===== " << title << " =====\n" << code << "\n";
}

} // namespace

int main() {
    cpp::CppFactory cppFactory;
    csharp::CSharpFactory csharpFactory;
    java::JavaFactory javaFactory;

    // Одна и та же спецификация (с флагами) собирается на всех трёх языках.
    const ClassSpec program = programSpec();
    printSection( cppFactory.languageName() + " : MyClass", buildClass( cppFactory, program ) );
    printSection( csharpFactory.languageName() + "  : MyClass", buildClass( csharpFactory, program ) );
    printSection( javaFactory.languageName() + " : MyClass", buildClass( javaFactory, program ) );

    // Демонстрации модификаторов, специфичных для каждого языка.
    printSection( csharpFactory.languageName() + "  : modifier showcase",
                  buildClass( csharpFactory, csharpShowcaseSpec() ) );
    printSection( javaFactory.languageName() + " : modifier showcase",
                  buildClass( javaFactory, javaShowcaseSpec() ) );

    return 0;
}
