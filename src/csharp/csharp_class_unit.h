#ifndef CODEGEN_SRC_CSHARP_CSHARP_CLASS_UNIT_H
#define CODEGEN_SRC_CSHARP_CSHARP_CLASS_UNIT_H

#include "class_unit.h"

namespace codegen::csharp {

// Узел класса C#: abstract; sealed из CM_FINAL.
class CSharpClassUnit : public ClassUnit {
public:
    using ClassUnit::ClassUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::csharp

#endif // CODEGEN_SRC_CSHARP_CSHARP_CLASS_UNIT_H
