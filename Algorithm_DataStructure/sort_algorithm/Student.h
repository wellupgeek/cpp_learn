#ifndef SELECTIONSORT_STUDENT
#define SELECTIONSORT_STUDENT

#include <string>
#include <iostream>

struct Student {
    std::string name;
    int score;

    bool operator< (const Student& other) {
        return score < other.score;
    }

    friend std::ostream& operator<< (std::ostream& os, const Student& stu) {
        os << "Student: " << stu.name << " score: " << stu.score << std::endl;
        return os;   
    }
};


#endif