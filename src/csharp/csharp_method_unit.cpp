#include "csharp/csharp_method_unit.h"

#include "csharp/csharp_access.h"

namespace codegen::csharp {

std::string CSharpMethodUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level ) + accessKeyword( m_access ) + " ";

    if( m_flags & MM_STATIC )   result += "static ";
    if( m_flags & MM_VIRTUAL )  result += "virtual ";
    if( m_flags & MM_ABSTRACT ) result += "abstract ";
    // const — модификатор C++; final-метод в C# выражается через sealed override,
    // что требует базового класса, поэтому на уровне метода не выводится.

    result += m_returnType + " " + m_name + "()";

    if( m_flags & MM_ABSTRACT ) {
        result += ";\n";
        return result;
    }

    result += "\n" + generateShift( level ) + "{\n";
    for( const auto& statement : m_body ) {
        result += statement->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

} // namespace codegen::csharp
