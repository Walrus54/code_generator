#ifndef CODEGEN_SRC_CSHARP_CSHARP_FIELD_UNIT_H
#define CODEGEN_SRC_CSHARP_CSHARP_FIELD_UNIT_H

#include "field_unit.h"

namespace codegen::csharp {

// Узел поля C#: static; readonly из MM_FINAL.
class CSharpFieldUnit : public FieldUnit {
public:
    using FieldUnit::FieldUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::csharp

#endif // CODEGEN_SRC_CSHARP_CSHARP_FIELD_UNIT_H
