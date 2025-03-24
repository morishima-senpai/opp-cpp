#ifndef SORT_H
#define SORT_H

#include <algorithm>

template <typename T>
class Sort {
private:

    static void heap_sort_helper(T** arr, size_t n, size_t i, long long& comparisons) {
        size_t largest = i;
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;

        if (l < n) {
            comparisons++;
            if (*(arr[l]) > *(arr[largest])) largest = l;
            
        }

        if (r < n) {
            comparisons++;
            if (*(arr[r]) > *(arr[largest])) largest = r;   
        }

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heap_sort_helper(arr, n, largest, comparisons);
        }
    }

public:

    static long long simple_sort(T** arr, size_t n) {
        long long comparisons = 0;
        
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {

                comparisons++;

                if (*(arr[j + 1]) < *(arr[j])) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        return comparisons;
    }



    static long long heap_sort(T** arr, size_t n) {
        long long comparisons = 0;

        for (int i = static_cast<int>(n) / 2 - 1; i >= 0; i--) {
            heap_sort_helper(arr, n, static_cast<size_t>(i), comparisons);
        }

        for (size_t i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heap_sort_helper(arr, i, 0, comparisons);
        }

        return comparisons;
    }

    static long long quick_sort(T** arr, int low, int high) {
        long long comparisons = 0;

        if (low < high) {

            T pivot = *(arr[high]);
            int i = low - 1;

            for (int j = low; j <= high - 1; ++j) {
                
                comparisons++;

                if (!(pivot < *(arr[j]))) {
                    ++i;
                    std::swap(arr[i], arr[j]);
                }
            }

            std::swap(arr[i + 1], arr[high]);
            int pi = i + 1;
            
            comparisons += quick_sort(arr, low, pi - 1);
            comparisons += quick_sort(arr, pi + 1, high);
        }
        return comparisons;
    }


    static bool is_sorted(T** arr, size_t n) {
        for (size_t i = 0; i < n - 1; ++i)
            if (*(arr[i + 1]) < *(arr[i]))
                return false;
        return true;
    }


};

#endif