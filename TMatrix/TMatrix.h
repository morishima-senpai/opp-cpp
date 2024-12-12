#ifndef TMATRIX_H
#define TMATRIX_H

#include "../TVector/TVector.h"

template<typename T>
class TMatrix {
private:
    TVector<T>* rows;
    int rowCount;

public:
    TMatrix(int rows = 1, int cols = 1);
    TMatrix(const TMatrix& other);
    ~TMatrix();

    TMatrix& operator=(const TMatrix& other);
    TMatrix& operator+=(const TMatrix& other);
    TVector<T>& operator[](int index);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const TMatrix<U>& matrix);

    template<typename U>
    friend std::istream& operator>>(std::istream& in, TMatrix<U>& matrix);
};

#include "TMatrix.tpp"

#endif
