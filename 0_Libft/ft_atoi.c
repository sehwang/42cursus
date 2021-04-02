/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:22:30 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/25 23:43:15 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
	c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	long	sign;
	long	sum;

	sign = 1;
	sum = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		sum *= 10;
		sum += *nptr - '0';
		if (sum > 2147483647 && sign == 1)
			return (-1);
		if (sum > 2147483648 && sign == -1)
			return (0);
		nptr++;
	}
	return (sum * sign);
}
