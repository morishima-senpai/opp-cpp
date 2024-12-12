#include "TVector.h"

/*
   .--.
  |o_o |
  |:_/ |
 //   \ \
(|     | )
/'\_   _/`\
\___)=(___/

*/

template <class T>
TVector<T>::TVector(int dim) {
    length = (dim > 0) ? dim : 1;
    arr = new T[length];

    for (int i = 0; i < length; ++i) {
        arr[i] = T();
    }
}

template <class T>
TVector<T>::TVector(const TVector& other) {
    length = other.length;
    arr = new T[length];

    for (int i = 0; i < length; ++i) {
        arr[i] = other.arr[i];
    }
}

template <class T>
TVector<T>::~TVector() {
    delete[] arr;
}

template <class T>
void TVector<T>::setLength(int new_length) {
    if (new_length <= 0) return;

    T* new_arr = new T[new_length];

    int copy_length = (new_length < length) ? new_length : length;
    for (int i = 0; i < copy_length; ++i) {
        new_arr[i] = arr[i];
    }

    for (int i = copy_length; i < new_length; ++i) {
        new_arr[i] = T();
    }

    delete[] arr;
    arr = new_arr;
    length = new_length;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector& other) {
    if (this != &other) {
        delete[] arr;
        length = other.length;
        arr = new T[length];

        for (int i = 0; i < length; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <class T>
TVector<T>& TVector<T>::operator+=(const TVector& other) {
    if (length != other.length) {
        throw std::runtime_error("Vectors must have the same dimension");
    }

    for (int i = 0; i < length; ++i) {
        arr[i] += other.arr[i];
    }
    return *this;
}

template <class T>
T& TVector<T>::operator[](int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TVector<T>& vec) {
    os << "[ ";
    for (int i = 0; i < vec.length; ++i) {
        os << vec.arr[i] << " ";
    }
    os << "]";
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, TVector<T>& vec) {
    for (int i = 0; i < vec.length; ++i) {
        is >> vec.arr[i];
    }
    return is;
}
