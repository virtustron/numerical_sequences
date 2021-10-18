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
                        let sequence_container: *mut cpp_sequence_generating::NaturalSequenceGeneratedContainer;
                        sequence_container = generated_sequence_container as *mut cpp_sequence_generating::NaturalSequenceGeneratedContainer;

                        let elements_count = cpp_sequence_generating::NaturalSequenceGeneratedContainer_get_elements_count(sequence_container);
                        let elements: *mut ::std::os::raw::c_uint;
                        elements = cpp_sequence_generating::NaturalSequenceGeneratedContainer_get_elements(sequence_container);  

                        let elements_slice = std::slice::from_raw_parts(elements, elements_count as usize);

                        for &element in elements_slice {
                            print!("{}, ", element);

                        }  
                        println!("\n");                      
                    }

                    cpp_sequence_generating::GENERATING_PARAMETERS_ARE_NOT_VALID => {
                        println!("Function GenerateNaturalSequence() returned exception: GENERATING_PARAMETERS_ARE_NOT_VALID.");
                    }

                    cpp_sequence_generating::GENERATING_FAILED => {
                        println!("Function GenerateNaturalSequence() returned exception: GENERATING_FAILED.");
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
