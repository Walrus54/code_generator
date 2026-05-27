#include "java/java_field_unit.h"

#include "java/java_access.h"

namespace codegen::java {

std::string JavaFieldUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );
    std::string access = accessKeyword( m_access );
    if( !access.empty() ) result += access + " ";
    if( m_flags & MM_STATIC ) result += "static ";
    if( m_flags & MM_FINAL )  result += "final ";
    result += m_type + " " + m_name + ";\n";
    return result;
}

} // namespace codegen::java
