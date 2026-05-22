#include "cpp/cpp_class_unit.h"

#include <array>

namespace codegen::cpp {
namespace {

const char* sectionKeyword( AccessModifier access ) {
    switch( access ) {
        case AM_PUBLIC:    return "public";
        case AM_PROTECTED: return "protected";
        default:        return "private";
    }
}

// Значения, которых в C++ нет (internal и т. п.), попадают в private,
// иначе член молча потерялся бы при генерации.
AccessModifier cppSection( AccessModifier access ) {
    return ( access == AM_PUBLIC || access == AM_PROTECTED ) ? access : AM_PRIVATE;
}

} // namespace

std::string CppClassUnit::compile( unsigned int level ) const {
    std::string shift = generateShift( level );
    std::string result = shift + "class " + m_name;
    if( m_flags & CM_FINAL ) {
        result += " final";
    }
    result += " {\n";

    static constexpr std::array< AccessModifier, 3 > order = { AM_PUBLIC, AM_PROTECTED, AM_PRIVATE };
    for( AccessModifier access : order ) {
        bool opened = false;
        for( const auto& member : m_members ) {
            if( cppSection( member->accessModifier() ) != access ) {
                continue;
            }
            if( !opened ) {
                result += shift + sectionKeyword( access ) + ":\n";
                opened = true;
            }
            result += member->compile( level + 1 );
        }
        if( opened ) {
            result += "\n";
        }
    }

    result += shift + "};\n";
    return result;
}

} // namespace codegen::cpp
