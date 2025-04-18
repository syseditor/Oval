#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

template<typename R, typename I>
class Complex final {
    R real;
    I imag;
public:
    Complex(R real, I imag);
    R get_real_part();
    I get_imaginary_part();
    double modulus();
    std::string to_string() const;
};

#endif //COMPLEX_H
