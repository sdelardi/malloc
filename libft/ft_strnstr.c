/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:08:43 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/25 14:24:20 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int h;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	j = 0;
	h = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s2[j] == s1[i] && s2[j + 1] == '\0')
			return (char *)&s1[i - j];
		h = (s1[i] == s2[0]) ? i : h;
		if (s2[j] == s1[i])
			j++;
		else if (h > 0)
		{
			i = h;
			j = 1;
			h = 0;
		}
		i++;
	}
	return (NULL);
}
