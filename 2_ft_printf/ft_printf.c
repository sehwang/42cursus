/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:58:13 by sehwang           #+#    #+#             */
/*   Updated: 2021/03/21 18:53:05 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			ft_init_flag(void)
{
	t_flag		flag;

	flag.left = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.space = ' ';
	flag.dot = 0;
	return (flag);
}

int				ft_display_width(t_flag *flag, char *src, int len)
{
	int			char_cnt;

	char_cnt = ft_strlen(src);
	if (len > 0)
	{
		char_cnt += len;
		if (flag->left)
			ft_putstr_fd(src, 1);
		else if (src[0] == '-' && flag->space == '0')
			ft_putchar_fd(*src++, 1);
		while (len-- > 0)
			ft_putchar_fd(flag->space, 1);
		if (!flag->left)
			ft_putstr_fd(src, 1);
	}
	else
		ft_putstr_fd(src, 1);
	return (char_cnt);
}

int				ft_treat_fmt(const char *fmt, va_list ap)
{
	t_flag		flag;
	int			char_cnt;

	char_cnt = 0;
	while (1)
	{
		flag = ft_init_flag();
		if (!(*fmt))
			break ;
		else if (*fmt == '%')
		{
			fmt += 1;
			if (!(*fmt))
				break ;
			char_cnt += ft_parse(&fmt, &flag, ap);
			fmt += 1;
		}
		else if (*fmt != '%')
		{
			ft_putchar_fd(*fmt++, 1);
			char_cnt += 1;
		}
	}
	return (char_cnt);
}

int				ft_printf(const char *fmt, ...)
{
	const char	*save;
	va_list		ap;
	int			char_cnt;

	if (!(save = ft_strdup(fmt)))
		return (0);
	va_start(ap, fmt);
	char_cnt = ft_treat_fmt(save, ap);
	va_end(ap);
	free((char*)save);
	return (char_cnt);
}
