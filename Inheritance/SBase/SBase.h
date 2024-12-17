#ifndef SBASE_H
#define SBASE_H

class SBase {
public:
    virtual ~SBase() = default;
    virtual int Get() = 0; // to get next number
};

#endif // SBASE_H
