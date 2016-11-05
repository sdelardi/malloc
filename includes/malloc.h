/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 09:12:07 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/05 12:45:16 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdio.h>
# include "libft.h"
# include <sys/mman.h>

size_t g_n;
size_t g_nn;
size_t g_m;
size_t g_mm;

typedef struct		s_tiny
{
	int				number;
	char			**data;
	int				size;
	struct s_tiny 	*next;
	struct s_tiny 	*prev;
}					t_tiny;

typedef struct		s_small
{
	int				number;
	char			*data;
	int				size;
	struct s_small	*next;
	struct s_small	*prev;
}					t_small;

typedef struct		s_large
{
	int				number;
	char			**data;
	size_t			size;
	struct s_large	*next;
	struct s_large	*prev;
}					t_large;

int					main(void);
void				ft_free(void *ptr);
void				*ft_malloc(size_t size);
void				*ft_realloc(void *ptrm, size_t size);

#endif
