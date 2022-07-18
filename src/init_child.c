/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
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
	return (NULL);
}

// Initializes a child process with execve
void	init_child(int i)
{
	t_data	*data;
	char	*path;
	char	**exec_arg;

	data = get_data();
	exec_arg = ft_split(data->argv[i + 2], ' ');
	path = get_path(data->paths, exec_arg[0]);
	printf("Path is: %s\n", path); //! DEBUG
	printf("Args are: %s\n", exec_arg[0]); //! DEBUG
	execve(path, exec_arg, data->envp);
}
