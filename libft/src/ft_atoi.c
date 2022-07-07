/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:08:51 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:09:07 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_pow10(int pow)
{
	int	result;

	if (pow <= 0)
		result = 1;
	else if (pow == 1)
		result = 10;
	else
		result = 10 * ft_pow10(pow - 1);
	return (result);
}

static int	is_space(char n)
{
	if (n == ' ' || n == '\n' || n == '\t' || n == '\v' || n == '\f' \
		|| n == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	output;
	int	i;
	int	j;

	i = 0;
	j = 0;
	output = 0;
	while (str[i] != '\0' && is_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	while (i >= 0)
	{
		if (ft_isdigit(str[i]))
			output += (str[i] - 48) * ft_pow10(j - 1);
		else if (str[i] == '-' && j > 0)
			return (output * -1);
		else if (str[i] == '+' && j > 0)
			return (output);
		i--;
		j++;
	}
	return (output);
}
