#ifndef CODEGEN_EXAMPLES_H
#define CODEGEN_EXAMPLES_H

#include <string>
#include <vector>

#include "factory.h"

namespace codegen {

struct MethodSpec {
    std::string name;
    std::string returnType;
    Flags flags = 0;
    AccessModifier access = AM_PUBLIC;
    std::vector< std::string > prints;
};

struct ClassSpec {
    std::string name;
    Flags classFlags = CM_UNKNOWN;
    std::vector< MethodSpec > methods;
};

std::string buildClass( const AbstractFactory& factory, const ClassSpec& spec );

ClassSpec programSpec();

ClassSpec csharpShowcaseSpec();

ClassSpec javaShowcaseSpec();

} // namespace codegen

#endif // CODEGEN_EXAMPLES_H
