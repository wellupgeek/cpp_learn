#include <iostream>
#include <ctime>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
int partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int j = l;  // arr[l] | arr[l+1]~arr[j] < v| arr[j+1]~arr[i-1] > v| arr[i]
    for (int i=l+1; i<=r; i++)
        if (arr[i] < v)
            swap(arr[i], arr[++j]);
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
int partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int i = l+1, j = r;   // arr[l+1, ..., i) <= v | arr(j, ..., r] >= v
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l+1 && arr[j] > v) j--;
        if (i > j)  break;
        swap(arr[i++], arr[j--]);
    }
    swap(arr[l], arr[j]);   // i表示第一个>=v的位置，j表示最后一个<=v的位置。
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r)
        return;
    int pos = partition2(arr, l, r);    // arr[pos] <= arr[l]
    __quickSort(arr, l, pos);         // arr[pos-1] < arr[l]
    __quickSort(arr, pos+1, r);         // arr[l] <= arr[pos+1] 
}

template <typename T>
void quickSort(T arr[], int n, bool(*cmp)(T, T)) {
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

template <typename T>
void merge(T arr[], int l, int mid, int r) {
    T* aux = new T[r-l+1];
    int i=l, j=mid+1, k=0;
    while (i<=mid && j<=r) {
        if (arr[i] < arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    while (i<=mid)
        aux[k++] = arr[i++];
    while (j<=r)
        aux[k++] = arr[j++];
    for (int i=0; i<k; i++)
        arr[l+i] = aux[i];
    delete[] aux;
}

template <typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r)
        return ;
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
void insertSort(T arr[], int n, bool(*cmp)(T, T)) {
    for (int i=1; i<n; i++) {
        T v = arr[i];
        int j;
        for (j=i; j>0 && v < arr[j-1]; j--)
            arr[j] = arr[j-1];
        arr[j] = v;
    }
}

int main()
{
    int n = 100000;
    // int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyArray(arr, n);
    int* arr3 = SortTestHelper::copyArray(arr, n);
    SortTestHelper::testSort(arr, n, quickSort);
    SortTestHelper::testSort(arr2, n, mergeSort);
    SortTestHelper::testSort(arr3, n, insertSort);
    // SortTestHelper::printArray(arr3, n);
    delete[] arr3;
    delete[] arr2;
    delete[] arr;
}