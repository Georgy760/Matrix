//
// Created by gosha on 4/7/2023.
//

#ifndef MATRIX_RATIONAL_H
#define MATRIX_RATIONAL_H

class rational{
private:
    int denominator, numerator;
    void stabilizator();
    static int gcd(int a, int b);
public:
    rational(int num, int denom);
    rational(int num);
    int getNum() const;
    int getDenom() const;
    rational operator+(const rational &a) const;
    rational operator+(const int &a) const;
    rational operator-(const rational &a) const;
    rational operator-(const int &a) const;
    rational operator*(const rational &a) const;
    rational operator*(const int &a) const;
    rational operator/(const rational &a) const;
    rational operator/(const int &a) const;

    bool operator==(const rational &a) const;
    bool operator!=(const rational &a) const;
    ~rational();
};
#endif //MATRIX_RATIONAL_H
