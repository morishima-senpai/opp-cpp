// TMatrix.tpp
template<typename T>
TMatrix<T>::TMatrix(int rows, int cols) : rowCount(rows) {
    this->rows = new TVector<T>[rows];
    for (int i = 0; i < rows; ++i)
        this->rows[i].setLength(cols);
}

template<typename T>
TMatrix<T>::TMatrix(const TMatrix& other) : rowCount(other.rowCount) {
    rows = new TVector<T>[rowCount];
    for (int i = 0; i < rowCount; ++i)
        rows[i] = other.rows[i];
}

template<typename T>
TMatrix<T>::~TMatrix() {
    delete[] rows;
}

template<typename T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix& other) {
    if (this != &other) {
        delete[] rows;
        rowCount = other.rowCount;
        rows = new TVector<T>[rowCount];
        for (int i = 0; i < rowCount; ++i)
            rows[i] = other.rows[i];
    }
    return *this;
}

template<typename T>
TMatrix<T>& TMatrix<T>::operator+=(const TMatrix& other) {
    for (int i = 0; i < rowCount; ++i)
        rows[i] += other.rows[i];
    return *this;
}

template<typename T>
TVector<T>& TMatrix<T>::operator[](int index) {
    return rows[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TMatrix<T>& matrix) {
    for (int i = 0; i < matrix.rowCount; ++i)
        out << matrix.rows[i] << "\n";
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, TMatrix<T>& matrix) {
    for (int i = 0; i < matrix.rowCount; ++i)
        in >> matrix.rows[i];
    return in;
}

