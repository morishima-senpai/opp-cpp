#ifndef SQUEUE_H
#define SQUEUE_H

#include "../SBase/SBase.h"
#include <vector>
#include <cstddef>

class SQueue : public SBase {
private:
    std::vector<int> numbers;
    size_t current_index;

public:
    explicit SQueue(size_t length);
    ~SQueue() override = default;
    int Get() override;
};

#endif // SQUEUE_H
