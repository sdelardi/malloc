/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:23:31 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/06 11:48:21 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void    *new_tiny_zone(char mode)
{
	t_tiny *zone;
	size_t	size;

	size = getpagesize() * 7;
	zone = (void *)mmap(0, sizeof(t_tiny), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)mmap(0, size, PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->size = size;
	zone->mem_left = size;
	zone->next = NULL;
	zone->prev = (mode == 0) ? NULL : g_a.thead;
	if (mode == 0)
	{
		g_a.thead = zone;
		g_a.ttail = zone;
	}
	else
	{
		g_a.thead->next = zone;
		g_a.thead = g_a.thead->next;
	}
	return (zone);
}

int		is_first_tiny(void)
{
	int		i;
	t_tiny	*start;

	start = g_a.ttail;
	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

void	*map_tiny(size_t size)
{
	t_tiny	*zone;
	t_alloc	*alloc;

	zone = NULL;
	alloc = NULL;
	if (is_first_tiny())
	{
		zone = new_tiny_zone(0);
		new_alloc_t(size);
	}
	else
		new_alloc_t(size);
}
