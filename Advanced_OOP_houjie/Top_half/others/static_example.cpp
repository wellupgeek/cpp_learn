#include <iostream>

class Bank{
public:
    static double rate;
    static void setRate(const double&);
    static double getRate();
};

double Bank::rate = 0.1;

inline
void Bank::setRate(const double& x) {
    rate = x;
}

inline
double Bank::getRate(){
    return rate;
}

int main() {
    Bank::setRate(1.0);
    std::cout << Bank::getRate() << '\n';

    Bank a;
    a.setRate(2.0);

    Bank::rate = 3.0;
    std::cout << Bank::rate << '\n';
}