#include "java/java_factory.h"

#include "java/java_class_unit.h"
#include "java/java_field_unit.h"
#include "java/java_method_unit.h"
#include "java/java_print_operator_unit.h"

namespace codegen::java {

std::shared_ptr< ClassUnit > JavaFactory::createClass( const std::string& name, Flags flags ) const {
    return std::make_shared< JavaClassUnit >( name, flags );
}

std::shared_ptr< MethodUnit > JavaFactory::createMethod(
    const std::string& name, const std::string& returnType, Flags flags ) const {
    return std::make_shared< JavaMethodUnit >( name, returnType, flags );
}

std::shared_ptr< FieldUnit > JavaFactory::createField(
    const std::string& name, const std::string& type, Flags flags ) const {
    return std::make_shared< JavaFieldUnit >( name, type, flags );
}

std::shared_ptr< PrintOperatorUnit > JavaFactory::createPrintOperator( const std::string& text ) const {
    return std::make_shared< JavaPrintOperatorUnit >( text );
}

std::string JavaFactory::languageName() const {
    return "Java";
}

} // namespace codegen::java
