/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:26:34 by chughes           #+#    #+#             */
/*   Updated: 2022/04/21 11:26:37 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_flags(t_mod *mods, char *format)
{
	while (ft_strchr("-+ #0", *format))
	{
		if (*format == '-')
			mods->dash = 1;
		if (*format == '+')
			mods->plus = 1;
		if (*format == ' ')
			mods->space = 1;
		if (*format == '#')
			mods->hash = 1;
		if (*format == '0')
			mods->zero = 1;
		format++;
	}
	return (format);
}

static char	*ft_get_num(char *format, int *num)
{
	int	count;

	count = 0;
	if (*format == '.')
		format++;
	while (format[count] && format[count] >= '0' && format[count] <= '9')
		count++;
	*num = ft_atoi(format);
	return (&format[count]);
}

t_mod	*ft_get_mods(char *format)
{
	t_mod	*mods;

	format++;
	mods = ft_calloc(1, sizeof(t_mod));
	if (mods == NULL)
		return (NULL);
	format = ft_get_flags(mods, format);
	mods->width = -1;
	mods->precision = -1;
	if (ft_isdigit((int)*format))
		format = ft_get_num(format, &mods->width);
	if (*format == '.')
		format = ft_get_num(format, &mods->precision);
	if (mods->precision > mods->width)
		mods->width = mods->precision;
	mods->specifier = (char)*format;
	format++;
	return (mods);
}
