/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:09:18 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:09:27 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
	return ;
}
