/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:45:24 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 10:02:17 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int			i;
	int			count;
	const char	*s;

	s = src;
	count = 1;
	while (*s++)
		count++;
	i = 0;
	while (len)
	{
		if (i < count)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		++i;
		--len;
	}
	return (dst);
}
