#include "ParametersContainer.hpp"

   
ParametersContainer::ParametersContainer(unsigned int lower_bound, unsigned int upper_bound)
{
    m_lower_bound = lower_bound;
    m_upper_bound = upper_bound;
}
    
   
unsigned int ParametersContainer::ParametersContainer::get_lower_bound()
{   
    return m_lower_bound;
}
    
unsigned int ParametersContainer::get_upper_bound()
{   
    return m_upper_bound;
}
    