/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:31:38 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 15:27:30 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	del_large(void *ptr)
{
	t_large *start;

	start = g_a.ltail;
	while (start)
	{
		if (start->data == ptr)
		{
			if (start->prev)
				start->prev->next = start->next;
			else
				g_a.ltail = start->next;
			if (start->next)
				start->next->prev = start->prev;
			else
				g_a.lhead = start->prev;
			start->prev = NULL;
			start->next = NULL;
			munmap(ptr, start->size);
			munmap(start, sizeof(t_large));
			start = NULL;
			return ;
		}
		start = start->next;
	}
}

void	del_alloc(void *ptr)
{
	t_alloc *start;

	start = g_a.atail;
	while (start)
	{
		if (start->data == ptr)
		{
			if (start->prev)
				start->prev->next = start->next;
			else
				g_a.atail = start->next;
			if (start->next)
				start->next->prev = start->prev;
			else
				g_a.ahead = start->prev;
			start->prev = NULL;
			start->next = NULL;
			munmap(ptr, start->size);
			munmap(start, sizeof(t_alloc));
			start = NULL;
			return ;
		}
	}
}

int		is_alloc(void *ptr, int *mode)
{
	t_alloc *alloc;
	t_large *large;

	alloc = g_a.atail;
	while (alloc)
	{
		if (ptr == alloc->data)
		{
			if (alloc->size <= (size_t)((getpagesize() / 16)))
				*mode = 1;
			else
				*mode = 2;
			return (1);
		}
		alloc = alloc->next;
	}
	large = g_a.ltail;
	while (large)
	{
		if (ptr == large->data)
			return (1);
		large = large->next;
	}
	return (0);
}

void	ft_free(void *ptr)
{
	int mode;

	mode = 0;
	if (is_alloc(ptr, &mode))
	{
		if (mode == 1 || mode == 2)
			del_alloc(ptr);
		else
			del_large(ptr);
		ptr = NULL;
	}
	return ;
}
