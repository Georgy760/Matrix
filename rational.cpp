#include <sstream>
#include "headers/rational.h"

rational::rational(int num, int denom) { //Конструктор инициализации
    denominator = denom;
    numerator = num;
    stabilizator();
}

rational::rational(int num) { //Конструктор инициализации от целочисленного значения
    numerator = num;
    denominator = 1;
}

rational::rational() {} //Конструктор по умолчанию

int rational::getNumerator() const {return numerator;}
int rational::getDenominator() const {return denominator;}
int rational::gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
void rational::stabilizator() {
    int total = gcd(denominator, numerator);
    denominator = denominator / total;
    numerator = numerator / total;
}



rational rational::operator+(const rational &a) const {
    return rational(this->numerator * a.denominator + a.numerator * this->denominator,
                    this->denominator * a.denominator);
}

rational rational::operator+(int a) const {
    rational tmp(a, a);
    return rational(this->numerator * tmp.denominator + tmp.numerator * this->denominator,
                    this->denominator * tmp.denominator);
}

rational rational::operator-(const rational &a) const {
    return rational(this->numerator * a.denominator - a.numerator * this->denominator,
                    this->denominator * a.denominator);
}

rational rational::operator-(int a) const {
    rational tmp(a, a);
    return rational(this->numerator * tmp.denominator - tmp.numerator * this->denominator,
                    this->denominator * tmp.denominator);
}

rational rational::operator*(const rational &a) const {
    return rational(this->numerator * a.numerator, this->denominator * a.denominator);
}
rational rational::operator*(int a) const {return rational(this->numerator * a);}
rational rational::operator/(const rational &a) const {
    return rational(this->numerator * a.denominator, this->denominator * a.numerator);
}
rational rational::operator/(int a) const {return rational(this->denominator * a);}
rational::operator int() const {return numerator / denominator;}
rational::operator float() const {return float(numerator) / float(denominator);}

bool rational::operator==(const rational &a) const {
    return bool(this->numerator == a.numerator && denominator == a.denominator);
}

bool rational::operator==(float a) const {
    return bool(float(this->numerator) / float(this->denominator) == a);
}

bool rational::operator==(int a) const {
    return bool(this->numerator / this->denominator == a);
}

bool rational::operator!=(const rational &a) const {
    return bool(this->numerator != a.numerator || denominator != a.denominator);
}

bool rational::operator!=(float a) const {
    return bool(float(this->numerator) / float(this->denominator) != a);
}

bool rational::operator!=(int a) const {
    return bool(this->numerator / this->denominator != a);
}

rational::~rational() {
}

std::ostream &operator<<(std::ostream &os, const rational &r) {
    std::ostringstream output_text;    // Declare an output string stream
    // Insert our output into the output string stream object
    output_text << r.numerator << '/' << r.denominator;
    // Convert the output string stream object to a string and insert it into
    // the output stream
    os << output_text.str();

    return os;
}

std::istream &operator>>(std::istream &is, rational &r) {
    char unused;
    is >> r.numerator;      // Read numerator
    is >> unused;             // Read / and ignore it
    is >> r.denominator;    // Read denominator
    return is;
}









