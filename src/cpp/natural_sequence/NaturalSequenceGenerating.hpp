#pragma once

const int INIT_SUCCEDED                 =  0;
const int INIT_INVALID_UPPER_BOUND      = -1;

const int GENERATING_SUCCEDED                 =  0;
const int GENERATING_FAILED                   = -1;
const int GENERATING_PARAMETERS_ARE_NOT_VALID  = -2;



int InitializeNaturalSequenceParameters(void** parameters_container_to_initialize);

int GenerateNaturalSequence(void* parameters_container, void **generated_sequence_container);
