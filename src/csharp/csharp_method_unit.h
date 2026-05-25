#ifndef CODEGEN_SRC_CSHARP_CSHARP_METHOD_UNIT_H
#define CODEGEN_SRC_CSHARP_CSHARP_METHOD_UNIT_H

#include "method_unit.h"

namespace codegen::csharp {

// Узел метода C#: static/virtual/abstract.
class CSharpMethodUnit : public MethodUnit {
public:
    using MethodUnit::MethodUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::csharp

#endif // CODEGEN_SRC_CSHARP_CSHARP_METHOD_UNIT_H
