/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
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

	check_input(argc, argv);
	data = get_data();
	init_data(argc, argv, envp);
	i = -1;
	while (++i < 2)
	{
		if (pipe(data->pipe) != 0)
			exit_error("Pipe error ");
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			exit_error("Fork error ");
		else if (data->pid[i] == 0)
			init_child(i);
		waitpid(data->pid[i], NULL, 0);
	}
	return (0);
}
