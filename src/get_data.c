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

void	init_data(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->argv = argv;
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 777);
	data->n_pipe = argc - 3;
	data->pipe = ft_calloc(data->n_pipe * 2, sizeof(int));
	data->pid = ft_calloc(data->n_pipe, sizeof(pid_t));
	return ;
}
