/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:42:27 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 09:59:16 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char*)dst;
	s = (char*)src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		while (len > 0)
		{
			*(d + len - 1) = *(s + len - 1);
			len--;
		}
	return (dst);
}
