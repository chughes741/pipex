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
