#include "csharp/csharp_factory.h"

#include "csharp/csharp_class_unit.h"
#include "csharp/csharp_field_unit.h"
#include "csharp/csharp_method_unit.h"
#include "csharp/csharp_print_operator_unit.h"

namespace codegen::csharp {

std::shared_ptr< ClassUnit > CSharpFactory::createClass( const std::string& name, Flags flags ) const {
    return std::make_shared< CSharpClassUnit >( name, flags );
}

std::shared_ptr< MethodUnit > CSharpFactory::createMethod(
    const std::string& name, const std::string& returnType, Flags flags ) const {
    return std::make_shared< CSharpMethodUnit >( name, returnType, flags );
}

std::shared_ptr< FieldUnit > CSharpFactory::createField(
    const std::string& name, const std::string& type, Flags flags ) const {
    return std::make_shared< CSharpFieldUnit >( name, type, flags );
}

std::shared_ptr< PrintOperatorUnit > CSharpFactory::createPrintOperator( const std::string& text ) const {
    return std::make_shared< CSharpPrintOperatorUnit >( text );
}

std::string CSharpFactory::languageName() const {
    return "C#";
}

} // namespace codegen::csharp
