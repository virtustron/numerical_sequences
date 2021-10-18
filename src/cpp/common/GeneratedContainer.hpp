#pragma once

const int GENERATING_SUCCEDED                 =  0;
const int GENERATING_FAILED                   = -1;
const int GENERATING_PARAMETERS_ARE_NOT_VALID  = -2;


class GeneratedContainer
{
public:
    GeneratedContainer();
    GeneratedContainer(unsigned int *elements, const int elements_count);
    ~GeneratedContainer();

    int get_elements_count();
    unsigned int* get_elements();
    void set_elements(unsigned int *elements, const int elements_count);

private:
    int m_elements_count;
    unsigned int *m_elements;

};