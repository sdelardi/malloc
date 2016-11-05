/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:25:40 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/26 17:42:35 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *current;
	t_list *tmp;

	if (lst)
	{
		begin = ft_lstnew(lst->content, lst->content_size);
		begin = f(lst);
		lst = lst->next;
	}
	current = begin;
	while (lst)
	{
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		tmp = f(lst);
		current->next = tmp;
		current = tmp;
		lst = lst->next;
	}
	return (begin);
}
