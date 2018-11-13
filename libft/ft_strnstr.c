/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:05:15 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 20:40:06 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needlel;
	size_t	k;

	k = 0;
	i = 0;
	j = 0;
	if (!(needlel = ft_strlen(needle)))
		return ((char*)haystack);
	while (*haystack)
	{
		while (needle[j] == haystack[i] && (k + j) < len)
		{
			if ((j + 1) == needlel)
				return ((char*)haystack);
			++i;
			++j;
		}
		j = 0;
		i = 0;
		++haystack;
		++k;
	}
	return (NULL);
}
