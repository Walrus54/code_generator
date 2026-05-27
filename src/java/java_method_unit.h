#ifndef CODEGEN_SRC_JAVA_JAVA_METHOD_UNIT_H
#define CODEGEN_SRC_JAVA_JAVA_METHOD_UNIT_H

#include "method_unit.h"

namespace codegen::java {

class JavaMethodUnit : public MethodUnit {
public:
    using MethodUnit::MethodUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::java

#endif // CODEGEN_SRC_JAVA_JAVA_METHOD_UNIT_H
