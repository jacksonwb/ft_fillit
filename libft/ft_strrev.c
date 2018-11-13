/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:28:36 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 19:48:06 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		len;
	int		i;
	char	temp;

	i = 0;
	if (!s || !*s)
		return (NULL);
	len = (int)ft_strlen(s);
	while (i < len - 1)
	{
		temp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = temp;
		++i;
		--len;
	}
	return (s);
}
