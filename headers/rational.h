//
// Created by gosha on 4/7/2023.
//

#ifndef MATRIX_RATIONAL_H
#define MATRIX_RATIONAL_H

#include <fstream>

class rational{
    friend std::istream& operator>>(std::istream & is, rational  & r);
    friend std::ostream& operator<<(std::ostream &os, rational const &r);
private:
    int denominator, numerator;
    void stabilizator();
    static int gcd(int a, int b);
public:
    rational(int num, int denom);
    rational(int num);
    rational();

    int getNumerator() const;
    int getDenominator() const;
    rational operator+(const rational &a) const;
    rational operator+(const int &a) const;
    rational operator-(const rational &a) const;
    rational operator-(const int &a) const;
    rational operator*(const rational &a) const;
    rational operator*(const int &a) const;
    rational operator/(const rational &a) const;
    rational operator/(const int &a) const;
    operator int() const;
    operator float() const;
    bool operator==(const rational &a) const;
    bool operator==(const float &a) const;
    bool operator==(const int &a) const;
    bool operator!=(const rational &a) const;
    bool operator!=(const float &a) const;
    bool operator!=(const int &a) const;



    ~rational();
};

#endif //MATRIX_RATIONAL_H
