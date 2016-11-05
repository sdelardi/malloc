/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 08:59:53 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/05 13:39:41 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t g_n;
size_t g_nn;
size_t g_m;
size_t g_mm;
t_large *g_lhead;
t_large *g_ltail;

static void *map_large(size_t size)
{
	t_large *zone;
	t_large *start;
	int i;

	start = g_ltail;
	zone = (void *)mmap(0, sizeof(t_large) + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	i = 0;
	while (start != NULL)
	{
		start = start->next;
		i++;
	}
	zone->number = i;
	zone->data = (void *)mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->size = size;
	zone->next = NULL;
	zone->prev = (i == 0) ? NULL : g_lhead;
	if (i == 0)
	{
		g_lhead = zone;
		g_ltail = zone;
	}
	else
	{
		g_lhead->next = zone;
		g_lhead = g_lhead->next;
	}
	return zone->data;
}

void		ft_free(void *ptr)
{
	ptr = NULL;
}

void		*ft_malloc(size_t size)
{
	void	*ptr;
	ptr = NULL;
	if (size <= 0)
		printf("Are you kiddin me ?\n");
	else if (size <= g_n)
		printf("TINY\n");
	else if (size > g_n && size <= g_m)
		printf("SMALL\n");
	else if (size > g_m)
		ptr = map_large(size);
	return (ptr);
}

void		*ft_realloc(void *ptrm, size_t size)
{	
	ptrm = NULL;
	size = 0;
	return (NULL);
}

static void	ft_show_alloc_mem(void)
{
	t_large *start;

	start = g_ltail;
	while (start)
	{
		printf("LARGE : %p\n", start);
		printf("%p", start->data);
		start->data += start->size;
		printf(" - %p", start->data);
		printf(" : %zu octets\n", start->size);
		start = start->next;
	}
}

int			main(void)
{
	char 	*ptr1;
	char 	*ptr2;
	char 	*ptr3;
	int		i;

	g_n = getpagesize() / 16;
	g_nn = getpagesize() * 7;
	g_m = getpagesize() / 2;
	g_mm = getpagesize() * 51;

	i = 0;
	ptr1 = (char *)ft_malloc(sizeof(char) * 5001);
	while (i < 5000)
	{
		ptr1[i] = 'x';
		i++;
	}
	ptr1[i] = '\0';
	printf("Str1 : %s\n", ptr1);
	i = 0;
	ptr2 = (char *)ft_malloc(sizeof(char) * 5001);
	while (i < 5000)
	{
		ptr2[i] = 'c';
		i++;
	}
	ptr2[i] = '\0';
	printf("Str2 : %s\n", ptr2);
	i = 0;
	ptr3 = (char *)ft_malloc(sizeof(char) * 5001);
	while (i < 5000)
	{
		ptr3[i] = 'v';
		i++;
	}
	ptr3[i] = '\0';
	printf("Str3 : %s\n", ptr3);
	ft_show_alloc_mem();
	munmap(ptr1, 5001);
	munmap(ptr2, 5001);
	munmap(ptr3, 5001);
	if (g_ltail && !g_ltail->next)
	{
		munmap(g_ltail, sizeof(t_large));
		return (0);
	}
	else if (!g_ltail)
		return (0);
	else
	{
		while(g_ltail)
		{
			if (g_ltail->next == NULL)
			{
				munmap(g_ltail, sizeof(t_large) + 1);
				return (0);
			}
			else
			{
				g_ltail = g_ltail->next;
				munmap(g_ltail->prev, sizeof(t_large) + 1);
			}
		}
	}
	return (0);
}
