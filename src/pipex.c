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

	data = get_data();
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[argc - 1], O_WRONLY, O_CREAT);



	return (0);
}

/* Notes
	0 - parent fd for first child
	1 - first child fd for parent
	2 - parent fd for second child
	3 - second child id for parent
	.
	.
	.



*/








void	child(char *argv[])
{
	char	**exec_args = ft_split(argv[3], ' ');

	execve("/bin/bash", exec_args, NULL);
}