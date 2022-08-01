/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:17 by chughes           #+#    #+#             */
/*   Updated: 2022/08/01 13:04:50 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	is_quote(char *str, int pos)
{
	int rtn;

	rtn = 0;
	if (pos == -1)
	{
		if (str[ft_strlen(str) - 1] == '\'' || str[ft_strlen(str) - 1] == '\"')
			rtn = 1;
	}
	else if (str[pos] == '\'' || str[pos] == '\"')
		rtn = 1;
	return (rtn);
}

// Counts number of args in 's', ignoring \' and \"
static size_t	arg_count(char **array)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (array[i])
	{
		if (is_quote(array[i], -1))
		{
			i++;
			count++;
		}
		else if (is_quote(array[i], 0))
			i++;
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	**split_arguments(char *args)
{
	char	**arg_array;
	char	**return_array;
	int		i;
	int		j;

	arg_array = ft_split(args, ' ');
	return_array = ft_calloc(arg_count(arg_array) + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (arg_array[i])
	{
		return_array[j] = ft_strdup(arg_array[i]);
		while (is_quote(return_array[j], 0))
		{
			if (is_quote(arg_array[i], -1))
				break ;
			i++;
			return_array[j] = ft_str_prepend(return_array[j], arg_array[i]);
		}
		j++;
		i++;
	}
	return (arg_array);
}

