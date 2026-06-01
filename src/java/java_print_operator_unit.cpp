#include "java/java_print_operator_unit.h"

#include "text_util.h"

namespace codegen::java {

std::string JavaPrintOperatorUnit::compile( unsigned int level ) const {
    return generateShift( level ) + "System.out.println( \"" + escapeStringLiteral( m_text ) + "\" );\n";
}

} // namespace codegen::java
