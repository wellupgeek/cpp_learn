
#include <iostream>

class Fraction {
public:
    explicit Fraction(int num, int deno = 1) : numerator(num), denominator(deno){}
    Fraction operator + (const Fraction& rhs) {
        int temp = denominator * rhs.denominator;
        return Fraction(numerator*rhs.denominator + rhs.numerator*denominator, temp);
    }
    operator double() const {
        return (double) (numerator * 1.0 / denominator);
    }
private:
    int numerator;
    int denominator;
};

int main()
{
    Fraction f(3, 5);
    double d = 5.9 + f;
    double c = f + 4;
    std::cout << c << std::endl;
}