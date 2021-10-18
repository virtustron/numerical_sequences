#pragma once

int InitializeNaturalSequenceParameters(void** parameters_container_to_initialize, unsigned int upper_bound);

int GenerateNaturalSequence(void* parameters_container, void **generated_sequence_container);
