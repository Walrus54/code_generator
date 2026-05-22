#include "cpp/cpp_method_unit.h"

namespace codegen::cpp {

std::string CppMethodUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );
    if( m_flags & MM_STATIC ) {
        result += "static ";
    } else if( m_flags & ( MM_VIRTUAL | MM_ABSTRACT ) ) {
        result += "virtual ";
    }
    result += m_returnType + " " + m_name + "()";
    if( m_flags & MM_CONST ) {
        result += " const";
    }
    if( m_flags & MM_FINAL ) {
        result += " final";
    }
    // Чистая виртуальная функция — без тела.
    if( m_flags & MM_ABSTRACT ) {
        result += " = 0;\n";
        return result;
    }
    result += " {\n";
    for( const auto& statement : m_body ) {
        result += statement->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

} // namespace codegen::cpp
