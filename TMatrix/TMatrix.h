#ifndef TMATRIX_H
#define TMATRIX_H

#include <stdexcept>
#include "../TVector/TVector.h"
#include <iostream>

template <class T>
class TMatrix {
private:
    TVector<T>* matrix;
    int rows;
    int cols;

public:
    TMatrix(int r = 1, int c = 1);
    TMatrix(const TMatrix& other);

    ~TMatrix();

    TMatrix& operator=(const TMatrix& other);

    TMatrix& operator+=(const TMatrix& other);

    TVector<T>& operator[](int index);

    template <class U>
    friend std::istream& operator>>(std::istream& is, TMatrix<U>& mat);

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const TMatrix<U>& mat);
};

#include "TMatrix.tpp"

#endif
