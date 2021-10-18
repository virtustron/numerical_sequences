#pragma once

#include <limits.h>
#include "FibonacciSequenceIterator.hpp"

class FibonacciSequence
{
public:
    FibonacciSequence(const unsigned int lower_bound = 0, const unsigned int upper_bound = UINT_MAX);
    
    FibonacciSequenceIterator begin();
    FibonacciSequenceIterator end();

private:
    unsigned int m_lower_bound;
    unsigned int m_upper_bound;

    bool IsBoundValid(unsigned int bound);
};