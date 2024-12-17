#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>

template<typename T>
class TVector {
private:
    T* data;
    int length;

public:
    explicit TVector(int dimension = 1);
    TVector(const TVector& other);
    ~TVector();

    void setLength(int newLength);
    TVector& operator=(const TVector& other);
    TVector& operator+=(const TVector& other);
    T& operator[](int index);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const TVector<U>& vector);

    template<typename U>
    friend std::istream& operator>>(std::istream& in, TVector<U>& vector);
};

template<typename T>
TVector<T>::TVector(int dimension) : length(dimension) {
    data = new T[dimension];
    std::cout << "test2\n";
}

template<typename T>
TVector<T>::TVector(const TVector& other) : length(other.length) {
    std::cout << "copy\n";
    data = new T[length];
    for (int i = 0; i < length; ++i){
        data[i] = other.data[i];
    }
}

template<typename T>
TVector<T>::~TVector() {
    delete[] data;
}

template<typename T>
void TVector<T>::setLength(int newLength) {
    T* newData = new T[newLength];
    for (int i = 0; i < (newLength < length ? newLength : length); ++i){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    length = newLength;
}

template<typename T>
TVector<T>& TVector<T>::operator=(const TVector& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new T[length];
        for (int i = 0; i < length; ++i){
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
TVector<T>& TVector<T>::operator+=(const TVector& other) {
    for (int i = 0; i < length; ++i){
        data[i] += other.data[i];
    }
    return *this;
}

template<typename T>
T& TVector<T>::operator[](int index) {
    return data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TVector<T>& vector) {
    for (int i = 0; i < vector.length; ++i){
        out << vector.data[i] << " ";
    }
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, TVector<T>& vector) {
    for (int i = 0; i < vector.length; ++i){
        in >> vector.data[i];
    }
    return in;
}

#endif // TVECTOR_H
