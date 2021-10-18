#include "FibonacciSequence.hpp"

FibonacciSequence::FibonacciSequence(const unsigned int lower_bound, const unsigned int upper_bound)
{
    if (!IsBoundValid(lower_bound))
    {
        throw std::invalid_argument("Lower bound has not valid numeric value.");
    }

    if (!IsBoundValid(lower_bound))
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

FibonacciSequenceIterator FibonacciSequence::begin() 
{
    return FibonacciSequenceIterator(m_lower_bound);
}

FibonacciSequenceIterator FibonacciSequence::end() 
{
    return FibonacciSequenceIterator(m_upper_bound);
}

bool FibonacciSequence::IsBoundValid(unsigned int bound)
{
    return (bound >= 0);
}

