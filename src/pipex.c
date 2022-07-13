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

	data = get_data();
	init_data(argc, argv);
	i = 0;
	while (i < data->n_pipe)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
		{
			perror("fork");
			exit(1);
		}
	}
	return (0);
}






void	child(char *argv[])
{
	char	**exec_args = ft_split(argv[3], ' ');

	execve("/bin/bash", exec_args, NULL);
}