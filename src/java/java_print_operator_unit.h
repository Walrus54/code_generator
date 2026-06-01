#ifndef CODEGEN_SRC_JAVA_JAVA_PRINT_OPERATOR_UNIT_H
#define CODEGEN_SRC_JAVA_JAVA_PRINT_OPERATOR_UNIT_H

#include "print_operator_unit.h"

namespace codegen::java {

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    using PrintOperatorUnit::PrintOperatorUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::java

#endif // CODEGEN_SRC_JAVA_JAVA_PRINT_OPERATOR_UNIT_H
