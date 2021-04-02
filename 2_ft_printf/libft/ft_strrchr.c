/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:46:12 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/21 21:32:51 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *start;

	start = (char *)s;
	while (*s)
		s++;
	s++;
	while (--s != start)
	{
		if (*s == c)
			return ((char *)s);
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
