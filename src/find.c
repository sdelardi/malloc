/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:47:06 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 08:49:30 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*copy_datas(void *ptr, size_t old, void *new, size_t size)
{
	size_t	i;
	char	*str;
	char	*strnew;

	i = 0;
	str = (char *)ptr;
	strnew = (char *)new;
	while (i < old && i < size)
	{
		strnew[i] = str[i];
		i++;
	}
	return (void *)(strnew);
}

t_alloc	*find_alloc(void *ptr)
{
	int		i;
	t_tiny	*tiny;
	t_small	*small;

	tiny = g_a.ttail;
	while (tiny)
	{
		i = -1;
		while (++i < 256)
			if (ptr == (tiny->alloc)[i].data
			&& (tiny->alloc)[i].is_empty == 0)
				return (&((tiny->alloc)[i]));
		tiny = tiny->next;
	}
	small = g_a.stail;
	while (small)
	{
		i = -1;
		while (++i < 256)
			if (ptr == (small->alloc)[i].data
			&& (small->alloc)[i].is_empty == 0)
				return (&((small->alloc)[i]));
		small = small->next;
	}
	return (NULL);
}

t_small	*find_small(void *ptr)
{
	t_small *small;

	small = g_a.stail;
	while (small)
	{
		if (ptr >= (void *)small->data
		&& ptr <= (void *)(small->data + small->size))
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
		if (ptr >= (void *)tiny->data
		&& ptr <= (void *)(tiny->data + tiny->size))
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
