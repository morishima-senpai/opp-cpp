#include "TMatrix.h"



template <class T>
TMatrix<T>::TMatrix(int r, int c) {
    rows = (r > 0) ? r : 1;
    cols = (c > 0) ? c : 1;
    matrix = new TVector<T>[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = TVector<T>(cols);
    }
}

// copy
template <class T>
TMatrix<T>::TMatrix(const TMatrix& other) {
    rows = other.rows;
    cols = other.cols;
    matrix = new TVector<T>[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = other.matrix[i];
    }
}

template <class T>
TMatrix<T>::~TMatrix() {
    delete[] matrix;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix& other) {
    if (this != &other) {
        delete[] matrix;
        rows = other.rows;
        cols = other.cols;
        matrix = new TVector<T>[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = other.matrix[i];
        }
    }
    return *this;
}

/*
     /\_/\  
    ( o.o ) 
     > ^ <
   (      )
    >    <
     -  -
*/

template <class T>
TMatrix<T>& TMatrix<T>::operator+=(const TMatrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::runtime_error("Matrices must have the same dimensions");
    }
    for (int i = 0; i < rows; ++i) {
        matrix[i] += other.matrix[i];
    }
    return *this;
}

template <class T>
TVector<T>& TMatrix<T>::operator[](int index) {
    if (index < 0 || index >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    return matrix[index];
}

template <class T>
std::istream& operator>>(std::istream& is, TMatrix<T>& mat) {
    for (int i = 0; i < mat.rows; ++i) {
        is >> mat.matrix[i];
    }
    return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TMatrix<T>& mat) {
    for (int i = 0; i < mat.rows; ++i) {
        os << mat.matrix[i] << std::endl;
    }
    return os;
}
