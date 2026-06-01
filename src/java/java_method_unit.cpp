#include "java/java_method_unit.h"

#include "java/java_access.h"

namespace codegen::java {

std::string JavaMethodUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );
    std::string access = accessKeyword( m_access );
    if( !access.empty() ) result += access + " ";

    if( m_flags & MM_STATIC )   result += "static ";
    if( m_flags & MM_FINAL )    result += "final ";
    if( m_flags & MM_ABSTRACT ) result += "abstract ";
    // const / virtual — не модификаторы Java, игнорируются.

    result += m_returnType + " " + m_name + "()";

    // У абстрактного метода в Java нет тела.
    if( m_flags & MM_ABSTRACT ) {
        result += ";\n";
        return result;
    }

    result += " {\n";
    for( const auto& statement : m_body ) {
        result += statement->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

} // namespace codegen::java
