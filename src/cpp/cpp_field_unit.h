#ifndef CODEGEN_SRC_CPP_CPP_FIELD_UNIT_H
#define CODEGEN_SRC_CPP_CPP_FIELD_UNIT_H

#include "field_unit.h"

namespace codegen::cpp {

// Узел поля C++ (static/const).
class CppFieldUnit : public FieldUnit {
public:
    using FieldUnit::FieldUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::cpp

#endif // CODEGEN_SRC_CPP_CPP_FIELD_UNIT_H
