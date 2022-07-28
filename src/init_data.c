/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:34:21 by chughes           #+#    #+#             */
/*   Updated: 2022/07/25 18:34:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	if (argc != 5)
		exit_error("Error: Too few arguments ");
	data->argv = argv;
	data->envp = envp;
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	data->paths = find_path(envp);
	return ;
}
