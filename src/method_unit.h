#ifndef CODEGEN_SRC_METHOD_UNIT_H
#define CODEGEN_SRC_METHOD_UNIT_H

#include <string>
#include <vector>

#include "unit.h"

namespace codegen {

// Хранит сигнатуру и операторы тела. Конкретные языки реализуют compile() и
// решают, какие флаги модификаторов выводить.
class MethodUnit : public Unit {
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags );

    void add( const std::shared_ptr< Unit >& unit, Flags flags = 0 ) override;

protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

} // namespace codegen

#endif // CODEGEN_SRC_METHOD_UNIT_H
