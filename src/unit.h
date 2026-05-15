#ifndef CODEGEN_SRC_UNIT_H
#define CODEGEN_SRC_UNIT_H

#include <memory>
#include <string>

#include "types.h"

namespace codegen {

class Unit {
public:
    virtual ~Unit() = default;

    virtual void add( const std::shared_ptr< Unit >& unit, Flags flags );

    virtual std::string compile( unsigned int level = 0 ) const = 0;

    void setAccessModifier( AccessModifier access );

    AccessModifier accessModifier() const;

protected:
    virtual std::string generateShift( unsigned int level ) const;

    AccessModifier m_access = AM_UNKNOWN;
};

} // namespace codegen

#endif // CODEGEN_SRC_UNIT_H
