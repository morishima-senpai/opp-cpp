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

#include "TVector.tpp"

#endif // TVECTOR_H
