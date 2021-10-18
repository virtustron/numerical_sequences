// class Iterator originally from
//   https://en.cppreference.com/w/cpp/iterator/iterator

#pragma once

#include <iterator> // For std::input_iterator_tag
#include <limits.h>

class NaturalSequenceIterator: public std::iterator<
                        std::input_iterator_tag,           // iterator_category
                        unsigned int,                      // value_type
                        unsigned int,                      // difference_type
                        const unsigned int*,               // pointer
                        unsigned int                       // reference
                        >
{
       
public:
        explicit NaturalSequenceIterator(unsigned int num = 0) : m_num(num) {}
        
        NaturalSequenceIterator& operator++();
        NaturalSequenceIterator operator++(int);

        bool operator==(const NaturalSequenceIterator& other) const;
        bool operator!=(const NaturalSequenceIterator& other) const;

        bool operator>(const NaturalSequenceIterator& other) const;
        bool operator<(const NaturalSequenceIterator& other) const;
        
        reference operator*() const;

private:
        unsigned int m_num = 0;
};