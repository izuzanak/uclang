
#ifndef __NODE_H
#define __NODE_H

@begin
include "ucl_libnode.h"
@end

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
/*!
 * \brief program main (input) function
 * \param argc - count of program arguments
 * \param argv - program argument string array
 */
int main(int argc,char **argv);
#endif

#endif

