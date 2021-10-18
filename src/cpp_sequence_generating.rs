/* automatically generated by rust-bindgen 0.59.1 */

pub const INIT_SUCCEDED: ::std::os::raw::c_int = 0;
pub const INIT_INVALID_UPPER_BOUND: ::std::os::raw::c_int = -1;
pub const GENERATING_SUCCEDED: ::std::os::raw::c_int = 0;
pub const GENERATING_FAILED: ::std::os::raw::c_int = -1;
pub const GENERATING_PARAMETERS_ARE_NOT_VALID: ::std::os::raw::c_int = -2;
extern "C" {
    #[link_name = "\u{1}_Z35InitializeNaturalSequenceParametersPPvj"]
    pub fn InitializeNaturalSequenceParameters(
        parameters_container_to_initialize: *mut *mut ::std::os::raw::c_void,
        upper_bound: ::std::os::raw::c_uint,
    ) -> ::std::os::raw::c_int;
}
extern "C" {
    #[link_name = "\u{1}_Z23GenerateNaturalSequencePvPS_"]
    pub fn GenerateNaturalSequence(
        parameters_container: *mut ::std::os::raw::c_void,
        generated_sequence_container: *mut *mut ::std::os::raw::c_void,
    ) -> ::std::os::raw::c_int;
}
#[repr(C)]
#[derive(Debug)]
pub struct NaturalSequenceGeneratedContainer {
    pub m_elements_count: ::std::os::raw::c_int,
    pub m_elements: *mut ::std::os::raw::c_uint,
}
#[test]
fn bindgen_test_layout_NaturalSequenceGeneratedContainer() {
    assert_eq!(
        ::std::mem::size_of::<NaturalSequenceGeneratedContainer>(),
        16usize,
        concat!("Size of: ", stringify!(NaturalSequenceGeneratedContainer))
    );
    assert_eq!(
        ::std::mem::align_of::<NaturalSequenceGeneratedContainer>(),
        8usize,
        concat!(
            "Alignment of ",
            stringify!(NaturalSequenceGeneratedContainer)
        )
    );
    assert_eq!(
        unsafe {
            &(*(::std::ptr::null::<NaturalSequenceGeneratedContainer>())).m_elements_count
                as *const _ as usize
        },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(NaturalSequenceGeneratedContainer),
            "::",
            stringify!(m_elements_count)
        )
    );
    assert_eq!(
        unsafe {
            &(*(::std::ptr::null::<NaturalSequenceGeneratedContainer>())).m_elements as *const _
                as usize
        },
        8usize,
        concat!(
            "Offset of field: ",
            stringify!(NaturalSequenceGeneratedContainer),
            "::",
            stringify!(m_elements)
        )
    );
}
extern "C" {
    #[link_name = "\u{1}_ZN33NaturalSequenceGeneratedContainer18get_elements_countEv"]
    pub fn NaturalSequenceGeneratedContainer_get_elements_count(
        this: *mut NaturalSequenceGeneratedContainer,
    ) -> ::std::os::raw::c_int;
}
extern "C" {
    #[link_name = "\u{1}_ZN33NaturalSequenceGeneratedContainer12get_elementsEv"]
    pub fn NaturalSequenceGeneratedContainer_get_elements(
        this: *mut NaturalSequenceGeneratedContainer,
    ) -> *mut ::std::os::raw::c_uint;
}
extern "C" {
    #[link_name = "\u{1}_ZN33NaturalSequenceGeneratedContainer12set_elementsEPji"]
    pub fn NaturalSequenceGeneratedContainer_set_elements(
        this: *mut NaturalSequenceGeneratedContainer,
        elements: *mut ::std::os::raw::c_uint,
        elements_count: ::std::os::raw::c_int,
    );
}
extern "C" {
    #[link_name = "\u{1}_ZN33NaturalSequenceGeneratedContainerC1Ev"]
    pub fn NaturalSequenceGeneratedContainer_NaturalSequenceGeneratedContainer(
        this: *mut NaturalSequenceGeneratedContainer,
    );
}
extern "C" {
    #[link_name = "\u{1}_ZN33NaturalSequenceGeneratedContainerC1EPji"]
    pub fn NaturalSequenceGeneratedContainer_NaturalSequenceGeneratedContainer1(
        this: *mut NaturalSequenceGeneratedContainer,
        elements: *mut ::std::os::raw::c_uint,
        elements_count: ::std::os::raw::c_int,
    );
}
extern "C" {
    #[link_name = "\u{1}_ZN33NaturalSequenceGeneratedContainerD1Ev"]
    pub fn NaturalSequenceGeneratedContainer_NaturalSequenceGeneratedContainer_destructor(
        this: *mut NaturalSequenceGeneratedContainer,
    );
}
impl NaturalSequenceGeneratedContainer {
    #[inline]
    pub unsafe fn get_elements_count(&mut self) -> ::std::os::raw::c_int {
        NaturalSequenceGeneratedContainer_get_elements_count(self)
    }
    #[inline]
    pub unsafe fn get_elements(&mut self) -> *mut ::std::os::raw::c_uint {
        NaturalSequenceGeneratedContainer_get_elements(self)
    }
    #[inline]
    pub unsafe fn set_elements(
        &mut self,
        elements: *mut ::std::os::raw::c_uint,
        elements_count: ::std::os::raw::c_int,
    ) {
        NaturalSequenceGeneratedContainer_set_elements(self, elements, elements_count)
    }
    #[inline]
    pub unsafe fn new() -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        NaturalSequenceGeneratedContainer_NaturalSequenceGeneratedContainer(
            __bindgen_tmp.as_mut_ptr(),
        );
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn new1(
        elements: *mut ::std::os::raw::c_uint,
        elements_count: ::std::os::raw::c_int,
    ) -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        NaturalSequenceGeneratedContainer_NaturalSequenceGeneratedContainer1(
            __bindgen_tmp.as_mut_ptr(),
            elements,
            elements_count,
        );
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn destruct(&mut self) {
        NaturalSequenceGeneratedContainer_NaturalSequenceGeneratedContainer_destructor(self)
    }
}
