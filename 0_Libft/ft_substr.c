/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 00:12:25 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/28 15:49:03 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*rtn;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rtn = sub;
	while (start-- > 0)
		s++;
	while (*s)
	{
		if (len-- <= 0)
			break ;
		*sub++ = *s++;
	}
	*sub = '\0';
	return (rtn);
}
