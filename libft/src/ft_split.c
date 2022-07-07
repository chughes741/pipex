/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:39:58 by chughes           #+#    #+#             */
/*   Updated: 2022/03/29 13:40:39 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	int				i;
	unsigned long	wordcount;

	i = 1;
	wordcount = 0;
	if (*s == '\0')
		return (wordcount);
	if (s[0] != c && s[0] != '\0')
		wordcount = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			wordcount++;
		i++;
	}
	return (wordcount);
}

static char	**makestrarray(unsigned int count)
{
	char	**rtn;

	rtn = (char **)ft_calloc(count + 1, sizeof(char *));
	if (rtn == NULL)
		return (NULL);
	rtn[count] = (void *)0;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char			**rtn;
	unsigned int	wordcount;
	unsigned int	start;
	unsigned int	end;

	wordcount = ft_wordcount(s, c);
	rtn = makestrarray(wordcount);
	if (rtn == NULL || wordcount == 0)
		return (rtn);
	start = (unsigned int)ft_strlen(s) - 1;
	while (s[start] && start >= 0 && wordcount >= 0)
	{
		while (s[start] && start > 0 && s[start] == c)
			start--;
		end = start;
		while (s[start] && start > 0 && s[start] != c)
			start--;
		wordcount--;
		if (start == 0)
			start -= 1;
		rtn[wordcount] = ft_substr(s, start + 1, (end - start));
		if (wordcount == 0)
			break ;
	}
	return (rtn);
}
