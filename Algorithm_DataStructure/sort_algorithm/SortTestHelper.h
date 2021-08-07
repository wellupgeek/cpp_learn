#ifndef _SORT_TEST_HELPER
#define _SORT_TEST_HELPER

#include <cassert>
#include <ctime>

namespace SortTestHelper {
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        assert( rangeL <= rangeR );
        int* arr = new int[n];
        srand(time(NULL));
        for (int i=0; i<n; ++i)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    int* generateNearlyOrderedArray(int n, int swaptimes) {
        int* arr = new int[n];
        for (int i=0; i<n; ++i)
            arr[i] = i+1;
        srand(time(NULL));
        for (int i=0; i<swaptimes; ++i) {
            int posx = rand() % n;
            int posy = rand() % n;
            std::swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n) {
        for (int i=0; i<n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return ;
    }

    template <typename T>
    bool isSorted(T arr[], int n) {
        for (int i=0; i<n-1; ++i)
            if (arr[i] > arr[i+1])
                return false;
        return true;
    }

    template <typename T>
    void testSort(T arr[], int n, void(*sort)(T[], int, bool(*)(T, T)), bool(*compare)(T, T)=0) {
        clock_t startTime = clock();
        sort(arr, n, compare);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        std::cout << "use time : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << "\n";
        return ;
    }

    template <typename T>
    T* copyArray(T arr[], int n) {
        T* a = new T[n];
        std::copy(arr, arr+n, a);
        return a;
    }
}

#endif