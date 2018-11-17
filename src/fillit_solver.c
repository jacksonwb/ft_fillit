/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackson <jackson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:41:40 by jbeall            #+#    #+#             */
/*   Updated: 2018/11/16 15:19:26 by jackson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		spot_check(t_tetrim *elem, t_16 *map)
{
	return (!((elem->val >> elem->x) & *(t_64*)(map + elem->y)));
}

void	toggle(t_64 val, int x, int y, t_16 *map)
{
	*(t_64*)(map + y) ^= val >> x;
}

char	**grid_builder(t_tetrim **ar, unsigned int size, unsigned int pieces)
{
	char			**grid;
	t_64			l;
	t_iterator		obj;

	ft_bzero(&obj, sizeof(obj));
	l = 1;
	grid = grid_initialize(size);
	while (obj.i < pieces)
	{
		while (obj.j < ar[obj.i]->h)
		{
			while (obj.k < ar[obj.i]->w)
			{
				if (((l << (16 * obj.j)) << (15 - obj.k)) & ar[obj.i]->val)
					grid[ar[obj.i]->y + obj.j][ar[obj.i]->x + obj.k] =
						ar[obj.i]->id;
				++obj.k;
			}
			++obj.j;
			obj.k = 0;
		}
		++obj.i;
		obj.j = 0;
	}
	return (grid);
}

int		r_solver(t_tetrim **ar, t_16 *map, t_state *state, int i)
{
	while ((ar[i])->y + ar[i]->h <= state->size)
	{
		while (ar[i]->x + ar[i]->w <= state->size)
		{
			if (spot_check(ar[i], map))
			{
				toggle(ar[i]->val, ar[i]->x, ar[i]->y, map);
				if (ar[i + 1])
					r_solver(ar, map, state, i + 1);
				else
				{
					printer(grid_builder(ar, state->size,
						state->pieces), state->size);
					exit(0);
				}
				toggle(ar[i]->val, ar[i]->x, ar[i]->y, map);
			}
			++ar[i]->x;
		}
		++ar[i]->y;
		ar[i]->x = 0;
	}
	ar[i]->y = 0;
	return (0);
}

void	solver(t_tetrim **ar, t_16 *map)
{
	t_state state;

	ft_bzero(&state, sizeof(state));
	while (ar[state.pieces])
		++state.pieces;
	while (state.size * state.size < 4 * state.pieces)
		++state.size;
	while (state.size <= 16)
	{
		r_solver(ar, map, &state, 0);
		++state.size;
	}
}
