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

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->fd_input = open(argv[1], 'r');
	data->fd_output = open(argv[argc - 1], 'w');

	char buffer[11];
	read(data->fd_input, buffer, 10);
	printf("%s\n", buffer);
	char buffer2[11];
	read(data->fd_output, buffer2, 10);
	printf("%s\n", buffer2);

	return (0);
}

void	child(char *argv[])
{
	char	**exec_args = ft_split(argv[3], ' ');

	execve("/bin/bash", exec_args, NULL);
}