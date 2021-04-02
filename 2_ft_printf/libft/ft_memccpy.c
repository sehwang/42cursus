/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:57:45 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/21 16:07:17 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	dst = dest;
	sr = (unsigned char *)src;
	while (i++ < n)
	{
		if (*sr == (unsigned char)c)
		{
			*dst++ = *sr++;
			return (dst);
		}
		*dst++ = *sr++;
	}
	return (NULL);
}
