#include "NaturalSequence.hpp"

NaturalSequence::NaturalSequence(const unsigned int lower_bound, const unsigned int upper_bound)
{
    if (!IsNaturalBoundValid(lower_bound))
    {
        throw std::invalid_argument("Lower bound has not valid numeric value.");
    }

    if (!IsNaturalBoundValid(lower_bound))
    {
        throw std::invalid_argument("Lower bound has not valid numeric value.");
    }

    if (upper_bound < lower_bound)
    {
        throw std::invalid_argument("Upper bound value is less than lower bound value.");
    }

    m_lower_bound = lower_bound;
    m_upper_bound = upper_bound;
}


NaturalSequenceIterator NaturalSequence::begin() 
{
    return NaturalSequenceIterator(m_lower_bound);
}

NaturalSequenceIterator NaturalSequence::end() 
{
    // !square! of the number must be smaller - so "sqrt" is called
    return NaturalSequenceIterator(round(sqrt(m_upper_bound)));
}

bool NaturalSequence::IsNaturalBoundValid(unsigned int bound)
{
    return (bound >= 0);
}

