#include "FibonacciSequenceGenerating.hpp"

#include <stdexcept>
#include <vector>
#include "FibonacciSequence.hpp"
#include "ParametersContainer.hpp"
#include "GeneratedContainer.hpp"


int InitializeFibonacciSequenceParameters(void** parameters_container_to_initialize, unsigned int lower_bound, unsigned int upper_bound)
{
    // TODO try smart poriners
    ParametersContainer* parameters_container = NULL;
    
    try
    {
        parameters_container = new ParametersContainer(lower_bound, upper_bound);
    }
    catch (const std::invalid_argument& e)
	{
        if (parameters_container != NULL)
            delete parameters_container;
        
        return INIT_INVALID_BOUND;
	}
    
    *parameters_container_to_initialize = (void*)parameters_container;
    
    return INIT_SUCCEDED;
}


int GenerateFibonacciSequence(void* parameters_container, void **generated_sequence_container)
{
    if (parameters_container == NULL)
    {
        return GENERATING_PARAMETERS_ARE_NOT_VALID;
    }
    
    try
    {
        ParametersContainer* sequence_parameters_container = (ParametersContainer*)parameters_container;

        auto fibonacci_sequence = FibonacciSequence(sequence_parameters_container->get_lower_bound(), sequence_parameters_container->get_upper_bound());
        std::vector<unsigned int> *sequence = new std::vector<unsigned int>();
    
        for (auto it = fibonacci_sequence.begin(), end = fibonacci_sequence.end(); it < end; ++it)
        {
            const auto i = *it;
            sequence->push_back(i);
        }

        GeneratedContainer* sequence_container;

        
        unsigned int *elements = sequence->data();
        const int elements_count = sequence->size();
        sequence_container = new GeneratedContainer(elements, elements_count);

        *generated_sequence_container = (void*)sequence_container; 


    }
    catch(const std::exception& e)
    {
        return GENERATING_FAILED;
    }
    
    return GENERATING_SUCCEDED;
}