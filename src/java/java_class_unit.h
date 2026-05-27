#ifndef CODEGEN_SRC_JAVA_JAVA_CLASS_UNIT_H
#define CODEGEN_SRC_JAVA_JAVA_CLASS_UNIT_H

#include "class_unit.h"

namespace codegen::java {

class JavaClassUnit : public ClassUnit {
public:
    using ClassUnit::ClassUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::java

#endif // CODEGEN_SRC_JAVA_JAVA_CLASS_UNIT_H
