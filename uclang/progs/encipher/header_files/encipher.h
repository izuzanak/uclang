
#ifndef __ENCIPHER_H
#define __ENCIPHER_H

@begin
include "ucl_string.h"
include "cipher.h"
@end

/*!
 * \brief encipher content of file, and print it to output stream
 * \param argc - count of program arguments
 * \param argv - program argument string array
 */
void encipher_file(int argc,char **argv);

/*!
 * \brief program main (input) function
 * \param argc - count of program arguments
 * \param argv - program argument string array
 */
int main(int argc,char **argv);

#endif

