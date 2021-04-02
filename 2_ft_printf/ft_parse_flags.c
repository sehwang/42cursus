/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:08:59 by sehwang           #+#    #+#             */
/*   Updated: 2021/03/20 18:29:26 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_zero_minus(const char **fmt, t_flag *flag)
{
	while (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '0')
			flag->zero = 1;
		else
			flag->left = 1;
		*fmt += 1;
	}
}

void	ft_flag_width(const char **fmt, va_list ap, t_flag *flag)
{
	int tmp;

	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			tmp = va_arg(ap, int);
			if (tmp < 0)
			{
				flag->left = 1;
				tmp *= -1;
			}
			*fmt += 1;
		}
		else
			tmp = ft_atoi_pointer(fmt);
		flag->width = tmp;
	}
	if (flag->left == 0 && flag->zero)
		flag->space = '0';
}

void	ft_flag_precision(const char **fmt, va_list ap, t_flag *flag)
{
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			flag->precision = va_arg(ap, int);
			*fmt += 1;
		}
		else
			flag->precision = ft_atoi_pointer(fmt);
	}
}

int		ft_parse(const char **fmt, t_flag *flag, va_list ap)
{
	ft_flag_zero_minus(fmt, flag);
	ft_flag_width(fmt, ap, flag);
	if (**fmt == '.' && (*fmt)++)
	{
		flag->dot = 1;
		ft_flag_precision(fmt, ap, flag);
	}
	if (ft_strchr("diuxX", **fmt))
		return (ft_treat_num(ap, flag, **fmt));
	else if (ft_strchr("c%", **fmt))
		return (ft_treat_char(ap, flag, **fmt));
	else if (**fmt == 'p')
		return (ft_treat_address(ap, flag));
	else if (**fmt == 's')
		return (ft_treat_str(ap, flag));
	return (0);
}
