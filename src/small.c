/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 07:26:17 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 09:23:51 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*new_alloc_s(size_t size, t_small *zone)
{
	void	*ptr;
	int		i;

	i = 0;
	while ((zone->alloc)[i].data != NULL && i <= 250)
	{
		if ((zone->alloc)[i].is_empty == 1 && size <= (zone->alloc)[i].size)
		{
			(zone->alloc)[i].is_empty = 0;
			(zone->alloc)[i].size = size;
			ptr = (zone->alloc)[i].data;
			return (ptr);
		}
		i++;
	}
	(zone->alloc)[i].is_empty = 0;
	(zone->alloc)[i].size = size;
	if (zone->size == zone->mem_left)
		(zone->alloc)[i].data = zone->data;
	else
		(zone->alloc)[i].data = zone->data + (zone->size - zone->mem_left) + 1;
	ptr = (zone->alloc)[i].data;
	zone->mem_left = zone->mem_left - (size + 1);
	return (ptr);
}

void	*new_small_zone(char mode)
{
	t_small	*zone;
	size_t	size;

	size = getpagesize() * 100;
	zone = (void *)mmap(0, sizeof(char) * size + sizeof(t_small), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)zone + sizeof(t_small);
	zone->size = size;
	zone->mem_left = size;
	zone->next = NULL;
	zone->prev = (mode == 0) ? NULL : g_a.shead;
	aux_small(&zone, mode);
	return (zone);
}

int		is_full_s(t_small *zone, size_t size)
{
	int i;

	i = 0;
	if (zone->mem_left < size)
		return (1);
	while ((zone->alloc)[i].data != NULL)
		i++;
	if (i == 251)
		return (1);
	return (0);
}

void	*map_small(size_t size)
{
	t_small	*zone;
	void	*ptr;

	zone = g_a.shead;
	if (zone == NULL)
	{
		zone = new_small_zone(0);
		ptr = new_alloc_s(size, zone);
	}
	else if (is_full_s(zone, size))
	{
		zone = new_small_zone(1);
		ptr = new_alloc_s(size, zone);
	}
	else
		ptr = new_alloc_s(size, zone);
	return (ptr);
}
