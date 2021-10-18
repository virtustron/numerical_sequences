// this file originally here: 
//   https://rust-lang.github.io/rust-bindgen/tutorial-3.html

extern crate bindgen;

fn main() {
    
    let src = [
        "src/cpp/natural_sequence/NaturalSequenceIterator.cpp",     
        "src/cpp/natural_sequence/NaturalSequence.cpp",    
        "src/cpp/natural_sequence/NaturalSequenceParametersContainer.cpp", 
        "src/cpp/natural_sequence/NaturalSequenceGeneratedContainer.cpp", 
        "src/cpp/natural_sequence/NaturalSequenceGenerating.cpp", 
    ];
    
    println!("cargo:rerun-if-changed=src/wrapper.hpp");

    cc::Build::new()
        .cpp(true)    
        .files(src.iter())
        //.file("src/mymath.cpp")
        .compile("cpp_sequence_generating");
    
    let bindings = bindgen::Builder::default()
        .header("wrapper.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    bindings
        .write_to_file("src/cpp_sequence_generating.rs")
        .expect("Couldn't write bindings!");

    

    
}