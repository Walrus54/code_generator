#ifndef CODEGEN_SRC_CPP_CPP_PRINT_OPERATOR_UNIT_H
#define CODEGEN_SRC_CPP_CPP_PRINT_OPERATOR_UNIT_H

#include "print_operator_unit.h"

namespace codegen::cpp {

// Узел оператора печати C++ (через printf).
class CppPrintOperatorUnit : public PrintOperatorUnit {
public:
    using PrintOperatorUnit::PrintOperatorUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::cpp

#endif // CODEGEN_SRC_CPP_CPP_PRINT_OPERATOR_UNIT_H
