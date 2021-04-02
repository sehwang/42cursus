/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:40:56 by sehwang           #+#    #+#             */
/*   Updated: 2020/12/05 18:46:32 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t s_len;

	s_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (s_len);
	while (i++ + 1 < dstsize && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (s_len);
}
