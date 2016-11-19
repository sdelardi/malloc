/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:07:22 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 19:29:26 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	swap_large(t_large **start, t_large **prev, t_large **next,
		t_large **second)
{
	*prev = (*start)->prev;
	*next = (*start)->next;
	*second = (*next)->next;
	if (*prev)
		(*prev)->next = *next;
	else
		g_a.ltail = *next;
	if (*second)
		(*second)->prev = *start;
	else
		g_a.lhead = *start;
	(*start)->prev = *next;
	(*start)->next = *second;
	(*next)->prev = *prev;
	(*next)->next = *start;
}

void		sort_large(void)
{
	t_large *start;
	t_large *prev;
	t_large *next;
	t_large *second;
	int		sort;

	sort = 1;
	start = g_a.ltail;
	while (sort)
	{
		sort = 0;
		while (start)
		{
			if (start->next != NULL && start->next < start)
			{
				sort = 1;
				swap_large(&start, &prev, &next, &second);
			}
			start = start->next;
		}
	}
}
