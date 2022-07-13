/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:58:12 by chughes           #+#    #+#             */
/*   Updated: 2022/07/13 14:58:14 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	del_data(void)
{
	t_data	*data;

	data = get_data();
	if (data->pipe)
		free(data->pipe);
	if (data->pid)
		free(data->pid);
	if (data)
		free(data);
	return ;
}
