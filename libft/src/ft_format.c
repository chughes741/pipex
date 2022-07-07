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

#include "../include/libft.h"

char	*ft_neg_pop(char *str, _Bool *neg)
{
	char	*rtn;

	if (str[0] != '-')
		return (str);
	*neg = 1;
	rtn = ft_strdup(&str[1]);
	free(str);
	if (rtn == NULL)
		return (NULL);
	return (rtn);
}

char	*ft_min_width(char *str, int width, int zero)
{
	_Bool	neg;

	neg = 0;
	if (ft_strlen(str) >= (unsigned long)width || width < 0)
		return (str);
	if (str[0] == '-' && zero)
		str = ft_neg_pop(str, &neg);
	width -= ft_strlen(str);
	while ((width--) > 0)
		str = ft_str_append(" ", str);
	if (zero)
		ft_space_to_zero(str);
	if (neg && zero)
		str[0] = '-';
	return (str);
}

static char	*ft_precision(char *str, t_mod *mod)
{
	_Bool	neg;

	neg = 0;
	if (mod->precision == 0 && str[0] == '0')
	{
		free(str);
		mod->zero = 0;
		return (ft_strdup(""));
	}
	str = ft_neg_pop(str, &neg);
	str = ft_min_width(str, mod->precision, mod->zero);
	ft_space_to_zero(str);
	mod->zero = 0;
	if (neg)
		str = ft_str_append("-", str);
	return (str);
}

char	*ft_format(t_mod *mod, char *str)
{
	if (mod->specifier == 's')
		return (ft_format_str(str, mod));
	if (mod->hash && (ft_strlen(str) != 1 || str[0] != '0'))
		str = ft_str_append("0x", str);
	if (mod->specifier == 'p')
		str = ft_str_append("0x", str);
	if (mod->precision >= 0)
		str = ft_precision(str, mod);
	if (mod->zero && mod->precision >= 0)
		ft_space_to_zero(str);
	if (mod->specifier == 'X')
		ft_strupper(str);
	if (mod->plus && str[0] != '-')
		str = ft_str_append("+", str);
	if (mod->space && str[0] != ' ' && str[0] != '-')
		str = ft_str_append(" ", str);
	if (mod->zero)
		ft_space_to_zero(str);
	str = ft_min_width(str, mod->width, mod->zero);
	if (mod->dash)
		ft_left_justify(str);
	return (str);
}
