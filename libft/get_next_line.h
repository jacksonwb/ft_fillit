/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:36:20 by jbeall            #+#    #+#             */
/*   Updated: 2018/11/06 20:38:13 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 20
# define NULL_CHECK(call) if (!call) return (NULL)

typedef struct	s_thread
{
	int			fd;
	char		**cache;
}				t_thread;

int				get_next_line(const int fd, char **line);

#endif
