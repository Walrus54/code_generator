#ifndef CODEGEN_SRC_CSHARP_CSHARP_ACCESS_H
#define CODEGEN_SRC_CSHARP_CSHARP_ACCESS_H

// Источник набора модификаторов — metanit.com/sharp/tutorial/3.2.php.

#include <string>

#include "types.h"

namespace codegen::csharp {

// Package-private отображается в private.
inline std::string accessKeyword( AccessModifier access ) {
    switch( access ) {
        case AM_PUBLIC:             return "public";
        case AM_PROTECTED:          return "protected";
        case AM_INTERNAL:           return "internal";
        case AM_PROTECTED_INTERNAL: return "protected internal";
        case AM_PRIVATE_PROTECTED:  return "private protected";
        case AM_FILE:        return "file";
        case AM_PRIVATE:
        default:                 return "private";
    }
}

} // namespace codegen::csharp

#endif // CODEGEN_SRC_CSHARP_CSHARP_ACCESS_H
