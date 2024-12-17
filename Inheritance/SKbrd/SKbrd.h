#ifndef SKBRD_H
#define SKBRD_H

#include "../SBase/SBase.h"

class SKbrd : public SBase {
public:
    SKbrd() = default;
    ~SKbrd() override = default;
    int Get() override;
};

#endif // SKBRD_H
