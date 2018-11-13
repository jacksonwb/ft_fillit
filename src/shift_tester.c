/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:22:37 by jbeall            #+#    #+#             */
/*   Updated: 2018/11/11 13:42:13 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int main()
{
	t_64 l = 1;
	char buf[21];
	int i = 0;
	t_64 test = 0;
	t_64 test2 = 0;
	unsigned int x_min = 0;
	unsigned int y_min = 0;

	ft_bzero(buf, sizeof(buf));
	buf[0] = '#';
	buf[1] = '#';
	buf[5] = '#';
	buf[6] = '#';

	char buf2[21];
	ft_bzero(buf2, sizeof(buf2));
	buf2[0] = '#';
	buf2[5] = '#';
	buf2[10] = '#';
	buf2[11] = '#';

	while (i < 18)
	{
		if (buf[i] == '#')
			test |= ((l << (16 * ((i / 5) - y_min))) << (15 - i % 5 + x_min));
		++i;
	}
	
	i = 0;
	while (i < 18)
	{
		if (buf2[i] == '#')
			test2 |= ((l << (16 * ((i / 5) - y_min))) << (15 - i % 5 + x_min));
		++i;
	}
	
	print_64(test);
	write(1, "\n", 1);
	print_64(test2);
	return (0);
}