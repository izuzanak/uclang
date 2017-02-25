
#ifndef __UCLANG_H
#define __UCLANG_H

@begin
include "script_parser.h"
include "spawner.h"
@end

/*!
 * \brief function executing script interpreter
 * \param data - data pointing to int argument cnt and char * array (argc,argv)
 */
void *run_interpreter(void *data);


#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
/*!
 * \brief program main (input) function
 * \param argc - count of program arguments
 * \param argv - program argument string array
 */
int main(int argc,char **argv);
#endif

#endif

