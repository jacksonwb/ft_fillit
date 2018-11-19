/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackson <jbeall@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:08:13 by jbeall            #+#    #+#             */
/*   Updated: 2018/11/18 20:24:55 by jackson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** This function checks that the piece in the buffer has the correct number of sharps and dots
*/

int			check_count(char *buf)
{
	int	i;
	int	space;
	int	sharp;

	i = 0;
	space = 0;
	sharp = 0;
	while (i < 20)
	{
		if (buf[i] == '.')
			++space;
		else if (buf[i] == '#')
			++sharp;
		++i;
	}
	if ((sharp == 4) && (space == 12))
		return (1);
	else
		return (0);
}

/*
** This function checks to see if the bufferized piece has the correct layout format
*/

int			check_format(char *buf)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (buf[i] != '\n')
				return (0);
		}
		else if (!(buf[i] == '.' || buf[i] == '#'))
			return (0);
		++i;
	}
	if (!(buf[20] == '\n' || buf[20] == '\0'))
		return (0);
	return (1);
}

/*
** This function checks if the piece has a valid tetris shape
*/

int			check_connect(char *buf)
{
	int	i;
	int	connects;

	i = 0;
	connects = 0;
	while (i <= 18)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < 3)
				if (buf[i + 1] == '#')
					++connects;
			if (i % 5 > 0)
				if (buf[i - 1] == '#')
					++connects;
			if (i / 5 < 3)
				if (buf[i + 5] == '#')
					++connects;
			if (i / 5 > 0)
				if (buf[i - 5] == '#')
					++connects;
		}
		++i;
	}
	return (connects == 6 || connects == 8);
}

/*
** This funtion finds the mix and max locations of each piece within its grid
*/

void		min_maxer(char *buf, int *mx)
{
	int	i;

	i = 0;
	mx[0] = 3;
	mx[1] = 0;
	mx[2] = 3;
	mx[3] = 0;
	while (i <= 18)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < mx[0])
				mx[0] = i % 5;
			if (i % 5 > mx[1])
				mx[1] = i % 5;
			if (i / 5 < mx[2])
				mx[2] = i / 5;
			if (i / 5 > mx[3])
				mx[3] = i / 5;
		}
		++i;
	}
}

/*
** This function converts the piece in a struct element and represents the piece in a t_64 type integar bitfield
*/

t_tetrim	*structify(char *buf)
{
	t_tetrim	*new;
	int			mx[4];
	int			i;
	t_64		l;

	l = 1;
	i = 0;
	if (!(new = (t_tetrim*)malloc(sizeof(t_tetrim))))
		return (NULL);
	ft_bzero(new, sizeof(t_tetrim));
	min_maxer(buf, mx);
	new->w = mx[1] - mx[0] + 1;
	new->h = mx[3] - mx[2] + 1;
	while (i < 19)
	{
		if (buf[i] == '#')
			new->val |= ((l << (16 * ((i / 5) - mx[2])))
				<< (15 - i % 5 + mx[0]));
		++i;
	}
	return (new);
}
