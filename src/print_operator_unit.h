#ifndef CODEGEN_SRC_PRINT_OPERATOR_UNIT_H
#define CODEGEN_SRC_PRINT_OPERATOR_UNIT_H

#include <string>

#include "unit.h"

namespace codegen {

// Конкретные языки реализуют compile().
class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text );

protected:
    std::string m_text;
};

} // namespace codegen

#endif // CODEGEN_SRC_PRINT_OPERATOR_UNIT_H
