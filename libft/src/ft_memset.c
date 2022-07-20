/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:16:13 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:16:15 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Sets 'n' bytes in mem to 'c' starting at 'str'
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*s;

	s = (char *)str;
	count = 0;
	while (count < n)
	{
		s[count] = c;
		count++;
	}
	return (s);
}
