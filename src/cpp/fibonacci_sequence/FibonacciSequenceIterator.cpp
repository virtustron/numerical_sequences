#include <limits.h>
#include "FibonacciSequenceIterator.hpp"

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() 
{
    m_num = CalculateNextFibonacciNumber(m_num, m_last, m_before_last);

    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) 
{
    FibonacciSequenceIterator retval = *this; 
    ++(*this); 
    
    return retval;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& other) const 
{
    return m_num == other.m_num;
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& other) const 
{
    return !(*this == other);
}

FibonacciSequenceIterator::reference FibonacciSequenceIterator::operator*() const 
{
    return m_num;
}

bool FibonacciSequenceIterator::operator>(const FibonacciSequenceIterator& other) const
{
    return m_num > other.m_num;
}

bool FibonacciSequenceIterator::operator<(const FibonacciSequenceIterator& other) const
{
    return m_num < other.m_num;
}

unsigned int FibonacciSequenceIterator::CalculatePreviousFibonacciNumber(const unsigned int current_number)
{
    double approximate_previous_number = current_number / ((1 + sqrt(5)) / 2.0);
    return round(approximate_previous_number);
}

unsigned int FibonacciSequenceIterator::CalculateNextFibonacciNumber(
    const unsigned int current_fibonacci_number, 
    unsigned int& last_fibonacci_number,
    unsigned int& before_last_fibonacci_number)
{
    unsigned int next_fibonacci_number = current_fibonacci_number;
    
    // 0 1 1 2 3 5 8 13 21 34
    switch (current_fibonacci_number)
    {
    case 0:
        ++next_fibonacci_number;
        break;

    case 1:
        if (last_fibonacci_number == 0)
        {
            last_fibonacci_number = 1;
        }
        else
        {
            // m_last == 1
            next_fibonacci_number = 2;
            before_last_fibonacci_number = last_fibonacci_number;
            last_fibonacci_number = next_fibonacci_number;
        }
        
        break;
    
    default:
        next_fibonacci_number = last_fibonacci_number + before_last_fibonacci_number;
        before_last_fibonacci_number = last_fibonacci_number;
        last_fibonacci_number = next_fibonacci_number;
        
        break;
    }

    return next_fibonacci_number;

}

unsigned int FibonacciSequenceIterator::FindNearestBiggerFibonacciNumber(
    const unsigned int number, 
    unsigned int& last_fibonacci_number,
    unsigned int& before_last_fibonacci_number)
{
    unsigned int bigger_fibonacci_number = 0; 
    
    while (bigger_fibonacci_number < number)
    {
        bigger_fibonacci_number = CalculateNextFibonacciNumber(bigger_fibonacci_number, last_fibonacci_number, before_last_fibonacci_number);
    }

    return bigger_fibonacci_number;
}