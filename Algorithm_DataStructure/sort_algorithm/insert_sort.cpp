#include <iostream>
#include "SortTestHelper.h"
using namespace std;

template <typename T>
bool myless(T a, T b, bool(*cmp)(T, T)=0) {
    if (cmp)
        return cmp(a, b);
    return a < b;
}

template <typename T>
void insertSort(T arr[], int n, bool(*cmp)(T, T)=0) {
    for (int i=1; i<n; ++i) {
        for (int j=i; j>0 && myless(arr[j], arr[j-1]); --j) {
            swap(arr[j], arr[j-1]);
        }
    }
}

template <typename T>
void insertSort2(T arr[], int n, bool(*cmp)(T, T)=0) {
    for (int i=1; i<n; ++i) {
        T t = arr[i];
        int j;  // j保存元素t应该插入的位置
        for (j=i; j>0 && myless(t, arr[j-1]); --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = t;
    }
}

template <typename T>
void selectionSort(T arr[], int n, bool(*cmp)(T, T)=0) {
    for (int i=0; i<n; ++i) {
        int minIndex = i;
        for (int j=i+1; j<n; ++j) {
            if (myless(arr[j], arr[minIndex]))
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void shellSort(T arr[], int n, bool(*cmp)(T, T)=0) {
    for (int i=n/2; i>=1; i/=2) {   // 跨度
        for (int j=i; j<n; j++) {   // 每组最末元素下标
            for (int k=j; k>=0; k-=i) {
                if(arr[k-i] > arr[k])
                    swap(arr[k-i], arr[k]);
            }
        }
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    // int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyArray(arr, n);
    int *arr3 = SortTestHelper::copyArray(arr, n);
    int *arr4 = SortTestHelper::copyArray(arr, n);
    SortTestHelper::testSort(arr, n, insertSort);
    SortTestHelper::testSort(arr3, n, insertSort2);
    SortTestHelper::testSort(arr2, n, selectionSort);
    SortTestHelper::testSort(arr4, n, shellSort);
    // SortTestHelper::printArray(arr, n);
    delete[] arr4;
    delete[] arr3;
    delete[] arr2;
    delete[] arr;
}