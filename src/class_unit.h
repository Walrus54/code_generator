#ifndef CODEGEN_SRC_CLASS_UNIT_H
#define CODEGEN_SRC_CLASS_UNIT_H

#include <string>
#include <vector>

#include "unit.h"

namespace codegen {

// Хранит имя, модификаторы класса и упорядоченный список членов (каждый член
// несёт собственный модификатор доступа). Конкретные языки реализуют compile().
class ClassUnit : public Unit {
public:
    ClassUnit( const std::string& name, Flags flags );

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override;

protected:
    std::string m_name;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_members;
};

} // namespace codegen

#endif // CODEGEN_SRC_CLASS_UNIT_H
