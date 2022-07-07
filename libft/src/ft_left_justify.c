/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_justify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:57:54 by chughes           #+#    #+#             */
/*   Updated: 2022/05/20 09:57:58 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_left_justify(char *str)
{
	int	i;
	int	j;

	if (str[0] != ' ')
		return ;
	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[j])
	{
		str[i] = str[j];
		str[j] = ' ';
		i++;
		j++;
	}
	return ;
}
