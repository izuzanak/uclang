
#ifndef __UCL_SIGNAL_H
#define __UCL_SIGNAL_H

@begin
include "script_parser.h"
@end

/*
 * constants and definitions
 */

extern unsigned c_rm_class_bin_array;

// - bin array types -
enum
{
  c_bin_array_type_int32,
  c_bin_array_type_uint32,
  c_bin_array_type_float,
  c_bin_array_type_double,
};

/*
 * definition of structure bin_array_s
 */

struct bin_array_s
{
  unsigned type;
  void *cont;
  pointer_array_s free_references;
};

/*
 * definition of generated structures
 */

// -- search_result_s --
@begin
struct
<
ui:start
ui:end
bd:dist
ui:dist_cnt
>
search_result_s;
@end

// -- search_results_s --
@begin
array<search_result_s> search_results_s;
@end

/*
 * inline methods of generated structures
 */

// -- search_result_s --
@begin
inlines search_result_s
@end

// -- search_results_s --
@begin
inlines search_results_s
@end

/*
 * definition of structure data_signal_s
 */

struct data_signal_s
{
  static void search_2d(bd_array_s *a_data[2],bd_array_s *a_win[2],
      unsigned a_step,unsigned a_dist,double a_dist_max,unsigned a_dist_count,
      search_results_s &a_results);
};

#endif

