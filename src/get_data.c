/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
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
		data = ft_calloc(1, sizeof(t_data));
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
void	init_data(char *argv[], char *envp[])
{
	t_data	*data;

	data = get_data();
	data->argv = argv;
	data->envp = envp;
	data->fd_in = open(argv[1], O_RDONLY);
	if (data->fd_in < 0)
		exit_error("Error with input file ");
	data->fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out < 0)
		exit_error("Error with output file ");
	data->paths = find_path(envp);
	return ;
}
