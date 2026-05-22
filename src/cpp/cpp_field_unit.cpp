#include "cpp/cpp_field_unit.h"

namespace codegen::cpp {

std::string CppFieldUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );
    if( m_flags & MM_STATIC ) {
        result += "static ";
    }
    if( m_flags & MM_CONST ) {
        result += "const ";
    }
    result += m_type + " " + m_name + ";\n";
    return result;
}

} // namespace codegen::cpp
