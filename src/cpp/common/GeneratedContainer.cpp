#include "GeneratedContainer.hpp"

GeneratedContainer::GeneratedContainer()
{
    set_elements(nullptr, 0);
}

GeneratedContainer::GeneratedContainer(unsigned int *elements, const int elements_count)
{
    set_elements(elements, elements_count);
}

GeneratedContainer::~GeneratedContainer()
{
    
}

int GeneratedContainer::get_elements_count()
{
    return m_elements_count;   
}

unsigned int* GeneratedContainer::get_elements()
{
    return m_elements;    
}

void GeneratedContainer::set_elements(unsigned int *elements, const int elements_count)
{
    // TODO add validation
    m_elements = elements;
    m_elements_count = elements_count;
}