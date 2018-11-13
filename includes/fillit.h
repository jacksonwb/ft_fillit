/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:17:36 by jbeall            #+#    #+#             */
/*   Updated: 2018/11/12 13:28:46 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef unsigned long long int	t_64;
typedef unsigned short int		t_16;

typedef struct					s_tetrim
{
	uint64_t		val;
	char			id;
	unsigned int	w;
	unsigned int	h;
	unsigned int	x;
	unsigned int	y;
}								t_tetrim;

typedef struct					s_state
{
	unsigned int	size;
	unsigned int	pieces;
	unsigned int	i;
}								t_state;

typedef struct					s_iterator
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
}								t_iterator;

int								check_count(char *buf);
int								check_format(char *buf);
int								check_connect(char *buf);
void							min_maxer(char *buf, int *mx);
t_tetrim						*structify(char *buf);
int								spot_check(t_tetrim *elem, t_16 *map);
void							toggle(uint64_t val, int x, int y,
									uint16_t *map);
char							**grid_builder(t_tetrim **ar, unsigned int size,
									unsigned int pieces);
char							**grid_initialize(unsigned int size);
int								r_solver(t_tetrim **ar, t_16 *map,
									t_state *state, int i);
void							solver(t_tetrim **ar, t_16 *map);
void							printer(char **grid, unsigned int size);

#endif
