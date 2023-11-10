#![allow(
    dead_code,
    non_camel_case_types,
    non_snake_case,
    non_upper_case_globals)]

// - c types -
type c_uli     = usize;
type c_lli     = i64;
type c_ulli    = u64;
type c_bool    = bool;
type c_int     = i32;
type c_ui      = u32;
type c_double  = f64;
type c_void    = std::os::raw::c_void;
type c_pointer = *mut c_void;
type c_size_t  = usize;

extern
{//{{{
    // - clib symbols -
    static stdout:c_pointer;
    pub fn fwrite(ptr:*const u8,size:c_size_t,nmemb:c_size_t,stream:c_pointer) -> c_size_t;

    // - uclang symbols -
    pub fn atomic_s_value(a_this:*mut UclAtomic) -> c_int;
    pub fn atomic_s_atomic_set(a_this:*mut UclAtomic,a_value:c_int);
    pub fn atomic_s_atomic_inc(a_this:*mut UclAtomic);
    pub fn atomic_s_atomic_add(a_this:*mut UclAtomic,a_value:c_int);

    pub fn string_s_set(a_this:*mut UclString,a_length:c_ui,a_data:*const u8);

    pub fn exception_s_throw_exception(it:*mut UclIThread,a_type:c_ui,a_pos:c_ui,obj_location_ptr:*mut UclLocation) -> *mut UclException;
    pub fn exception_s_push_method_ri_class_idx(it:*mut UclIThread,new_exception:*mut UclException,a_class_idx:c_ui,a_method_name:*const u8);
    pub fn exception_s_push_parameter(a_this:*mut UclException,a_param:c_lli);

    pub fn interpreter_thread_s_get_new_location_ptr(it:*mut UclIThread) -> *mut UclLocation;
    pub fn interpreter_thread_s_get_new_string_ptr(it:*mut UclIThread) -> *mut UclString;
    pub fn interpreter_thread_s_release_location_ptr(it:*mut UclIThread,location_ptr:*mut UclLocation);
}//}}}

// - built in methods operand positions -
const c_source_pos_idx:isize = 0;
const c_res_op_idx    :isize = 1;
const c_dst_op_idx    :isize = 2;
const c_src_0_op_idx  :isize = 3;
const c_src_1_op_idx  :isize = 4;
const c_src_2_op_idx  :isize = 5;
const c_src_3_op_idx  :isize = 6;
const c_src_4_op_idx  :isize = 7;
const c_src_5_op_idx  :isize = 8;
const c_src_6_op_idx  :isize = 9;

// - indexes of built in classes -
const c_bi_class_blank     :u32 = 0;
const c_bi_class_char      :u32 = 1;
const c_bi_class_integer   :u32 = 2;
const c_bi_class_float     :u32 = 3;
const c_bi_class_string    :u32 = 4;
const c_bi_class_array     :u32 = 5;
const c_bi_class_error     :u32 = 6;
const c_bi_class_exception :u32 = 7;
const c_bi_class_type      :u32 = 8;
const c_bi_class_mutex     :u32 = 9;
const c_bi_class_thread    :u32 = 10;
const c_bi_class_delegate  :u32 = 11;
const c_bi_class_buffer    :u32 = 12;
const c_bi_reference       :u32 = 0xffffffff;

// - system errors and exceptions -
enum UclError
{//{{{
    OK = 0,
    UNKNOWN,

    EINVAL,
    EDEADLK,
    EBUSY,
    EPERM,
    EAGAIN,
    ESRCH,

    // - global errors -
    USER_EXCEPTION,
    TODO_EXCEPTION,

    // - run_expression -
    CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR,

    CLASS_DOES_NOT_CONTAIN_METHOD,
    CLASS_DOES_NOT_CONTAIN_VARIABLE,

    CANNOT_ACCESS_PRIVATE_METHOD,
    CANNOT_ACCESS_PRIVATE_VARIABLE,

    METHOD_CANNOT_RETURN_VALUE,
    CANNOT_TEST_TYPE_VALUE,

    CANNOT_CONVERT_TYPE_TO_INTEGER,
    CANNOT_USE_NEGATIVE_NUMBER,

    SLICE_NOT_INTEGER_ARGUMENTS,
    SLICE_START_LESS_THAN_ZERO,
    SLICE_STOP_LESS_THAN_ZERO,
    SLICE_STEP_EQUAL_TO_ZERO,

    OBJECT_OF_CLASS_IS_NOT_ITERABLE,
    UNEXPECTED_END_OF_ITERABLE,

    // - built_in -
    BUILT_IN_NOT_IMPLEMENTED_METHOD,

    METHOD_NOT_DEFINED_WITH_PARAMETERS,
    WRONG_METHOD_PARAMETER_VALUE,

    DIVISION_BY_ZERO,
    NEGATIVE_SHIFT_COUNT,

    METHOD_NOT_RETURN_INTEGER,
    METHOD_NOT_RETURN_STRING,
    METHOD_NOT_RETURN_INDEX,

    INTEGER_BASE_OUT_OF_RANGE,
    INTEGER_CONVERT_INVALID_STRING,

    FLOAT_CONVERT_INVALID_STRING,

    STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,
    STRING_FORMAT_WRONG_ARGUMENT_TYPE,
    STRING_FORMAT_ARGUMENT_FORMAT_ERROR,
    STRING_FORMAT_WRONG_FORMAT_SPECIFIER,
    STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED,

    STRING_INDEX_EXCEEDS_RANGE,
    STRING_WRONG_RANGE_INDEXES,
    STRING_CONVERT_FROM_INTEGER,
    STRING_CONVERT_FROM_FLOAT,

    ARRAY_INDEX_EXCEEDS_RANGE,
    ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE,
    ARRAY_NO_ELEMENTS,
    ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH,

    DELEGATE_NEGATIVE_PARAMETER_COUNT,
    DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,
    DELEGATE_CALL_WRONG_PARAMETER_COUNT,
    DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT,
    DELEGATE_WRONG_RETURN_VALUE_TYPE,
}//}}}

#[repr(C)]
pub struct UclAtomic
{//{{{

    // - FIXME only for linux -
    counter:c_int,
}//}}}

#[repr(C)]
pub struct UclString
{//{{{
    size:c_ui,
    data:*mut u8,
}//}}}

#[repr(C)]
union UclDataType
{//{{{
    lli:c_lli,
    llu:c_ulli,
    bd:c_double,
    ptr:c_pointer,
}//}}}

#[repr(C)]
pub struct UclLocation
{//{{{
    v_type:c_ui,
    v_reference_cnt:UclAtomic,
    v_data_ptr:UclDataType,
}//}}}

#[repr(C)]
pub struct UclLLIArray
{//{{{
    size:c_ui,
    used:c_ui,
    data:*mut c_lli,
}//}}}

#[repr(C)]
pub struct UclException
{//{{{
    exc_type:c_ui,
    position:c_ui,
    obj_location:c_pointer,
    params:UclLLIArray,
}//}}}

#[repr(C)]
pub struct UclPointerArray
{//{{{
    size:c_ui,
    used:c_ui,
    data:*mut c_pointer,
}//}}}

#[repr(C)]
pub struct UclLocationPointerArray
{//{{{
    size:c_ui,
    used:c_ui,
    data:*mut *mut UclLocation,
}//}}}

#[repr(C)]
pub struct UclIThread
{//{{{
    free_location_ptrs:UclPointerArray,
    free_reference_ptrs:UclPointerArray,

    interpreter_ptr:c_pointer,
    data_stack:UclLocationPointerArray,

    thread_location:c_pointer,
    blank_location:*mut UclLocation,
    exception_location:c_pointer,
}//}}}

impl UclIThread {

    fn get_stack_value(&mut self,stack_idx:isize) -> &mut *mut UclLocation
    {//{{{
        unsafe {
            let ref mut location = *self.data_stack.data.offset(stack_idx);

            if (**location).v_type == c_bi_reference {
                &mut *((**location).v_data_ptr.ptr as *mut *mut UclLocation)
            }
            else {
                &mut *location
            }
        }
    }//}}}
}

#[repr(C)]
pub struct UclModule
{//{{{
    class_cnt:c_ui,
    classes:c_pointer,

    error_base:c_ui,
    error_cnt:c_ui,
    error_strings:c_pointer,

    initialize_caller:c_pointer,
    print_exception_caller:c_pointer,
}//}}}

#[repr(C)]
pub struct UclLocationArray {}

#[allow(unused_macros)]
macro_rules! bic_todo_error
{//{{{
    ($it:expr,$operands:expr) => {
        let string = interpreter_thread_s_get_new_string_ptr($it);
        string_s_set(string,file!().len() as u32,file!().as_ptr());
        bic_create_new_location!($it,new_location,c_bi_class_string,ptr,string as c_pointer,0);

        let new_exception = exception_s_throw_exception($it,UclError::TODO_EXCEPTION as u32,*$operands.offset(c_source_pos_idx),new_location);
        exception_s_push_parameter(new_exception,line!() as i64);
    }
}//}}}

// - create new location macros -
macro_rules! bic_create_new_location
{//{{{
    ($it:expr,$name:ident,$class_idx:expr,$type:ident,$value:expr,$ref_cnt:expr) => {
        let $name = interpreter_thread_s_get_new_location_ptr($it);
        (*$name).v_type = $class_idx;
        atomic_s_atomic_set(&mut (*$name).v_reference_cnt,$ref_cnt);
        (*$name).v_data_ptr.$type = $value;
    };
    ($it:expr,$name:ident,$class_idx:expr,$type:ident,$value:expr) => {
        bic_create_new_location!($it,$name,$class_idx,$type,$value,1)
    };
}//}}}

// - set destination macros -
macro_rules! bic_set_destination
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$location_ptr:expr) => {
        let ref mut dst_location = bic_stack_location_value!($it,$stack_base,$operands,c_dst_op_idx);
        interpreter_thread_s_release_location_ptr($it,*dst_location);
        *dst_location = $location_ptr;
    };
}//}}}

// - set result macros -
macro_rules! bic_set_result
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$location_ptr:expr) => {
        let ref mut res_location = bic_stack_location!($it,$stack_base,$operands,c_res_op_idx);
        interpreter_thread_s_release_location_ptr($it,*res_location);
        *res_location = $location_ptr;
    };
}//}}}

macro_rules! bic_set_result_swap
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$location_ptr:expr) => {
        let ref mut res_location = bic_stack_location!($it,$stack_base,$operands,c_res_op_idx);
        let ref mut dst_location = bic_stack_location_value!($it,$stack_base,$operands,c_dst_op_idx);

        interpreter_thread_s_release_location_ptr($it,*res_location);
        *res_location = *dst_location;
        *dst_location = $location_ptr;
    };
}//}}}

macro_rules! bic_set_result_blank
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr) => {
        let blank_location = (*$it).blank_location;
        atomic_s_atomic_inc(&mut (*blank_location).v_reference_cnt);
        bic_set_result!($it,$stack_base,$operands,blank_location);
    };
}//}}}

macro_rules! bic_set_result_string
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$value:expr) => {
        bic_create_new_location!($it,new_location,c_bi_class_string,ptr,$value as c_pointer);
        bic_set_result!($it,$stack_base,$operands,new_location);
    };
}//}}}

macro_rules! bic_simple_set_res
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$class_idx:expr,$type:ident,$value:expr) => {
        let ref mut res_location = bic_stack_location!($it,$stack_base,$operands,c_res_op_idx);

        if (**res_location).v_type == $class_idx &&
            atomic_s_value(&mut (**res_location).v_reference_cnt) == 1
        {
            (**res_location).v_data_ptr.$type = $value;
        }
        else {
            bic_create_new_location!($it,new_location,$class_idx,$type,$value);
            interpreter_thread_s_release_location_ptr($it,*res_location);
            *res_location = new_location;
        }
    };
}//}}}

// - stack location macros -
macro_rules! bic_stack_location_value
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$idx:expr) => {
        *(*$it).get_stack_value(($stack_base as usize + *$operands.offset($idx)) as isize)
    };
}//}}}

macro_rules! bic_stack_location
{//{{{
    ($it:expr,$stack_base:expr,$operands:expr,$idx:expr) => {
        *((*$it).data_stack.data.offset(($stack_base as usize + *$operands.offset($idx)) as isize))
    };
}//}}}

// -----

extern {
    static c_bi_class_rust_string:c_ui;

    static module:UclModule;
}

enum ModuleError {
    RUST_STRING_UTF8_ENCODING_ERROR = 0,
}

#[no_mangle]
pub extern "C" fn bic_rust_string_consts(_const_locations:*mut UclLocationArray)
{//{{{
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_init(_it:*mut UclIThread,location_ptr:*mut UclLocation)
{//{{{
    unsafe { (*location_ptr).v_data_ptr.ptr = Box::into_raw(Box::new(String::new())) as c_pointer; }
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_clear(_it:*mut UclIThread,location_ptr:*mut UclLocation)
{//{{{
    unsafe { drop(Box::from_raw((*location_ptr).v_data_ptr.ptr as *mut String)); }
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_operator_binary_equal(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let src_0_location = bic_stack_location_value!(it,stack_base,operands,c_src_0_op_idx);

        atomic_s_atomic_add(&mut (*src_0_location).v_reference_cnt,2);

        bic_set_destination!(it,stack_base,operands,src_0_location);
        bic_set_result!(it,stack_base,operands,src_0_location);
    }

    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_operator_unary_post_double_plus(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let dst_location = bic_stack_location_value!(it,stack_base,operands,c_dst_op_idx);
        let ref string = *((*dst_location).v_data_ptr.ptr as *const String);

        let result = Box::into_raw(Box::new(string.clone() + " ++"));

        bic_create_new_location!(it,new_location,c_bi_class_rust_string,ptr,result as c_pointer);
        bic_set_result_swap!(it,stack_base,operands,new_location);
    }

    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_operator_unary_pre_double_plus(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let dst_location = bic_stack_location_value!(it,stack_base,operands,c_dst_op_idx);
        let ref string = *((*dst_location).v_data_ptr.ptr as *const String);

        let result = Box::into_raw(Box::new(string.clone() + " ++"));

        bic_create_new_location!(it,new_location,c_bi_class_rust_string,ptr,result as c_pointer,2);
        bic_set_destination!(it,stack_base,operands,new_location);
        bic_set_result!(it,stack_base,operands,new_location);
    }

    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_method_RustString_0(_it:*mut UclIThread,_stack_base:c_ui,_operands:*mut c_uli) -> c_bool
{//{{{
    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_method_RustString_1(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let dst_location = bic_stack_location_value!(it,stack_base,operands,c_dst_op_idx);
        let src_0_location = bic_stack_location_value!(it,stack_base,operands,c_src_0_op_idx);

        // - ERROR -
        if (*src_0_location).v_type != c_bi_class_string {
            let new_exception = exception_s_throw_exception(it,UclError::METHOD_NOT_DEFINED_WITH_PARAMETERS as u32,*operands.offset(c_source_pos_idx) as u32,(*it).blank_location);
            exception_s_push_method_ri_class_idx(it,new_exception,(*dst_location).v_type,"RustString#1\0".as_ptr());
            exception_s_push_parameter(new_exception,1);
            exception_s_push_parameter(new_exception,(*src_0_location).v_type as i64);

            return false;
        }

        let ref mut string = *((*dst_location).v_data_ptr.ptr as *mut String);
        let ref source = *((*src_0_location).v_data_ptr.ptr as *const UclString);

        let slice = std::slice::from_raw_parts(source.data,source.size as usize - 1);

        match std::str::from_utf8(slice) {
            Ok(value) => string.push_str(value),

            // - ERROR -
            Err(_) => {
                exception_s_throw_exception(it,module.error_base + ModuleError::RUST_STRING_UTF8_ENCODING_ERROR as u32,*operands.offset(c_source_pos_idx) as u32,(*it).blank_location);
                return false;
            }
        }
    }

    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_method_length_0(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let dst_location = bic_stack_location_value!(it,stack_base,operands,c_dst_op_idx);

        let result = (*((*dst_location).v_data_ptr.ptr as *const String)).len() as i64;

        bic_simple_set_res!(it,stack_base,operands,c_bi_class_integer,lli,result);
    }

    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_method_to_string_0(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let dst_location = bic_stack_location_value!(it,stack_base,operands,c_dst_op_idx);

        let ref string = *((*dst_location).v_data_ptr.ptr as *const String);

        let result = interpreter_thread_s_get_new_string_ptr(it);
        string_s_set(result,string.len() as u32,string.as_ptr());

        bic_set_result_string!(it,stack_base,operands,result);
    }

    true
}//}}}

#[no_mangle]
pub extern "C" fn bic_rust_string_method_print_0(it:*mut UclIThread,stack_base:c_ui,operands:*mut c_uli) -> c_bool
{//{{{
    unsafe {
        let dst_location = bic_stack_location_value!(it,stack_base,operands,c_dst_op_idx);

        let ref string = *((*dst_location).v_data_ptr.ptr as *const String);
        fwrite(string.as_ptr(),string.len(),1,stdout);

        bic_set_result_blank!(it,stack_base,operands);
    }

    true
}//}}}

