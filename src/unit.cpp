#include "unit.h"

#include <stdexcept>

namespace codegen {

void Unit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    (void)unit;
    (void)flags;
    throw std::runtime_error( "Not supported" );
}

void Unit::setAccessModifier( AccessModifier access ) {
    m_access = access;
}

AccessModifier Unit::accessModifier() const {
    return m_access;
}

std::string Unit::generateShift( unsigned int level ) const {
    static const auto DEFAULT_SHIFT = "    ";
    std::string result;
    for( unsigned int i = 0; i < level; ++i ) {
        result += DEFAULT_SHIFT;
    }
    return result;
}

} // namespace codegen
