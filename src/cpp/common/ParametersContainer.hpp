#pragma once

const int INIT_SUCCEDED                 =  0;
const int INIT_INVALID_BOUND            = -1;


class ParametersContainer
{
public:
    ParametersContainer(unsigned int lower_bound, unsigned int upper_bound);
    
    unsigned int get_lower_bound();
    unsigned int get_upper_bound();
private:
    unsigned int m_lower_bound;
    unsigned int m_upper_bound;
};
