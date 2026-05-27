#ifndef CODEGEN_SRC_JAVA_JAVA_FIELD_UNIT_H
#define CODEGEN_SRC_JAVA_JAVA_FIELD_UNIT_H

#include "field_unit.h"

namespace codegen::java {

class JavaFieldUnit : public FieldUnit {
public:
    using FieldUnit::FieldUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::java

#endif // CODEGEN_SRC_JAVA_JAVA_FIELD_UNIT_H
