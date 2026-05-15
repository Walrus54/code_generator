#ifndef CODEGEN_SRC_TEXT_UTIL_H
#define CODEGEN_SRC_TEXT_UTIL_H

#include <stdexcept>
#include <string>

namespace codegen {

// Экранирует спецсимволы, чтобы текст нельзя было «вырваться» из строкового
// литерала и внедрить произвольный код в генерируемую программу.
inline std::string escapeStringLiteral( const std::string& text ) {
    std::string result;
    result.reserve( text.size() );
    for( char c : text ) {
        switch( c ) {
            case '\\': result += "\\\\"; break;
            case '\"': result += "\\\""; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            default:   result += c; break;
        }
    }
    return result;
}

inline const std::string& requireNonEmpty( const std::string& value, const char* what ) {
    if( value.empty() ) {
        throw std::invalid_argument( std::string( what ) + " must not be empty" );
    }
    return value;
}

// Проверяет, что строка — корректный идентификатор ([A-Za-z_][A-Za-z0-9_]*),
// защищая генерируемый код от инъекции через имена классов/методов/полей.
inline bool isIdentChar( char c, bool first ) {
    return c == '_' || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ||
           ( !first && c >= '0' && c <= '9' );
}

inline const std::string& requireIdentifier( const std::string& name, const char* what ) {
    requireNonEmpty( name, what );
    for( std::size_t i = 0; i < name.size(); ++i ) {
        if( !isIdentChar( name[ i ], i == 0 ) ) {
            throw std::invalid_argument( std::string( what ) + " is not a valid identifier: " + name );
        }
    }
    return name;
}

} // namespace codegen

#endif // CODEGEN_SRC_TEXT_UTIL_H
