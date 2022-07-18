
//! HEADER

#include "../include/pipex.h"

void	check_input(int argc, char *argv[])
{
	if (argc < 5)
		exit_error("Error: Too few arguments ");
	if (!argv[0]) //! Void for compiling
		exit_error("This shouldn't be possible");
	return ;
}