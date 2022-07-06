/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:22:32 by chughes           #+#    #+#             */
/*   Updated: 2022/04/17 15:22:35 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list		args;
	t_mod		*mods;
	int			count;
	char		*format;

	format = (char *)form;
	count = 0;
	va_start(args, form);
	while (*format)
	{
		if (*format == '%')
		{
			mods = ft_get_mods(format);
			ft_print_arg(mods, args, &count);
			free(mods);
			format++;
			while (ft_strchr(" .-+#1234567890", *format))
				format++;
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
