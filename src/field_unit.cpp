#include "field_unit.h"

#include "text_util.h"

namespace codegen {

FieldUnit::FieldUnit( const std::string& name, const std::string& type, Flags flags )
    : m_name( requireIdentifier( name, "field name" ) ),
      m_type( requireNonEmpty( type, "field type" ) ),
      m_flags( flags ) {}

} // namespace codegen
