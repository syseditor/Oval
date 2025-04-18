#include "expression.h"

#include <utility>

Expression::Expression(std::string &expr)
    : expr(std::move(expr)) {}

NumericalExpression::NumericalExpression(std::string &expr, bool has_complex_numbers, std::vector<bool> complex_number_types)
    : Expression(expr), complex_numbers(has_complex_numbers), complex_number_types{std::move(complex_number_types)} {}

auto NumericalExpression::compute_complex_num_typeof_real() {
    return this->get_complex_number_types_vector()[0] ? 1.0 : 1;
}

auto NumericalExpression::compute_complex_num_typeof_imag() {
    return this->get_complex_number_types_vector()[1] ? 1.0 : 1;
}

std::vector<bool> NumericalExpression::get_complex_number_types_vector() {
    return this->complex_number_types;
}

bool NumericalExpression::has_complex_numbers() const {
    return this->complex_numbers;
}
