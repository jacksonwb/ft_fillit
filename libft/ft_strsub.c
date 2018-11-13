/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:04:42 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 10:35:27 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *d;

	if (!s)
		return (NULL);
	if (!(d = (char*)malloc(len + 1)))
		return (NULL);
	ft_strncpy(d, s + start, len);
	d[len] = '\0';
	return (d);
}
