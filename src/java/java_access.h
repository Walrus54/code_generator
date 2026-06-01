#ifndef CODEGEN_SRC_JAVA_JAVA_ACCESS_H
#define CODEGEN_SRC_JAVA_JAVA_ACCESS_H

// Сопоставление модификатора доступа ключевому слову Java.
// Источник набора — proglang.su/java/modifiers.

#include <string>

#include "types.h"

namespace codegen::java {

// Package-private — пустая строка.
inline std::string accessKeyword( AccessModifier access ) {
    switch( access ) {
        case AM_PUBLIC:    return "public";
        case AM_PROTECTED: return "protected";
        case AM_PRIVATE:   return "private";
        default:        return ""; // package-private / значения только для C#
    }
}

} // namespace codegen::java

#endif // CODEGEN_SRC_JAVA_JAVA_ACCESS_H
