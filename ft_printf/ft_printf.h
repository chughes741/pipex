/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:22:14 by chughes           #+#    #+#             */
/*   Updated: 2022/04/17 15:22:25 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct t_mod_list
{
	unsigned int	dash : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	hash : 1;
	unsigned int	zero : 1;
	int				width;
	int				precision;
	char			specifier;
}					t_mod;

int			ft_printf(const char *form, ...);
t_mod		*ft_get_mods(char *format);
void		ft_print_arg(t_mod *mods, va_list args, int *count);
char		*ft_itox(int nbr);
char		*ft_utoa(unsigned int nbr);
char		*ft_ptoa(uintptr_t nbr);
char		*ft_str_append(char *s1, char *s2);
char		*ft_format(t_mod *mod, char *str);

#endif
