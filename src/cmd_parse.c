/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:17 by chughes           #+#    #+#             */
/*   Updated: 2022/08/01 13:04:50 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	awk "{count++} END {printf \"count: %i\" , count}"
	./"script space.sh"
	./"script\"quote.sh"
*/

// Duplicates contents from cmds into rtn, frees cmds
static void lst_to_str(char ***rtn, t_list *cmds)
{
	t_list	*node;
	int		i;

	node = cmds;
	i = -1;
	while (node && *rtn[++i])
	{
		*rtn[i] = ft_strdup(node->content);
		node = node->next;
	}
	while (cmds)
	{
		while ((node->next)->next)
			node = node->next;
		free((node->next)->content);
		free(node->next);
		node->next = NULL;
		node = cmds;
	}
	return ;
}

// Returns index of first instance of char in c
static int len_to_c(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			break ;
		i++;
	}
	return (i);
}

// Returns index of end of first cmd
static int first_len(char *str)
{
    int     i;

    i = 0;
	if (len_to_c(str, " "))
    while (str[i] && str[i] != ' ');
		i++;
    return (i);
}

// Beep boop write better docstrings Cole
char **cmd_parse(char *cmd)
{
	t_list	*cmds;
	char	**rtn;

	cmds = ft_lstnew(ft_substr(cmd, 0, first_len(cmd)));


	rtn = ft_calloc(ft_lstsize(cmds) + 1, sizeof(char *));
	lst_to_str(&rtn, cmds);
	return (rtn);
}