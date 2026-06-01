#ifndef CODEGEN_SRC_CSHARP_CSHARP_PRINT_OPERATOR_UNIT_H
#define CODEGEN_SRC_CSHARP_CSHARP_PRINT_OPERATOR_UNIT_H

#include "print_operator_unit.h"

namespace codegen::csharp {

// Узел оператора печати C#: через System.Console.WriteLine.
class CSharpPrintOperatorUnit : public PrintOperatorUnit {
public:
    using PrintOperatorUnit::PrintOperatorUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::csharp

#endif // CODEGEN_SRC_CSHARP_CSHARP_PRINT_OPERATOR_UNIT_H
