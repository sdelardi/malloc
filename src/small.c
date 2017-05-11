/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:46:14 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/11 11:50:46 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*new_alloc_s(size_t size, t_small *zone)
{
	void	*ptr;
	int		i;

	i = 0;
	while ((zone->alloc)[i].is_empty == 0 && i <= 250)
		i++;
	(zone->alloc)[i].is_empty = 0;
	(zone->alloc)[i].size = size;
	ptr = zone->data + (zone->size - zone->mem_left);
	zone->mem_left = (size < 16) ? zone->mem_left - 16 : zone->mem_left - size;
	return (ptr);
}

t_small		*new_small_zone(char mode)
{
	t_small	*zone;
	size_t	size;
	int		i;

	i = -1;
	size = getpagesize();
	zone = (void *)mmap(0, sizeof(char) * size + sizeof(t_small), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)(zone + sizeof(t_small));
	zone->size = size;
	zone->mem_left = size;
	zone->next = NULL;
	zone->prev = (mode == 0) ? NULL : g_a.shead;
	if (mode == 0)
	{
		g_a.shead = zone;
		g_a.stail = zone;
	}
	else
	{
		g_a.shead->next = zone;
		g_a.shead = g_a.shead->next;
	}
	while (++i <= 250)
	{
		(zone->alloc)[i].is_empty = 1;
		(zone->alloc)[i].size = 0;
	}
	return (zone);
}

t_small	*is_first_small(void)
{
	t_small	*start;

	start = g_a.stail;
	if (!start)
		return (NULL);
	while (start->next)
		start = start->next;
	return (start);
}

void	*map_small(size_t size)
{
	t_small	*zone;
	void	*ptr;

	zone = NULL;
	if ((zone = is_first_small()) == NULL)
	{
		zone = new_small_zone(0);
		ptr = new_alloc_s(size, zone);
	}
	else
		ptr = new_alloc_s(size, zone);
	return (ptr);
}
