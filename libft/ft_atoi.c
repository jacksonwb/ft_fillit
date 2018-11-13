/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:59:26 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 11:03:34 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	val;
	int	neg;

	neg = 0;
	val = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		neg = 1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		val *= 10;
		val -= *str++ - '0';
	}
	if (!neg)
		val *= -1;
	return (val);
}
