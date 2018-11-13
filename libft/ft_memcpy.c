/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:32:52 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 20:36:21 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		d[i] = *((unsigned char*)src + i);
		i++;
	}
	return (dst);
}
