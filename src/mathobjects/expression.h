#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "complex.h"
#include <vector>

template<typename R, typename I>
union Number{
    int integer;
    double real;
    Complex<R, I> complex;
};

class Expression {
protected:
    std::string expr;
public:
    explicit Expression(std::string &expr);
};

class NumericalExpression final : public Expression{
    bool complex_numbers;
    std::vector<bool> complex_number_types; // false for int, true for double(float counts too)

    std::vector<bool> get_complex_number_types_vector();
    auto compute_complex_num_typeof_real();
    auto compute_complex_num_typeof_imag();
public:
    NumericalExpression(std::string &expr, bool has_complex_numbers, std::vector<bool> complex_number_types);
    bool has_complex_numbers() const;

    constexpr Number<auto, auto> evaluate();
};

class VariableExpression final : public Expression{
    std::vector<char> independent_variables;
public:
    VariableExpression(std::string &expr, std::vector<char> independent_variables);
    constexpr Number<auto, auto> evaluate();
};

#endif //EXPRESSION_H
