#ifndef TVECTOR_H
#define TVECTOR_H

#include <stdexcept>
#include <iostream>

template <class T>
class TVector {
private:
    T* arr;
    int length;

public:
    TVector(int dim = 1);

    TVector(const TVector& other);

    ~TVector();

    void setLength(int new_length);

    TVector& operator=(const TVector& other);

    TVector& operator+=(const TVector& other);

    T& operator[](int index);

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const TVector<U>& vec);

    template <class U>
    friend std::istream& operator>>(std::istream& is, TVector<U>& vec);
};

#include "TVector.tpp"

#endif 
