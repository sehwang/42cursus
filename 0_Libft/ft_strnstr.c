/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:33:07 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/25 22:18:10 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*ndle;
	size_t	ndle_len;

	if (*needle == '\0')
		return ((char*)haystack);
	ndle_len = ft_strlen(needle);
	while (*haystack && len-- >= ndle_len)
	{
		if (*haystack == *needle)
		{
			hay = (char *)haystack;
			ndle = (char *)needle;
			while (*hay++ == *ndle++)
			{
				if (*ndle == '\0')
					return ((char *)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
