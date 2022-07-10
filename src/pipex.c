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

int	main(int c, char *args[])
{
	t_data	*data;
	char	*path = "/bin/bash";
	char	*exec_args[] = {path, "-c", "echo \"Visit $HOSTNAME from your browser.\"", NULL};
	char	*env[] = {NULL};
	int		parent;

	parent = fork();
	if (parent)
		fork();
	data = get_data();
	data->fd_input = c;
	args = NULL;
	execve(path, exec_args, env);
	return (0);
}
