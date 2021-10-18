#pragma once

#include <limits.h>
#include <math.h>
#include "NaturalSequenceIterator.hpp"

class NaturalSequence
{
public:
    NaturalSequence(const unsigned int lower_bound = 0, const unsigned int upper_bound = UINT_MAX);
    
    NaturalSequenceIterator begin();
    NaturalSequenceIterator end();

private:
    unsigned int m_lower_bound;
    unsigned int m_upper_bound;

    bool IsNaturalBoundValid(unsigned int bound);
};