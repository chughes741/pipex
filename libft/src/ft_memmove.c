/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:13:19 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:13:20 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstptr;
	char	*srcptr;
	char	*temp;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	temp = (char *)ft_calloc(n, sizeof(char));
	dstptr = (char *)dst;
	srcptr = (char *)src;
	while (i < n)
	{
		temp[i] = srcptr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dstptr[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
