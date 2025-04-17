#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "complex.h"

template<typename R, typename I>
union Number{
    int integer;
    double real;
    Complex<R, I> complex;
};

class NumericalExpression final {
    std::string expr;
    bool has_complex_numbers;
    bool complex_number_types[2]; // false for int, true for double(float counts too)
public:
    explicit NumericalExpression(std::string expr, bool has_complex_numbers, bool complex_number_types[2]);
    auto compute_complex_num_types();
    Number<typeof(compute_complex_num_types()), typeof(compute_complex_num_types())> evaluate();
};

class VariableExpression final {

};

#endif //EXPRESSION_H
