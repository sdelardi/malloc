/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:47:06 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 18:36:37 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*copy_datas(void *ptr, size_t old, void *new)
{
	size_t	i;
	char	*str;
	char	*strnew;

	i = 0;
	str = (char *)ptr;
	strnew = (char *)new;
	while (i < old)
	{
		strnew[i] = str[i];
		i++;
	}
	return (void *)(strnew);
}

t_alloc	*find_alloc(void *ptr)
{
	t_alloc *alloc;

	alloc = g_a.atail;
	while (alloc)
	{
		if (ptr == alloc->data)
			return (alloc);
		alloc = alloc->next;
	}
	return (NULL);
}

t_small	*find_small(void *ptr)
{
	t_small *small;

	small = g_a.stail;
	while (small)
	{
		if (ptr == small->data + small->size)
			return (small);
		small = small->next;
	}
	return (NULL);
}

t_tiny	*find_tiny(void *ptr)
{
	t_tiny *tiny;

	tiny = g_a.ttail;
	while (tiny)
	{
		if (ptr == tiny->data + tiny->size)
			return (tiny);
		tiny = tiny->next;
	}
	return (NULL);
}

t_large	*find_large(void *ptr)
{
	t_large *large;

	large = g_a.ltail;
	while (large)
	{
		if (ptr == large->data)
			return (large);
		large = large->next;
	}
	return (NULL);
}
