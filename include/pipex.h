/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:58:16 by chughes           #+#    #+#             */
/*   Updated: 2022/07/06 13:04:02 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h> 
# include <sys/wait.h>

# include "../libft/include/libft.h"

// Pointer to an integer array
typedef int *array;

// Holds the file descriptors and programs
typedef struct	s_data {
	int		fd_in;
	int		fd_out;
	int		n_pipe;
	array	pipe;
	pid_t	*pid;
}			t_data;


t_data	*get_data(void);
void	init_data(int argc, char *argv[]);
void	exit_error(char *message);
void	del_data(void);

#endif
