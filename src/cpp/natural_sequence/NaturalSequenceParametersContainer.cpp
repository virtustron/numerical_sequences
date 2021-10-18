#include "NaturalSequenceParametersContainer.hpp"

    NaturalSequenceParametersContainer::NaturalSequenceParametersContainer()
    {
        set_upper_bound(0);
    }
    
    NaturalSequenceParametersContainer::NaturalSequenceParametersContainer(unsigned int upper_bound)
    {
        set_upper_bound(upper_bound);
    }
    
    NaturalSequenceParametersContainer::~NaturalSequenceParametersContainer()
    {

    }
    
    void NaturalSequenceParametersContainer::set_upper_bound(unsigned int upper_bound)
    {
        m_upper_bound = upper_bound;
    }
    
    unsigned int NaturalSequenceParametersContainer::get_upper_bound()
    {   
        return m_upper_bound;
    }
    