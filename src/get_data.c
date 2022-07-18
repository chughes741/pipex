/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:55:39 by chughes           #+#    #+#             */
/*   Updated: 2022/07/08 15:55:46 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Singleton constructor for data struct
t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
	{
		data = ft_calloc(1, sizeof(t_data));
		data->fd_in = -1;
		data->fd_out = -1;
		data->n_pipe = -1;
	}
	return (data);
}

// Returns a new string with the PATH from envp
static char	**find_path(char *envp[])
{
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_strdup(&envp[i][5]);
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

// Initializes data struct
void	init_data(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	data = get_data();
	data->argv = argv;
	data->envp = envp;
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 777);
	data->n_pipe = argc - 3;
	data->pipe = ft_calloc(data->n_pipe * 2, sizeof(int));
	data->pid = ft_calloc(data->n_pipe, sizeof(pid_t));
	data->paths = find_path(envp);
	return ;
}
