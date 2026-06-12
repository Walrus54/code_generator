#include "cpp/cpp_print_operator_unit.h"

#include "text_util.h"

namespace codegen::cpp {

std::string CppPrintOperatorUnit::compile( unsigned int level ) const {
    // "%s" вместо подстановки текста в формат printf — иначе символы '%' в
    // тексте превращаются в format-string и читают мусор из стека.
    return generateShift( level ) + "printf( \"%s\", \"" + escapeStringLiteral( m_text ) + "\" );\n";
}

} // namespace codegen::cpp
