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

	data = get_data();
	init_data(argc, argv, envp);
	if (pipe(&data->pipe[0]) != 0)
		exit_error("Pipe error ");

	data->pid[0] = fork();
	if (data->pid[0] == 0)
		first_child();
	close(data->pipe[1]);
	waitpid(data->pid[0], NULL, 0);

	data->pid[1] = fork();
	if (data->pid[1] == 0)
		second_child();
	close(data->pipe[0]);
	waitpid(data->pid[1], NULL, 0);

	del_data();
	return (0);
}
