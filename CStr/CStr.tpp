#ifndef CSTR_TPP
#define CSTR_TPP

#include "CStr.h"

inline char* CStr::generate(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    char* result = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        result[i] = charset[rand() % 26];
    }
    result[length] = '\0';
    return result;
}

#endif
