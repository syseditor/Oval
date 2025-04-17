#include "complex.h"
#include <sstream>
#include <cmath>

template<typename R, typename I>
Complex<R, I>::Complex(const R real, const I imag)
    : real(real), imag(imag) {}

template<typename R, typename I>
R Complex<R, I>::get_real_part() {
    return this->real;
}

template<typename R, typename I>
I Complex<R, I>::get_imaginary_part() {
    return this->imag;
}

template<typename R, typename I>
std::string Complex<R, I>::to_string() const {
    std::stringstream complex_stringstream;
    complex_stringstream << this->real << "+" << this->imag << "i";
    return complex_stringstream.str();
}

template<typename T>
Complex<T, T> operator+(Complex<T, T> &complex1, Complex<T, T> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() + complex2.get_real_part(), complex1.get_imaginary_part() + complex2.get_imaginary_part());
    return result;
}

template<typename R, typename I>
Complex<R, I> operator+(Complex<R, I> &complex1, Complex<R, I> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() + complex2.get_real_part(), complex1.get_imaginary_part() + complex2.get_imaginary_part());
    return result;
}

template<typename R, typename I1, typename I2>
Complex<R, double> operator+(Complex<R, I1> &complex1, Complex<R, I2> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() + complex2.get_real_part(), complex1.get_imaginary_part() + complex2.get_imaginary_part());
    return result;
}

template<typename R1, typename R2, typename I>
Complex<double, I> operator+(Complex<R1, I> &complex1, Complex<R2, I> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() + complex2.get_real_part(), complex1.get_imaginary_part() + complex2.get_imaginary_part());
    return result;
}

template<typename R1, typename I1, typename R2, typename I2>
Complex<double, double> operator+(Complex<R1, I1> &complex1, Complex<R2, I2> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() + complex2.get_real_part(), complex1.get_imaginary_part() + complex2.get_imaginary_part());
    return result;
}

template<typename T>
Complex<T, T> operator-(Complex<T, T> &complex1, Complex<T, T> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() - complex2.get_real_part(), complex1.get_imaginary_part() - complex2.get_imaginary_part());
    return result;
}

template<typename R, typename I>
Complex<R, I> operator-(Complex<R, I> &complex1, Complex<R, I> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() - complex2.get_real_part(), complex1.get_imaginary_part() - complex2.get_imaginary_part());
    return result;
}

template<typename R, typename I1, typename I2>
Complex<R, double> operator-(Complex<R, I1> &complex1, Complex<R, I2> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() - complex2.get_real_part(), complex1.get_imaginary_part() - complex2.get_imaginary_part());
    return result;
}

template<typename R1, typename R2, typename I>
Complex<double, I> operator-(Complex<R1, I> &complex1, Complex<R2, I> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() - complex2.get_real_part(), complex1.get_imaginary_part() - complex2.get_imaginary_part());
    return result;
}

template<typename R1, typename I1, typename R2, typename I2>
Complex<double, double> operator-(Complex<R1, I1> &complex1, Complex<R2, I2> &complex2) {
    const Complex<double, double> result(complex1.get_real_part() - complex2.get_real_part(), complex1.get_imaginary_part() - complex2.get_imaginary_part());
    return result;
}

template<typename T>
Complex<T, T> operator*(Complex<T, T> &complex1, Complex<T, T> &complex2) {
    const Complex<T, T> result(
        complex1.get_real_part()*complex2.get_real_part() - complex1.get_imaginary_part()*complex2.get_imaginary_part(),
        (complex1.get_real_part()*complex2.get_imaginary_part() + complex1.get_imaginary_part()*complex2.get_real_part())
        );
    return result;
}

template<typename R1, typename I1, typename R2, typename I2>
Complex<double, double> operator*(Complex<R1, I1> &complex1, Complex<R2, I2> &complex2) {
    const Complex<double, double> result(
        complex1.get_real_part()*complex2.get_real_part() - complex1.get_imaginary_part()*complex2.get_imaginary_part(),
        (complex1.get_real_part()*complex2.get_imaginary_part() + complex1.get_imaginary_part()*complex2.get_real_part())
        );
    return result;
}

template<typename R1, typename I1, typename R2, typename I2>
Complex<double, double> operator/(Complex<R1, I1> &complex1, Complex<R2, I2> &complex2) {
    if(complex2.get_real_part() == 0 && complex2.get_imaginary_part() == 0) throw std::runtime_error("Divided by zero 2 complex numbers");

    const Complex<double, double> result(
        (complex1.get_real_part()*complex2.get_real_part() + complex1.get_imaginary_part()*complex2.get_imaginary_part()) /
            (pow(complex2.get_real_part(), 2) + pow(complex2.get_imaginary_part(), 2)),
        (complex1.get_imaginary_part()*complex2.get_real_part() - complex1.get_real_part()*complex2.get_imaginary_part()) /
            (pow(complex2.get_real_part(), 2) + pow(complex2.get_imaginary_part(), 2))
        );
    return result;
}

template<typename R1, typename I1, typename R2, typename I2>
bool operator==(Complex<R1, I1> &complex1, Complex<R2, I2> &complex2) {
    return complex1.get_real_part() == complex2.get_real_part() && complex1.get_imaginary_part() == complex2.get_imaginary_part();
}

template<typename R1, typename I1, typename R2, typename I2>
bool operator!=(Complex<R1, I1> &complex1, Complex<R2, I2> &complex2) {
    return !(complex1 == complex2);
}