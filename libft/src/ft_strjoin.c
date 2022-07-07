/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:51:26 by chughes           #+#    #+#             */
/*   Updated: 2022/03/29 13:51:29 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rtn = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		rtn[i + j] = s2[j];
		j++;
	}
	rtn[i + j] = '\0';
	return (rtn);
}
