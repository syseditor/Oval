#include "expression.h"

#include <memory>
#include <utility>
#include <typeinfo>
#include <sstream>

template<typename T>
Number<T>::Number(T value)
    : value(std::move(value)) {}

template<typename T>
std::ostream &operator<<(std::ostream &os, Number<T> &number) {
    if(typeid(number.value).name() == "i" || typeid(number.value).name() == "d" || typeid(number.value).name() == "f")
        return os << number.value;
    return os << number.value.to_string();
}

Expression::Expression(std::string &expr)
    : expr(std::move(expr)) {}

NumericalExpression::NumericalExpression(std::string &expr, const bool has_complex_numbers, std::vector<bool> complex_number_types)
    : Expression(expr), complex_numbers(has_complex_numbers), complex_number_types{std::move(complex_number_types)} {}


bool NumericalExpression::has_complex_numbers() const noexcept{
    return this->complex_numbers;
}

VariableExpression::VariableExpression(std::string &expr, std::vector<char> &independent_variables)
    : Expression(expr), independent_variables(std::move(independent_variables)) {}

std::vector<char> &VariableExpression::get_independent_variables() noexcept {
    return this->independent_variables;
}

template<typename T>
constexpr Number<T> &NumericalExpression::evaluate() {
    if(this->has_complex_numbers()) {
        Number<T> result{T()};
        //parsing complex num expr...
        return std::make_unique<Number<T>>(result);
    }
    Number<T> result{0};

    //parsing real num expr...

    return std::make_unique<Number<T>>(result);
}

template<typename T>
constexpr Number<T> &VariableExpression::evaluate(T values[]) {
    std::string expr = this->expr;
    // Replace variables with numbers...
    NumericalExpression numExpr{expr, false, std::vector<bool>{false, false}};

    return numExpr.evaluate<T>();
}

