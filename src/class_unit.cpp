#include "class_unit.h"

#include "text_util.h"

namespace codegen {

ClassUnit::ClassUnit( const std::string& name, Flags flags )
    : m_name( requireIdentifier( name, "class name" ) ), m_flags( flags ) {}

void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    unit->setAccessModifier( static_cast< AccessModifier >( flags ) );
    m_members.push_back( unit );
}

} // namespace codegen
