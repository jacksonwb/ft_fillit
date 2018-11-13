/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:51:37 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 20:37:35 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	i = 0;
	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (dstsize <= dstl)
		return (dstsize + srcl);
	while ((i < dstsize - dstl - 1) && src[i])
	{
		dst[i + dstl] = src[i];
		++i;
	}
	dst[i + dstl] = '\0';
	return (dstl + srcl);
}
