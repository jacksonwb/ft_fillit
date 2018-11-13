/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:47:42 by jbeall            #+#    #+#             */
/*   Updated: 2018/10/30 11:04:53 by jbeall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!alst || !*alst)
		return ;
	temp = *alst;
	while (temp)
	{
		del(temp->content, temp->content_size);
		*alst = temp->next;
		free(temp);
		temp = *alst;
	}
}
