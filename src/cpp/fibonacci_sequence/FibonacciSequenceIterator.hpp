#pragma once

#include <iterator> // For std::input_iterator_tag
#include <limits.h>
#include <math.h>

class FibonacciSequenceIterator: public std::iterator<
                        std::input_iterator_tag,           // iterator_category
                        unsigned int,                      // value_type
                        unsigned int,                      // difference_type
                        const unsigned int*,               // pointer
                        unsigned int                       // reference
                        >
{
       
public:
        explicit FibonacciSequenceIterator(unsigned int num = 0)
        {
                if (num > 0)
                {
                        m_num = FindNearestBiggerFibonacciNumber(num, m_last, m_before_last);
                }
        }
        
        FibonacciSequenceIterator& operator++();
        FibonacciSequenceIterator operator++(int);

        bool operator==(const FibonacciSequenceIterator& other) const;
        bool operator!=(const FibonacciSequenceIterator& other) const;

        bool operator>(const FibonacciSequenceIterator& other) const;
        bool operator<(const FibonacciSequenceIterator& other) const;
        
        reference operator*() const;

private:
        unsigned int m_num = 0;
        unsigned int m_last = 0;
        unsigned int m_before_last = 0;

        unsigned int CalculatePreviousFibonacciNumber(const unsigned int current_number);
        unsigned int CalculateNextFibonacciNumber(
                const unsigned int current_fibonacci_number, 
                unsigned int& last_fibonacci_number,
                unsigned int& before_last_fibonacci_number);
        unsigned int FindNearestBiggerFibonacciNumber(
                const unsigned int number, 
                unsigned int& last_fibonacci_number,
                unsigned int& before_last_fibonacci_number);
};



        