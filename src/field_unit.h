#ifndef CODEGEN_SRC_FIELD_UNIT_H
#define CODEGEN_SRC_FIELD_UNIT_H

#include <string>

#include "unit.h"

namespace codegen {

// Конкретные языки реализуют compile().
class FieldUnit : public Unit {
public:
    FieldUnit( const std::string& name, const std::string& type, Flags flags );

protected:
    std::string m_name;
    std::string m_type;
    Flags m_flags;
};

} // namespace codegen

#endif // CODEGEN_SRC_FIELD_UNIT_H
