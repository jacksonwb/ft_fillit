/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:03:34 by jbeall            #+#    #+#             */
/*   Updated: 2018/11/13 12:58:50 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_64(t_64 n)
{
	int i;
	t_64 l;

	l = 1;
	l <<= 63;
	i = 0;
	while (i < 64)
	{
		if (n & l)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (i % 16 == 15)
			write(1, "\n", 1);
		n <<= 1;
		++i;
	}
}

void print_map(t_16* map)
{
	int i;
	int j;
	t_16 s;

	j = 15;
	i = 0;
	s = 1;
	while(i < 16)
	{
		while (j >= 0)
		{
			if (map[i] & s << j)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			--j;
		}
		write(1, "\n", 1);
		++i;
		j = 15;
	}
	write(1, "\n", 1);
}
