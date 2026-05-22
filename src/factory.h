#ifndef CODEGEN_SRC_FACTORY_H
#define CODEGEN_SRC_FACTORY_H

#include <memory>
#include <string>

#include "class_unit.h"
#include "field_unit.h"
#include "method_unit.h"
#include "print_operator_unit.h"
#include "types.h"

namespace codegen {

// Объявляет по одному фабричному методу на тип продукта. Конкретная фабрика
// порождает семейство узлов своего языка. Клиентский код зависит только от
// этого интерфейса.
class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

    virtual std::shared_ptr< ClassUnit > createClass(
        const std::string& name, Flags flags = 0 ) const = 0;

    virtual std::shared_ptr< MethodUnit > createMethod(
        const std::string& name, const std::string& returnType, Flags flags = 0 ) const = 0;

    virtual std::shared_ptr< FieldUnit > createField(
        const std::string& name, const std::string& type, Flags flags = 0 ) const = 0;

    virtual std::shared_ptr< PrintOperatorUnit > createPrintOperator(
        const std::string& text ) const = 0;

    virtual std::string languageName() const = 0;
};

} // namespace codegen

#endif // CODEGEN_SRC_FACTORY_H
