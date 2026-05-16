#ifndef CODEGEN_SRC_CPP_CPP_CLASS_UNIT_H
#define CODEGEN_SRC_CPP_CPP_CLASS_UNIT_H

#include "class_unit.h"

namespace codegen::cpp {

// Узел класса C++ (члены под метками public:/protected:/private:).
class CppClassUnit : public ClassUnit {
public:
    using ClassUnit::ClassUnit;
    std::string compile( unsigned int level = 0 ) const override;
};

} // namespace codegen::cpp

#endif // CODEGEN_SRC_CPP_CPP_CLASS_UNIT_H
