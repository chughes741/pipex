/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:14:17 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:14:18 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *str)
{
	int		i;
	size_t	output;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	output = (sizeof(char) * i);
	return (output);
}
