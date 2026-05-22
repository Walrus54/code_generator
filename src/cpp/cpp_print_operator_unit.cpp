#include "cpp/cpp_print_operator_unit.h"

#include "text_util.h"

namespace codegen::cpp {

std::string CppPrintOperatorUnit::compile( unsigned int level ) const {
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}

} // namespace codegen::cpp
