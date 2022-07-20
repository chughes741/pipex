/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:04:17 by chughes           #+#    #+#             */
/*   Updated: 2022/07/19 13:04:50 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_input(int argc, char *argv[])
{
	if (argc != 5)
		exit_error("Error: Too few arguments ");
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		exit_error("Error: empty argument");
	return ;
}