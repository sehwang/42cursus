/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:55:12 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/25 21:32:40 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;

	if (dest == src || n == 0)
		return (dest);
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*dst++ = *sr++;
	}
	else
	{
		dst += n;
		sr += n;
		while (n--)
			*--dst = *--sr;
	}
	return (dest);
}
