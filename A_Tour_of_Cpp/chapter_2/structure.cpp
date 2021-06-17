#include <iostream>
using std::cin;

struct Vector {
    double *element;
    int size;
};

void Vector_init(Vector &vec, int s) {
    vec.element = new double[s];
    vec.size = s;
}

double read_and_sum(Vector &vec, int s) {
    Vector_init(vec, s);
    double sum = 0;
    for (int i = 0; i != s; i++){
        cin >> vec.element[i];
        sum += vec.element[i];
    }
    return sum;
}