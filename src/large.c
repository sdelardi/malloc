/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:21:09 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/06 11:44:28 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*new_large(int i, size_t size)
{
	t_large *zone;

	zone = (void *)mmap(0, sizeof(t_large) + 1, PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)mmap(0, size + 1, PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->size = size;
	zone->next = NULL;
	zone->prev = (i == 0) ? NULL : g_a.lhead;
	return (zone);
}

void	*map_large(size_t size)
{
	t_large		*zone;
	t_large		*start;
	int			i;

	start = g_a.ltail;
	i = 0;
	while (start != NULL)
	{
		start = start->next;
		i++;
	}
	zone = new_large(i, size);
	if (i == 0)
	{
		g_a.lhead = zone;
		g_a.ltail = zone;
	}
	else
	{
		g_a.lhead->next = zone;
		g_a.lhead = g_a.lhead->next;
	}
	return (zone->data);
}
