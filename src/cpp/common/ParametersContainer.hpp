#pragma once

class ParametersContainer
{
public:
    ParametersContainer();
    ParametersContainer(unsigned int upper_bound);
    ~ParametersContainer();

    void set_upper_bound(unsigned int upper_bound);
    unsigned int get_upper_bound();
private:
    unsigned int m_upper_bound;
};
