#include "NaturalSequenceParametersContainer.hpp"

    ParametersContainer::ParametersContainer()
    {
        set_upper_bound(0);
    }
    
    ParametersContainer::ParametersContainer(unsigned int upper_bound)
    {
        set_upper_bound(upper_bound);
    }
    
    ParametersContainer::~ParametersContainer()
    {

    }
    
    void ParametersContainer::set_upper_bound(unsigned int upper_bound)
    {
        m_upper_bound = upper_bound;
    }
    
    unsigned int ParametersContainer::get_upper_bound()
    {   
        return m_upper_bound;
    }
    