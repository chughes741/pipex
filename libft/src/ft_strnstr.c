/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:14:35 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:14:37 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned long	i;

	i = 0;
	if (needle == NULL || haystack == NULL)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && n--)
	{
		while (*haystack && *haystack != needle[i] && n)
		{
			haystack++;
			n--;
		}
		while (needle[i] && haystack[i] == needle[i] && n >= i)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		i = 0;
	}
	return (NULL);
}
