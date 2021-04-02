/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:23:22 by sehwang           #+#    #+#             */
/*   Updated: 2020/11/22 12:21:31 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_rec(int n, int fd)
{
	char tmp;

	if (n > 9)
		putnbr_rec(n / 10, fd);
	tmp = (n % 10) + '0';
	write(fd, &tmp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		putnbr_rec(-n, fd);
	}
	else
		putnbr_rec(n, fd);
}
