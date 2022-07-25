/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:04:17 by chughes           #+#    #+#             */
/*   Updated: 2022/07/06 13:04:50 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;
	int		i;

	data = get_data();
	init_data(argc, argv, envp);
	i = -1;
	if (pipe(&data->pipe[0]) != 0)
		exit_error("Pipe error ");
	while (++i < 2)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			exit_error("Fork error ");
		else if (data->pid[i] == 0)
			init_child(i);
	}
	close(data->pipe[0]);
	close(data->pipe[1]);
	waitpid(data->pid[0], NULL, 0);
	waitpid(data->pid[1], NULL, 0);
	del_data();
	return (0);
}
