#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "complex.h"
#include <vector>

template<typename T>
union Number{
    T value;
    explicit Number(T value);
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

public:
    NumericalExpression(std::string &expr, bool has_complex_numbers, std::vector<bool> complex_number_types = std::vector<bool>{false, true});
    bool has_complex_numbers() const noexcept;
    template<typename T> Number<T> &evaluate();
};

class VariableExpression final : public Expression{
    std::vector<char> independent_variables;
public:
    VariableExpression(std::string &expr, std::vector<char> &independent_variables);
    std::vector<char> &get_independent_variables() noexcept;
    template<typename T> Number<T> &evaluate(T values[]);
};

#endif //EXPRESSION_H
