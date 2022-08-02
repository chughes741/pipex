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

// 0/1 return if char at pos is \' || \"
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
	while (array[++i])
	{
		if (is_quote(array[i], 0) && !is_quote(array[i], -1))
		{
			while (!is_quote(array[i], -1))
				i++;
		}
		else
			count++;
	}
	return (count);
}

// Split with apostrophe sensitivity
char	**split_arguments(char *args)
{
	char	**split_args;
	char	**return_args;
	int		i;
	int		j;

	split_args = ft_split(args, ' ');
	return_args = ft_calloc(arg_count(split_args) + 2, sizeof(char *));
	i = -1;
	j = -1;
	while (split_args[++i] && ++j > -1)
	{
		return_args[j] = ft_strdup(split_args[i]);
		while (is_quote(return_args[j], 0))
		{
			if (is_quote(split_args[i], -1))
				break ;
			i++;
			return_args[j] = ft_str_prepend(return_args[j], " ");
			return_args[j] = ft_str_prepend(return_args[j], split_args[i]);
		}
		return_args[j] = trimfree(return_args[j]);
	}
	return (return_args);
}
