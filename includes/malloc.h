/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 09:12:07 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 11:07:06 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include <sys/mman.h>
# include <inttypes.h>
# include "libftprintf.h"

typedef struct		s_alloc
{
	char			*data;
	char			is_empty;
	size_t			size;
}					t_alloc;

typedef struct		s_tiny
{
	size_t			size;
	size_t			mem_left;
	struct s_tiny	*next;
	struct s_tiny	*prev;
	struct s_alloc	alloc[256];
	char			*data;
}					t_tiny;

typedef struct		s_small
{
	size_t			size;
	size_t			mem_left;
	struct s_small	*next;
	struct s_small	*prev;
	struct s_alloc	alloc[256];
	char			*data;

}					t_small;

typedef struct		s_large
{
	char			*data;
	size_t			size;
	struct s_large	*next;
	struct s_large	*prev;
}					t_large;

typedef struct		s_sort
{
	t_tiny			*tiny;
	t_small			*small;
	t_large			*large;
	void			*addr;
	size_t			size;
	void			*data;
	int				type;
	struct s_sort	*next;
	struct s_sort	*prev;
}					t_sort;

typedef struct		s_manage
{
	t_large			*lhead;
	t_large			*ltail;
	t_tiny			*thead;
	t_tiny			*ttail;
	t_small			*shead;
	t_small			*stail;
	t_sort			*sohead;
	t_sort			*sotail;
}					t_manage;

t_manage			g_a;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptrm, size_t size);
/*
**Large functions
*/
void				*map_large(size_t size);
void				*new_large(int i, size_t size);
/*
**Small functions
*/
void				*new_small_zone(char mode);
void				*map_small(size_t size);
/*
**Tiny functions
*/
void				*new_tiny_zone(char mode);
void				*map_tiny(size_t size);
/*
**Alloc functions
*/
void				*new_alloc_t(size_t size, t_tiny *zone);
void				*new_alloc_s(size_t size, t_small *zone);
/*
**Free functions
*/
void				del_large(void *ptr);
void				del_alloc(void *ptr);
int					is_alloc(void *ptr, int *mode);
int					search_alloc(void *begin, void *end, void *exception);
void				del_segment_tiny(void *ptr);
void				del_segment_small(void *ptr);
/*
**Show functions
*/
void				show_alloc_mem(void);
void				show_alloc_t(t_tiny *zone, size_t size);
void				show_alloc_s(t_small *zone, size_t size);
/*
**Realloc functions
*/
void				*stretch(void *ptr, size_t old, size_t size);
int					not_enough_size(void *ptr, size_t old, size_t size);
int					not_same_part(size_t old_size, size_t size);
size_t				find_size(void *ptr);
/*
**Find functions
*/
void				*copy_datas(void *ptr, size_t old, void *new, size_t size);
t_alloc				*find_alloc(void *ptr);
t_small				*find_small(void *ptr);
t_tiny				*find_tiny(void *ptr);
t_large				*find_large(void *ptr);
/*
**Sort functions
*/
void				sort_alloc(void);
void				new_sort(void *data, size_t size, void *alloc, int type);
void				end_sort(void);
void				sort_sort(void);
/*
**Aux functions
*/
void				aux_small(t_small **new, char mode);
void				aux_tiny(t_tiny **new, char mode);
void				init_tiny(t_tiny **new);
void				init_small(t_small **new);
void				del_large(void *ptr);
void				aux_sort(t_sort **sort);
#endif
