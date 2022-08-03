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
	t_list	*head;
	t_list	*node;
	int		i;

	head = cmds;
	node = cmds;
	i = -1;
	while (node && *rtn[++i])
	{
		*rtn[i] = ft_strdup(node->content);
		node = node->next;
	}
	ft_lstclear(cmds, free());
	return ;
}

// Beep boop write better docstrings Cole
char **cmd_parse(char *cmd)
{
	t_list	*cmds;
	char	**rtn;

	if (is_quote(cmd, 0))
		cmds = ft_lstnew(until next matching quote)
	else
		cmds = ft_lstnew(until first space)
	if (start of cmd is './')
		remove './' from cmds->contents

	rtn = ft_calloc(ft_lstsize(cmds) + 1, sizeof(char *))
	lst_to_str(&rtn, cmds);
	return (rtn);
}