#include "NaturalSequenceIterator.hpp"

NaturalSequenceIterator& NaturalSequenceIterator::operator++() 
{
    ++m_num; 
    return *this;
}

NaturalSequenceIterator NaturalSequenceIterator::operator++(int) 
{
    NaturalSequenceIterator retval = *this; 
    
    ++(*this); 
    
    return retval;
}

bool NaturalSequenceIterator::operator==(const NaturalSequenceIterator& other) const 
{
    return m_num == other.m_num;
}

bool NaturalSequenceIterator::operator!=(const NaturalSequenceIterator& other) const 
{
    return !(*this == other);
}

NaturalSequenceIterator::reference NaturalSequenceIterator::operator*() const 
{
    return m_num;
}

bool NaturalSequenceIterator::operator>(const NaturalSequenceIterator& other) const
{
    return m_num > other.m_num;
}

bool NaturalSequenceIterator::operator<(const NaturalSequenceIterator& other) const
{
    return m_num < other.m_num;
}