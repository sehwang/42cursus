/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:07:14 by sehwang           #+#    #+#             */
/*   Updated: 2021/03/20 20:37:18 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_len_base(long long n, int base)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

int				ft_atoi_pointer(const char **nptr)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			sign *= -1;
	}
	while ('0' <= **nptr && **nptr <= '9')
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	return (num * sign);
}

char			*ft_itoa_precision(long int n, t_flag *flag)
{
	char		*str;
	int			len;
	long long	num;

	num = n;
	len = ft_len_base(num, 10);
	len = len > flag->precision ? len : flag->precision;
	if (num < 0)
		len += 1;
	if (!(str = (char*)ft_calloc((len + 1), 1)))
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len--] = '\0';
	while (1)
	{
		if (str[len] == '-' || len < 0)
			break ;
		str[len--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

char			*ft_uitoa_base(unsigned int n, char *base, t_flag *flag)
{
	char		*str;
	int			base_len;
	int			len;
	long long	num;

	num = n;
	base_len = ft_strlen(base);
	len = ft_len_base(num, base_len);
	len = len > flag->precision ? len : flag->precision;
	if (!(str = (char*)malloc(len + 1)))
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (1)
	{
		if (len < 0)
			break ;
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

char			*ft_ultoa_base(unsigned long num, char *base, t_flag *flag)
{
	char		*str;
	int			base_len;
	int			len;

	base_len = ft_strlen(base);
	len = ft_len_base(num, base_len);
	len = len > flag->precision ? len : flag->precision;
	if (!(str = (char*)malloc(len + 1)))
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (1)
	{
		if (len < 0)
			break ;
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
