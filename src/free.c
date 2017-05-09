/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:56 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/09 12:02:59 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:56 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/09 12:02:56 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:56 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/09 12:02:56 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:31:38 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/09 12:02:36 by sdelardi         ###   ########.fr       */
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
			printf("ERRL %d\n", munmap(ptr, start->size));
			munmap(start, sizeof(t_large));
			start = NULL;
			return ;
		}
		start = start->next;
	}
}

int		search_alloc(void *begin, void *end, void *exception)
{
	t_alloc *start;

	start = g_a.ahead;
	while (start)
	{
		if ((void *)start->data >= begin && (void *)start->data < end && start->data != exception)
		{
			printf("SEGMENT NOT EMPTY\n");
			return (1);
		}
		start = start->next;
	}
	return (0);
}

void	del_segment_tiny(void *ptr)
{
	t_tiny	*tiny;

	tiny = g_a.ttail;
	while (tiny)
	{
		if (ptr >= (void *)(tiny->data) && ptr < (void *)(tiny->data + tiny->size))
		{
			if (!search_alloc(tiny->data, tiny->data + tiny->size, ptr))
			{
				printf("ERRTINY %d\n", munmap(tiny->data, tiny->size));
				if (tiny->prev)
					tiny->prev->next = tiny->next;
				else
					g_a.ttail = tiny->next;
				if (tiny->next)
					tiny->next->prev = tiny->prev;
				else
					g_a.thead = tiny->prev;
				tiny->prev = NULL;
				tiny->next = NULL;
				printf("ZARBT %d\n", munmap(tiny, sizeof(t_tiny)));
				tiny = NULL;
			}
			break ;
		}
		tiny = tiny->next;
	}
}

void	del_segment_small(void *ptr)
{
	t_small *small;

	small = g_a.stail;
	while (small)
	{
		if (ptr >= (void *)small->data && ptr < (void *)small->data + small->size)
		{
			if (!search_alloc(small->data, small->data + small->size, ptr))
			{
				printf("ERRSMALL %d\n", munmap(small->data, small->size));
				if (small->prev)
					small->prev->next = small->next;
				else
					g_a.stail = small->next;
				if (small->next)
					small->next->prev = small->prev;
				else
					g_a.shead = small->prev;
				small->prev = NULL;
				small->next = NULL;
				printf("ZARBS %d\n", munmap(small, sizeof(t_small)));
				small = NULL;
			}
			break ;
		}
		small = small->next;
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
			if (start->size <= (size_t)(getpagesize() / 16))
				del_segment_tiny(ptr);
			else if (start->size <= (size_t)(getpagesize() / 2))
				del_segment_small(ptr);
			//printf("ERR %d\n", munmap(ptr, (start->size)));
			printf("ERRAL %d\n", munmap(start, sizeof(t_alloc)));
			start = NULL;
			return ;
		}
		start = start->next;
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
