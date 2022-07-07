/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:55:14 by chughes           #+#    #+#             */
/*   Updated: 2022/04/21 13:55:18 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

static char	*ft_get_num(t_mod *mod, va_list args, char *output)
{
	free(output);
	if (mod->specifier == 'd' || mod->specifier == 'i')
		output = ft_itoa(va_arg(args, int));
	if (mod->specifier == 'u')
		output = ft_utoa(va_arg(args, unsigned int));
	if (mod->specifier == 'x' || mod->specifier == 'X')
		output = ft_itox(va_arg(args, unsigned int));
	if (mod->specifier == 'p')
		output = ft_ptoa((va_arg(args, uintptr_t)));
	return (output);
}

static void	ft_print_chr(int chr, t_mod *mod, int *count, char *output)
{
	free(output);
	if (mod->width <= 1)
	{
		*count += ft_putchar(chr);
		return ;
	}
	else if (mod->dash)
	{
		*count += ft_putchar(chr);
		while (--mod->width)
			*count += ft_putchar(' ');
		return ;
	}
	else
	{
		while (--mod->width)
			*count += ft_putchar(' ');
		*count += ft_putchar(chr);
		return ;
	}
}

void	ft_print_arg(t_mod *mod, va_list args, int *count)
{
	char	*output;

	output = ft_calloc(1, sizeof(char));
	if (mod->specifier == '%')
		output = ft_str_append("%", output);
	if (mod->specifier == 'c')
		return (ft_print_chr(va_arg(args, int), mod, count, output));
	if (mod->specifier == 's')
		output = ft_str_append(va_arg(args, char *), output);
	if (mod->specifier == 'd' || mod->specifier == 'i' || mod->specifier == 'u'\
	|| mod->specifier == 'x' || mod->specifier == 'X' || mod->specifier == 'p')
		output = ft_get_num(mod, args, output);
	if (output == NULL)
		output = ft_strdup("(null)");
	output = ft_format(mod, output);
	ft_putstr_fd(output, 1);
	*count += ft_strlen(output);
	free(output);
	return ;
}
