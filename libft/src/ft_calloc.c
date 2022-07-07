/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:09:46 by chughes           #+#    #+#             */
/*   Updated: 2022/03/28 17:09:49 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*outptr;

	outptr = malloc(nitems * size);
	if (outptr == NULL)
		return (NULL);
	ft_bzero(outptr, (nitems * size));
	return (outptr);
}
