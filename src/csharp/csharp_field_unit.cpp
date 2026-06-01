#include "csharp/csharp_field_unit.h"

#include "csharp/csharp_access.h"

namespace codegen::csharp {

std::string CSharpFieldUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level ) + accessKeyword( m_access ) + " ";
    if( m_flags & MM_STATIC ) result += "static ";
    if( m_flags & MM_FINAL )  result += "readonly "; // final-поле в C# — readonly.
    result += m_type + " " + m_name + ";\n";
    return result;
}

} // namespace codegen::csharp
