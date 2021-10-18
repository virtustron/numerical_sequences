#include "NaturalSequenceGenerating.hpp"

#include <stdexcept>
#include <vector>
#include "NaturalSequence.hpp"
#include "NaturalSequenceParametersContainer.hpp"
#include "NaturalSequenceGeneratedContainer.hpp"


int InitializeNaturalSequenceParameters(void** parameters_container_to_initialize)
{
    // TODO try smart poriners
    NaturalSequenceParametersContainer* parameters_container;
    
    try
    {
        parameters_container = new NaturalSequenceParametersContainer(100);
    }
    catch (const std::invalid_argument& e)
	{
        if (parameters_container != NULL)
            delete parameters_container;
        
        return INIT_INVALID_UPPER_BOUND;
	}
    
    *parameters_container_to_initialize = (void*)parameters_container;
    
    return INIT_SUCCEDED;
}


int GenerateNaturalSequence(void* parameters_container, void **generated_sequence_container)
{
    if (parameters_container == NULL)
    {
        return GENERATING_PARAMETERS_ARE_NOT_VALID;
    }
    
    try
    {
        NaturalSequenceParametersContainer* sequence_parameters_container = (NaturalSequenceParametersContainer*)parameters_container;

        auto natural_sequence = NaturalSequence(0, sequence_parameters_container->get_upper_bound());
        std::vector<unsigned int> *sequence = new std::vector<unsigned int>();
    
        for (auto it = natural_sequence.begin(), end = natural_sequence.end(); it < end; ++it)
        {
            const auto i = *it;
            sequence->push_back(i);
        }

        NaturalSequenceGeneratedContainer* sequence_container;

        
        unsigned int *elements = sequence->data();
        const int elements_count = sequence->size();
        sequence_container = new NaturalSequenceGeneratedContainer(elements, elements_count);

        *generated_sequence_container = (void*)sequence_container; 
    }
    catch(const std::exception& e)
    {
        return GENERATING_FAILED;
    }
    
    return GENERATING_SUCCEDED;
}