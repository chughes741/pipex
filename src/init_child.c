/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:00:23 by chughes           #+#    #+#             */
/*   Updated: 2022/07/08 16:00:24 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Uses access to find the correct path 
static char	*get_path(char **paths, char *command)
{
	char	*path;
	int		i;

	i = -1;
	while(paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_str_prepend(path, command);
		if (access(path, F_OK) == 0)
			return(path);
		free(path);
	}
	exit_error("Error couldn't find program: ");
	return (NULL);
}

// Sets up pipes for children
static void	lay_pipe(int cid)
{
	t_data	*data;

	data = get_data();
	if (cid == 0)
	{
		dup2(data->fd_in, STDIN_FILENO);
		close(data->pipe[0]);
		dup2(data->pipe[1], STDOUT_FILENO);
	}
	else
	{
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->pipe[1]);
		dup2(data->pipe[0], STDIN_FILENO);
	}
	return ;
}

// Initializes a child process with execve
void	init_child(int cid)
{
	t_data	*data;
	char	*path;
	char	**exec_arg;

	data = get_data();
	lay_pipe(cid);
	exec_arg = ft_split(data->argv[cid + 2], ' ');
	path = get_path(data->paths, exec_arg[0]);
	execve(path, exec_arg, data->envp);
}
