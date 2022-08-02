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
# include <stdint.h> //! For compiling on Linux

# include "../libft/include/libft.h"

// Holds the file descriptors and programs
typedef struct s_data {
	char	**argv;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		pipe[2];
	pid_t	pid[2];
	char	**paths;
}			t_data;

t_data	*get_data(void);
void	init_data(int argc, char *argv[], char *envp[]);
void	exit_error(char *message);
void	del_data(void);
void	init_child(int cid);
char	*ft_str_prepend(char *s1, char *s2);
void	first_child(void);
void	second_child(void);
char	**split_arguments(char *args);
char	*trimfree(char *str);

#endif
