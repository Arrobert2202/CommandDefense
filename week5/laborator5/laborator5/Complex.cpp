#include "Complex.h"

bool double_equals(double l, double r)
{
    return abs(l - r) < 0.001;
}

Complex::Complex() : Complex(0, 0)
{
}

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::real() const
{
    return real_data;
}

double Complex::imag() const
{
    return imag_data;
}

double Complex::abs() const
{
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const
{
    return { real(), -imag() };
}

Complex operator+(const Complex& l, const Complex& r)
{
    return { l.real() + r.real(), r.imag() + l.imag() };
}
Complex operator+(const Complex& l, double r)
{

    return { l.real() + r,l.imag() };
}
Complex operator+(double l, const Complex& r)
{
    return { l + r.real(), r.imag() };
}

Complex operator-(const Complex& l, const Complex& r)
{
    return { l.real() - r.real(), l.imag() - r.imag() };
}
Complex operator-(const Complex& l, double r)
{
    return { l.real() - r, l.imag() };
}
Complex operator-(double l, const Complex& r)
{
    return { l - r.real(), r.imag() };
}
Complex operator*(const Complex& l, const Complex& r)
{
    return { l.real() * r.real()-l.imag()*r.imag(), l.real()*r.imag() + l.imag()*r.real() };
}

bool operator==(const Complex& l,const Complex& r)
{
    if ((l.real() == r.real()) && (l.imag() == r.imag()))
        return true;
    return false;
}
bool operator!=(const Complex& l, const Complex& r)
{
    if ((l.real() != r.real()) || (l.imag() != r.imag()))
        return true;
    return false;
}

