#include "method_unit.h"

#include "text_util.h"

namespace codegen {

MethodUnit::MethodUnit( const std::string& name, const std::string& returnType, Flags flags )
    : m_name( requireIdentifier( name, "method name" ) ),
      m_returnType( requireNonEmpty( returnType, "method return type" ) ),
      m_flags( flags ) {}

void MethodUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    (void)flags;
    m_body.push_back( unit );
}

} // namespace codegen
