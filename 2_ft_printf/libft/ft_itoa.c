/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:29:55 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/28 21:03:34 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			d_len(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*rtn_itoa(char *rtn, int len, int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		rtn[len - i++ - 1] = n % 10 + '0';
		n /= 10;
	}
	rtn[len] = '\0';
	return (rtn);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*rtn;
	int		len;

	len = d_len(n);
	i = 0;
	if (!(rtn = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0 || n == -2147483648)
	{
		(n == 0) ? ft_strlcpy(rtn, "0", len + 1) :
		ft_strlcpy(rtn, "-2147483648", len + 1);
		return (rtn);
	}
	else if (n < 0)
	{
		rtn[0] = '-';
		n *= -1;
	}
	rtn = rtn_itoa(rtn, len, n);
	return (rtn);
}
