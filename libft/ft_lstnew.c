/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:48:17 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/26 17:43:38 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;
	size_t new_size;

	new_size = content_size;
	new = (t_list *)malloc(sizeof(size_t) * content_size);
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (new->content != NULL)
		{
			new->content = ft_memcpy(new->content, content, content_size);
			new->content_size = new_size;
			new->next = NULL;
		}
	}
	new->next = NULL;
	return (new);
}
