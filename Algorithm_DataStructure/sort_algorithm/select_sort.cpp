#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
bool myless(T a, T b, bool (*cmp)(T, T) = 0) {
    if (cmp != 0)
        return cmp(a, b);
    return a < b;
}

template <typename T>
void selectionSort(T arr[], int n, bool (*cmp)(T, T) = 0){
    for (int i=0; i<n; ++i) {
        // 找最小元素下标
        int minIndex = i;
        for (int j=i+1; j<n; ++j)
            if (myless(arr[j], arr[minIndex], cmp))
                minIndex = j;
        
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    // selectionSort(arr, n);
    SortTestHelper::testSort(arr, n, selectionSort);
    // SortTestHelper::printArray(arr, n);
    delete[] arr;
    // double b[] = {8.0, 5.1, 4.2, 3.2};
    // selectionSort(b, sizeof(b)/sizeof(double));
    // Student c[] = {{"nana", 90}, {"haha", 87}, {"jjj", 68}};
    // selectionSort(c, sizeof(c)/sizeof(Student));

}