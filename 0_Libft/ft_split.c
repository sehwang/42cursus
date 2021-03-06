/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:16:12 by sehwang           #+#    #+#             */
/*   Updated: 2020/12/04 22:23:19 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cnt_strs(char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s)
			s++;
	}
	return (n);
}

char		**ft_split(char const *s, char c)
{
	char	**rtn;
	char	*sptr;
	size_t	i;

	if (!(rtn = (char**)malloc(sizeof(char*) *
		(ft_cnt_strs((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			sptr = (char *)s;
			while (*s != c && *s != '\0')
				s++;
			if (!(rtn[i] = (char*)malloc(sizeof(char) * (s - sptr + 1))))
				return (NULL);
			ft_strlcpy(rtn[i], sptr, s - sptr + 1);
			i++;
		}
		if (*s)
			s++;
	}
	rtn[i] = NULL;
	return (rtn);
}
