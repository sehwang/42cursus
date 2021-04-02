/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:20:38 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/20 14:04:31 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtn;

	rtn = malloc(nmemb * size);
	if (!rtn)
		return (NULL);
	ft_memset(rtn, 0, nmemb * size);
	return (rtn);
}
