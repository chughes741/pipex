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
	path = ft_strdup(command);
	if (access(path, F_OK) == 0)
		return (path);
	path = ft_strjoin("./", command);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_str_prepend(path, command);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

// Initializes first child
void	first_child(void)
{
	t_data	*data;
	char	*path;
	char	**exec_arg;

	data = get_data();
	dup2(data->fd_in, STDIN_FILENO);
	dup2(data->pipe[1], STDOUT_FILENO);
	close(data->pipe[0]);
	close(data->pipe[1]);
	exec_arg = ft_split(data->argv[2], ' ');
	path = get_path(data->paths, exec_arg[0]);
	execve(path, exec_arg, data->envp);
}

// Initializes second child
void	second_child(void)
{
	t_data	*data;
	char	*path;
	char	**exec_arg;

	data = get_data();
	dup2(data->fd_out, STDOUT_FILENO);
	dup2(data->pipe[0], STDIN_FILENO);
	close(data->pipe[0]);
	close(data->pipe[1]);
	exec_arg = ft_split(data->argv[3], ' ');
	path = get_path(data->paths, exec_arg[0]);
	execve(path, exec_arg, data->envp);
}
