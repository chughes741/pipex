/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:13:42 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:13:44 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *src)
{
	char	*outstr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	outstr = malloc((len + 1) * sizeof(char));
	if (outstr == NULL)
		return (NULL);
	while (i < len)
	{
		outstr[i] = src[i];
		i++;
	}
	outstr[i] = '\0';
	return (outstr);
}
