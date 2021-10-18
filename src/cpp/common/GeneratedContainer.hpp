#pragma once

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