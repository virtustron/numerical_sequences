use std::ptr;

mod cpp_sequence_generating;

fn main() {
    let command_line_arguments: Vec<String> = std::env::args().collect();
    let mut is_arguments_valid: bool = true;

    if command_line_arguments.len() != 2
    {
        println!("Please enter upper bound for the sequence - one natural number (>0).\n");
        return;
    }

    let upper_bound = command_line_arguments[1].parse::<u32>().unwrap_or_else(|_| {
        println!("Not valid upper_bound_value: {}.", command_line_arguments[1]);
        is_arguments_valid = false;
        0
    });

    if !is_arguments_valid{
        println!("Program stopped due to previous error.");
        return;
    }


    let mut parameters_container: *mut std::os::raw::c_void;
    parameters_container = ptr::null_mut();

    
    unsafe{
        let init_result: std::os::raw::c_int;
        
        init_result = cpp_sequence_generating::InitializeNaturalSequenceParameters(&mut parameters_container, upper_bound);

        match init_result {
            cpp_sequence_generating::INIT_SUCCEDED => {
                
                let generating_result: std::os::raw::c_int;
                let mut generated_sequence_container: *mut std::os::raw::c_void;
                generated_sequence_container = ptr::null_mut();

                generating_result = cpp_sequence_generating::GenerateNaturalSequence(parameters_container, &mut generated_sequence_container);

                match  generating_result {
                    cpp_sequence_generating::GENERATING_SUCCEDED => {
                        let mut sequence_container: cpp_sequence_generating::NaturalSequenceGeneratedContainer;
                        sequence_container = generated_sequence_container as cpp_sequence_generating::NaturalSequenceGeneratedContainer;
                        
                    }

                    cpp_sequence_generating::GENERATING_PARAMETERS_ARE_NOT_VALID => {
                        println!("Function GenerateNaturalSequence() returned exception: COMPARATION_CONTAINER_IS_NULL.");
                    }

                    cpp_sequence_generating::GENERATING_FAILED => {
                        println!("Function GenerateNaturalSequence() returned exception: COMPARATION_FAILED.");
                    }

                    _ => {
                        println!("Unexpected error in the function GenerateNaturalSequence().");
                    }
                }
            }


            cpp_sequence_generating::INIT_INVALID_UPPER_BOUND => {
                println!("Function InitializeNaturalSequenceParameters() returned exception: INIT_INVALID_UPPER_BOUND.");
            }

            _ => {
                println!("Unexpected error in the function InitializeNaturalSequenceParameters().");
            }
        }
    }

    
}
