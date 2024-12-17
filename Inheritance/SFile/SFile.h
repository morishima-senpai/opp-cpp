#ifndef SFILE_H
#define SFILE_H

#include "../SBase/SBase.h"
#include <fstream>
#include <string>

class SFile : public SBase {
private:
    std::ifstream file;

public:
    explicit SFile(const std::string& filename);
    ~SFile() override;
    int Get() override;
};

#endif // SFILE_H
