#include <iostream>
#include "TVector/TVector.h"
#include "TMatrix/TMatrix.h"
#include "CStr/CStr.cpp"

using namespace std;

int main() {
    // srand(time(NULL));


    /*
    cout << "TVector<double> Demonstration :" << endl;


    TVector<double> double_vector_1(3);
    double_vector_1[0] = 7.9;
    double_vector_1[1] = 1.1;
    double_vector_1[2] = 6.2;    
    cout << "Initial double_vector_1 : " << double_vector_1 << endl;


    TVector<double> double_vector_2 = double_vector_1;
    cout << "Copied double_vector_2 : " << double_vector_2 << endl;

    double_vector_1.setLength(4);
    double_vector_1[3] = 9.19;
    cout << "After setLength double_vector_1 : " << double_vector_1 << endl;


    TVector<double> double_vector_3(4);
    double_vector_3[0] = 45.99;
    double_vector_3[1] = 11.8;
    double_vector_3[2] = 7.0;
    double_vector_3[3] = 8.9;
    
    double_vector_1 += double_vector_3;
    cout << "After += operation double_vector_1 : " << double_vector_1 << endl;


    cout << endl <<"TVector<string> Demonstration :" << endl;

    TVector<string> string_vec(3);
    string_vec[0] = "TSU";
    string_vec[1] = "IPMKN";
    string_vec[2] = "OOP";
    
    cout << "Initial string_vec: " << string_vec << endl;

    TVector<string> string_vec_2;
    string_vec_2 = string_vec;
    string_vec_2[2] = "C++";
    cout << "Modified string_vec_2: " << string_vec_2 << endl;




    cout << endl << "--------------------------------------------------------------" << endl << endl;

    */


    cout << "TMatrix<int> Demonstration :\n" << endl;

    TMatrix<int> integer_matrix_1(2, 3);
    integer_matrix_1[0][0] = 1;
    integer_matrix_1[0][1] = 2;
    integer_matrix_1[0][2] = 3;
    integer_matrix_1[1][0] = 4;
    integer_matrix_1[1][1] = 5;
    integer_matrix_1[1][2] = 6;
    cout << "Initial integer_matrix_1 :" << endl << integer_matrix_1 << endl;


    TMatrix<int> integer_matrix_2 = integer_matrix_1;
    integer_matrix_2[1][2] = 10;
    cout << "Modified (integer_matrix_1[1][2]=10) integer_matrix_2 :" << endl << integer_matrix_2 << endl;

    // += operator
    TMatrix<int> integer_matrix_3(2, 3);
    integer_matrix_3[0][0] = 30;
    integer_matrix_3[0][1] = 55;
    integer_matrix_3[0][2] = 23;
    integer_matrix_3[1][0] = 123;
    integer_matrix_3[1][1] = 81;
    integer_matrix_3[1][2] = 160;

    cout << "Matrix integer_matrix_3 :" << endl << integer_matrix_3 << endl;

    integer_matrix_1 += integer_matrix_3;
    cout << "After += operation integer_matrix_1 +=  integer_matrix_3 :" << endl << integer_matrix_1 << endl;

    // with CStr
    cout << endl << "TMatrix<CStr> Demonstration :" << endl;

    // random CStr objects
    TMatrix<CStr> cstr_matrix(2, 2);
    
    cout << "Initial random CStr Matrix:" << endl << cstr_matrix << endl;

    // index & modification of CStr elements
    cout << endl << "Modifying CStr Matrix elements :" << endl;
    cstr_matrix[0][0] = "PinkFloyd";
    cstr_matrix[0][1] = "Slipknot";
    cstr_matrix[1][0] = "Metallica";
    cstr_matrix[1][1] = "Scorpions";
    
    cout << "Modified CStr Matrix:" << endl << cstr_matrix << endl;

    // copy
    TMatrix<CStr> cstr_matrix_2 = cstr_matrix;
    cstr_matrix_2[1][1] = "Kino";
    cout << "Modified cstr_matrix2 :" << endl << cstr_matrix_2 << endl;

    return 0;
}

