/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:52:14 by chughes           #+#    #+#             */
/*   Updated: 2022/08/02 13:52:17 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Trims 'set' char from either side of 'str', frees 'str'
char	*trimfree(char *str)
{
	char			*rtn;
	unsigned int	start;
	size_t			len;

	start = 0;
	len = ft_strlen(str) - 1;
	if (str[0] == '\0')
		return (ft_strdup(str));
	while (ft_strchr("\'\"", (int)str[start]) != NULL && start <= len)
		start++;
	while (ft_strchr("\'\"", (int)str[len]) != NULL && start <= len)
		len--;
	rtn = ft_substr(str, start, (len - start + 1));
	free(str);
	return (rtn);
}
