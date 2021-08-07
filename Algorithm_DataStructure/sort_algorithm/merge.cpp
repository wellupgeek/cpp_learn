#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
void merge(T arr[], int l, int mid, int r) {
    T* aux = new T[r-l+1];

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    while (i <= mid)
        aux[k++] = arr[i++];
    while (j <= r)
        aux[k++] = arr[j++];
    for (int i=l; i<=r; i++) {
        arr[i] = aux[i-l];
    }
    delete[] aux;
}

template <typename T>
void insertSort3(T arr[], int l, int r);

template <typename T>
void __mergeSort(T arr[], int l, int r) {
    // if (l >= r)
    //     return ;
    if (r - l <= 15) {
        insertSort3(arr, l, r);
        return ;
    }
    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr[mid+1])
        merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n, bool(*cmp)(T, T)) {
    __mergeSort(arr, 0, n-1);
}

template <typename T>
void mergeSortBU(T arr[], int n, bool(*cmp)(T, T)) { // 迭代法
    for (int sz=1; sz<=n; sz+=sz)
        for (int i=0; i+sz<n; i+=2*sz) {
            if (2*sz <= 32)
                insertSort3(arr, i, min(i+2*sz-1, n-1));
            else if (arr[i+sz-1] > arr[i+sz])
                merge(arr, i, i+sz-1, min(i+2*sz-1, n-1));
        }
}

template <typename T>
void insertSort2(T arr[], int n, bool(*cmp)(T, T)=0) {
    for (int i=1; i<n; ++i) {
        T t = arr[i];
        int j;  // j保存元素t应该插入的位置
        for (j=i; j>0 && t < arr[j-1]; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = t;
    }
}

template <typename T>
void insertSort3(T arr[], int l, int r) {
    for (int i=l+1; i<=r; i++) {
        T e = arr[i];
        int j;
        for (j=i; j>l && e < arr[j-1]; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

int main()
{
    int n = 10000000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    // int swaptimes = 10;
    // int* arr = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    int* arr2 = SortTestHelper::copyArray(arr, n);
    // int* arr3 = SortTestHelper::copyArray(arr, n);
    SortTestHelper::testSort(arr2, n, mergeSortBU);
    // SortTestHelper::testSort(arr3, n, insertSort2);

    // delete[] arr3;
    delete[] arr2;
    delete[] arr;
}