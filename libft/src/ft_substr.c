/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:51:51 by chughes           #+#    #+#             */
/*   Updated: 2022/03/29 13:51:54 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	const char	*first;

	first = &s[start];
	str = ft_calloc((len + 1), sizeof(char));
	if (start > ft_strlen(s))
		return (str);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, first, (len + 1));
	str[len] = '\0';
	return (str);
}
