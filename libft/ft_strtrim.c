/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:58:35 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 20:51:24 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	i;
	char	*n;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		--end;
	if (end < i)
		end = i;
	if (!(n = ft_memalloc(end - i + 1)))
		return (NULL);
	return (ft_strncpy(n, (s + i), end - i));
}
