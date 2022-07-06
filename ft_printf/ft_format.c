/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chuhges@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:41:51 by chughes           #+#    #+#             */
/*   Updated: 2022/05/18 13:41:53 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_space_to_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return ;
}

static char	*ft_set_width(char *str, int width)
{
	if (ft_strlen(str) >= (unsigned long)width)
		return (str);
	width -= ft_strlen(str);
	while ((width--) > 0)
		str = ft_str_append(" ", str);
	return (str);
}

static void	ft_left_justify(char *str)
{
	int	i;
	int	j;

	if (str[0] != ' ')
		return ;
	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[j])
	{
		str[i] = str[j];
		str[j] = ' ';
		i++;
		j++;
	}
	return ;
}

static void	ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] ^= 1 << 5;
		i++;
	}
}

char	*ft_format(t_mod *mod, char *str)
{
	if (mod->hash && (ft_strlen(str) != 1 || str[0] != '0'))
		str = ft_str_append("0x", str);
	if (mod->specifier == 'p')
		str = ft_str_append("0x", str);
	if (mod->width >= 0 && mod->width >= mod->precision)
		str = ft_set_width(str, mod->width);
	else if (mod->precision >= 0 && mod->precision > mod->width)
		str = ft_set_width(str, mod->precision);
	if (mod->specifier == 'X')
		ft_strupper(str);
	if (mod->plus && str[0] != '-')
		str = ft_str_append("+", str);
	if (mod->dash)
		ft_left_justify(str);
	if (mod->space && str[0] != ' ' && str[0] != '-')
		str = ft_str_append(" ", str);
	if (mod->zero)
		ft_space_to_zero(str);
	return (str);
}
