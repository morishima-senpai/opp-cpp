#ifndef CSTR_H
#define CSTR_H

#include <iostream>

class CStr {
private:
    char* string;
    char* generate(int length);

public:
    CStr();
    CStr(const char* str);
    CStr(int length);
    CStr(const CStr& obj);
    ~CStr();

    CStr& operator=(CStr& obj);
    CStr& operator=(const char* str);
    CStr& operator=(const CStr& obj);


    CStr operator+(CStr& obj);
    CStr& operator+=(CStr& obj);

    bool operator>(CStr& obj);

    char& operator[](int index);

    int get_length();

    friend std::ostream& operator<<(std::ostream& stream, CStr& obj);
    friend std::istream& operator>>(std::istream& stream, CStr& obj);
};

#endif