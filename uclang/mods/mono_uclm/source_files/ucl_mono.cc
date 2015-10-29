
@begin
include "ucl_mono.h"
@end

/*
 * static members of class mono_c
 */

MonoDomain *mono_c::domain;
MonoAssembly *mono_c::assembly;
MonoImage *mono_c::image;

// - mono global init object -
mono_c g_mono;

/*
 * methods of class mono_c
 */

