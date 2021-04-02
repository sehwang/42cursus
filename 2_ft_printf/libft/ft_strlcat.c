/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:31:20 by sehwang           #+#    #+#             */
/*   Updated: 2020/12/05 20:37:15 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t s_len;
	size_t d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (d_len > dstsize)
		return (s_len + dstsize);
	while (*dst != '\0')
		dst++;
	i = d_len + 1;
	while (i++ < dstsize && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (s_len + d_len);
}
