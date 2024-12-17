#include "SFile.h"

SFile::SFile(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
}

SFile::~SFile() {
    if (file.is_open()) {
        file.close();
    }
}

int SFile::Get() {
    int num;
    if (file >> num) {
        return num;
    }
    return -1; // end of file is reached
}
