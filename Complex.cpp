//
// Created by gosha on 10/25/2022.
//

#include "Complex.h"
#include "iostream"
class Complex {
private:
    double re;
    double im;

public:
    Complex() :re(1), im(1) {
        std::cout << "Constructor 1" << std::endl;
    }
    Complex(double r, double i) {
        re = r;
        im = i;
        std::cout << "Constructor 2" << std::endl;
    }

    double getRe() { return re; }
    void setRe(double r) { re = r; }

    double getIm() { return im; }
    void setIm(double i) { im = i; }



    void print() {
        std::cout << "re: " << re << " , im: " << im << std::endl;
    }
    friend Complex operator+ (const Complex& a, const Complex& b);
    friend Complex operator/ (const Complex& a, const Complex& b);
    friend Complex operator/ (const Complex& a, const double b);
    friend Complex operator/ (const double a, const Complex& b);
    friend Complex operator* (const Complex& a, const Complex& b);
    friend Complex operator* (const Complex& a, const double b);
    friend Complex operator* (const double a, const Complex& b);
    Complex& operator++() {
        re += 1; //this->re
        im += 1;
        return *this;
    }

    Complex operator++(int) {
        Complex c(*this);
        re += 1;
        im += 1;
        return c;
    }

    Complex conj(const Complex& a) {
        im = -1 * a.im;
        return *this;
    }
};

Complex operator+ (const Complex& a, const Complex& b) { // z1+z2 = (a1+b1), (a2+b2)
    return Complex(a.re + b.re, a.im + b.im);
}
Complex operator/ (const Complex& a, const Complex& b) { // z1/z2 = (a1*b1 + a2*b2)/(a2^2+b2), (a2*b1-a1*b2)/(a2^2+b2^2)
    return Complex(((a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im)), ((b.re * a.im - a.re * b.im) / (b.re * b.re + b.im * b.im)));
}
Complex operator/ (const Complex& a, const double b) { // z1/b = (a1/b), (a2/b)
    return Complex(a.re / b, a.im / b);
}
Complex operator/ (const double a, const Complex& b) { // a/z1 = (a*z1*(z1.re-z1.im)/z1*(z1.re-z1.im))
    Complex c(b);
    Complex conjugate;
    c = (a * conjugate.conj(c)) / (c * conjugate.conj(c));
    return c;
}
Complex operator* (const Complex& a, const Complex& b) {
    return Complex((a.re * b.re) - (a.im * b.im), (a.re * b.im) + (a.im * b.re));
}
Complex operator* (const Complex& a, const double b) {
    return Complex(a.re * b, a.im * b);
}
Complex operator* (const double a, const Complex& b) {
    return Complex(b.re * a, b.im * a);
}