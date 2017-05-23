/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:26:45 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 11:16:42 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	show_alloc_t(t_tiny *zone, size_t size)
{
	int		i;

	i = 0;
	ft_printf("TINY : %p\n", zone);
	while (i < 256)
	{
		if ((zone->alloc)[i].data >= zone->data && (zone->alloc)[i].data <
		zone->data + size && (zone->alloc)[i].is_empty == 0)
		{
			ft_printf("%p", (zone->alloc)[i].data);
			ft_printf(" - %p", (zone->alloc)[i].data + (zone->alloc)[i].size);
			ft_printf(" : %zu octets\n", (zone->alloc)[i].size);
		}
		i++;
	}
}

void	show_alloc_s(t_small *zone, size_t size)
{
	int		i;

	i = 0;
	ft_printf("SMALL : %p\n", zone);
	while (i < 256)
	{
		if ((zone->alloc)[i].data >= zone->data && (zone->alloc)[i].data <
		zone->data + size && (zone->alloc)[i].is_empty == 0)
		{
			ft_printf("%p", (zone->alloc)[i].data);
			ft_printf(" - %p", (zone->alloc)[i].data + (zone->alloc)[i].size);
			ft_printf(" : %zu octets\n", (zone->alloc)[i].size);
		}
		i++;
	}
}

void	show_alloc_mem(void)
{
	t_sort	*start;

	sort_alloc();
	start = g_a.sotail;
	while (start)
	{
		if (start->type == 1)
		{
			ft_printf("LARGE : %p\n", (t_large *)(start->large));
			ft_printf("%p", (t_large *)(start->large)->data);
			ft_printf(" - %p", (t_large *)(start->large)->data + start->size);
			ft_printf(" : %zu octets\n", start->size);
		}
		else if (start->type == 2 && start->size == (size_t)getpagesize() * 5)
		{
			show_alloc_t((t_tiny *)(start->tiny), start->size);
		}
		else if (start->type == 3 && start->size == (size_t)getpagesize() * 100)
		{
			show_alloc_s((t_small *)(start->small), start->size);
		}
		start = start->next;
	}
	end_sort();
}
