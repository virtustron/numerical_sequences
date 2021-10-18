#pragma once

int InitializeFibonacciSequenceParameters(void** parameters_container_to_initialize, unsigned int lower_bound, unsigned int upper_bound);

int GenerateFibonacciSequence(void* parameters_container, void **generated_sequence_container);
