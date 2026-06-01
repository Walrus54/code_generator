#include "java/java_class_unit.h"

namespace codegen::java {

std::string JavaClassUnit::compile( unsigned int level ) const {
    std::string mods;
    if( m_flags & CM_ABSTRACT ) mods += "abstract ";
    if( m_flags & CM_FINAL )    mods += "final ";

    std::string shift = generateShift( level );
    std::string result = shift + mods + "class " + m_name + " {\n";
    for( const auto& member : m_members ) {
        result += member->compile( level + 1 );
    }
    result += shift + "}\n";
    return result;
}

} // namespace codegen::java
