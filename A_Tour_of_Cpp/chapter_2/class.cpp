#include <iostream>
using std::cin;

class Vector{
public:
    Vector(int s) : elem(new double[s]), sz(s) {}
    double& operator[](int i) { return elem[i]; }
    int size() {return sz;}

private:
    double *elem;
    int sz;
};

double read_and_sum(int s) {
    Vector vec(s);
    double sum = 0;
    for (int i = 0; i < vec.size(); i++){
        cin >> vec[i];
        sum += vec[i];
    }
    return sum;
}