
#ifndef __UCL_LANG_H
#define __UCL_LANG_H

@begin
include "script_parser.h"
@end

/*!
 * \brief fill array by indexes of top level classes
 * \param it reference to interpreter thread
 * \param a_class_idxs reference to target index array
 */
void get_top_level_classes(interpreter_thread_s &it,ui_array_s &a_class_idxs);

/**
 * \brief retrieve index of top level class with symbol identified by given index
 *
 * \param it reference to interpreter thread
 * \param a_name_idx class symbol name index
 * \param a_class_idx found class record index
 *
 * \return true if class was found
 */
bool get_top_level_class(interpreter_thread_s &it,unsigned a_name_idx,unsigned &a_class_idx);

/*!
 * \brief retrieve index of class record by given class path
 *
 * \param it reference to interpreter thread
 * \param a_path_array array of strings representing class path
 * \param a_class_idx found class index, c_idx_not_exist otherwise
 *
 * \return false if exception was thrown
 */
bool get_class_idx_by_path(interpreter_thread_s &it,pointer_array_s *a_path_array,unsigned a_path_length,unsigned &a_class_idx);

#endif

