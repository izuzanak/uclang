
#ifndef __UCLANG_H
#define __UCLANG_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <fcntl.h>
#include <sys/wait.h>

/*!
 * \brief function implementing process spawner
 * \param spawner_path - path to spawner fifo pipe
 * \param spawn_name - name of spawn source module
 */
int run_spawner(const char *proc_name,const char *spawner_path,string_s &spawn_name);
#endif

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

