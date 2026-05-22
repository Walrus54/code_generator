#ifndef CODEGEN_SRC_CPP_CPP_METHOD_UNIT_H
#define CODEGEN_SRC_CPP_CPP_METHOD_UNIT_H

#include "method_unit.h"

namespace codegen::cpp {

// Узел метода C++ (static/virtual/const/final, чистая виртуальность).
class CppMethodUnit : public MethodUnit {
public:
    using MethodUnit::MethodUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::cpp

#endif // CODEGEN_SRC_CPP_CPP_METHOD_UNIT_H
