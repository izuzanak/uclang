
#ifndef __CONTAINERS_H
#define __CONTAINERS_H

@begin
include "script_parser.h"
@end

/*
 * definition of generated structures
 */

// -- pointer_queue_s --
@begin
queue<pointer> pointer_queue_s;
@end

// -- pointer_list_s --
@begin
safe_list<pointer> pointer_list_s;
@end

/*
 * inline methods of generated structures
 */

// -- pointer_queue_s --
@begin
inlines pointer_queue_s
@end

// -- pointer_list_s --
@begin
inlines pointer_list_s
@end

#endif

