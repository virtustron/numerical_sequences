#pragma once

class NaturalSequenceParametersContainer
{
public:
    NaturalSequenceParametersContainer();
    NaturalSequenceParametersContainer(unsigned int upper_bound);
    ~NaturalSequenceParametersContainer();

    void set_upper_bound(unsigned int upper_bound);
    unsigned int get_upper_bound();
private:
    unsigned int m_upper_bound;
};
