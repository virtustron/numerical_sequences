#include "NaturalSequenceGeneratedContainer.hpp"

NaturalSequenceGeneratedContainer::NaturalSequenceGeneratedContainer()
{
    set_elements(nullptr, 0);
}

NaturalSequenceGeneratedContainer::NaturalSequenceGeneratedContainer(unsigned int *elements, const int elements_count)
{
    set_elements(elements, elements_count);
}

NaturalSequenceGeneratedContainer::~NaturalSequenceGeneratedContainer()
{
    
}

unsigned int NaturalSequenceGeneratedContainer::get_elements_count()
{
    return m_elements_count;   
}

unsigned int* NaturalSequenceGeneratedContainer::get_elements()
{
    return m_elements;    
}

void NaturalSequenceGeneratedContainer::set_elements(unsigned int *elements, const int elements_count)
{
    // TODO add validation
    m_elements = elements;
    m_elements_count = elements_count;
}