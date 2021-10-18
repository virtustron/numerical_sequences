#pragma once

class NaturalSequenceGeneratedContainer
{
public:
    NaturalSequenceGeneratedContainer();
    NaturalSequenceGeneratedContainer(unsigned int *elements, const int elements_count);
    ~NaturalSequenceGeneratedContainer();

    unsigned int get_elements_count();
    unsigned int* get_elements();
    void set_elements(unsigned int *elements, const int elements_count);

private:
    unsigned int m_elements_count;
    unsigned int *m_elements;

};