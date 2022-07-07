/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:57:54 by chughes           #+#    #+#             */
/*   Updated: 2022/05/20 09:57:58 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_max_width(char *str, int precision)
{
	char	*rtn;

	if (ft_strlen(str) <= (unsigned long)precision)
		return (str);
	rtn = ft_calloc(precision + 1, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, str, precision + 1);
	free(str);
	return (rtn);
}

char	*ft_format_str(char *str, t_mod *mod)
{
	if (mod->precision >= 0 && ft_strlen(str) > (unsigned long)mod->precision)
		str = ft_max_width(str, mod->precision);
	if (mod->width >= 0 && ft_strlen(str) < (unsigned long)mod->width)
		str = ft_min_width(str, mod->width, mod->zero);
	if (mod->dash)
		ft_left_justify(str);
	return (str);
}
