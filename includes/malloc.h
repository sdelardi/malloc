/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 09:12:07 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/06 11:53:25 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include "libft.h"
# include <sys/mman.h>

typedef struct		s_tiny
{
	char			*data;
	int				size;
	int				mem_left;
	struct s_tiny	*next;
	struct s_tiny	*prev;
}					t_tiny;

typedef struct		s_small
{
	char			*data;
	int				size;
	int				mem_left;
	struct s_small	*next;
	struct s_small	*prev;
}					t_small;

typedef struct		s_large
{
	char			*data;
	size_t			size;
	struct s_large	*next;
	struct s_large	*prev;
}					t_large;

typedef struct		s_alloc
{
	char			*data;
	size_t			size;
	struct s_alloc	*next;
	struct s_alloc	*prev;
}					t_alloc;

typedef struct		s_manage
{
	t_large			*lhead;
	t_large			*ltail;
	t_tiny			*thead;
	t_tiny			*ttail;
	t_small			*shead;
	t_small			*stail;
	t_alloc			*ahead;
	t_alloc			*atail;
}					t_manage;

t_manage			g_a;

int					main(void);
void				ft_free(void *ptr);
void				*ft_malloc(size_t size);
void				*ft_realloc(void *ptrm, size_t size);
/*
**Large functions
*/
void				*map_large(size_t size);
void				*new_large(int i, size_t size);
/*
**Tiny functions
*/
void				*new_tiny_zone(char mode);
int					is_first_tiny(void);
void				*map_tiny(size_t size);
/*
**Alloc functions
*/
void				new_alloc_t(size_t size);
#endif
