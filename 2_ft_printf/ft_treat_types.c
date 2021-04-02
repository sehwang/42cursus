/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:01:51 by sehwang           #+#    #+#             */
/*   Updated: 2021/03/19 02:24:12 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_treat_char(va_list ap, t_flag *flag, char type)
{
	char			str;
	int				char_cnt;
	int				len;

	if (type == '%')
		str = '%';
	else
		str = va_arg(ap, int);
	char_cnt = 1;
	if (flag->width > 1)
	{
		char_cnt += flag->width - 1;
		len = flag->width - 1;
		if (flag->left)
			ft_putchar_fd(str, 1);
		while (len-- > 0)
			ft_putchar_fd(flag->space, 1);
		if (!flag->left)
			ft_putchar_fd(str, 1);
	}
	else
		ft_putchar_fd(str, 1);
	return (char_cnt);
}

int					ft_treat_str(va_list ap, t_flag *flag)
{
	char			*str;
	int				char_cnt;
	char			*tmp;

	tmp = va_arg(ap, char *);
	if (!tmp)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(tmp);
	if (flag->dot && flag->precision >= 0)
		str = ft_substr(tmp, 0, flag->precision);
	else
		str = ft_strdup(tmp);
	char_cnt = ft_display_width(flag, str, flag->width - ft_strlen(str));
	free(tmp);
	free(str);
	return (char_cnt);
}

int					ft_treat_address(va_list ap, t_flag *flag)
{
	char			*src;
	char			*tmp;
	int				char_cnt;
	unsigned long	num;

	num = va_arg(ap, unsigned long);
	if (flag->dot && flag->precision == 0 && num == 0)
		tmp = ft_strdup("");
	else
		tmp = ft_ultoa_base(num, "0123456789abcdef", flag);
	src = ft_strjoin("0x", tmp);
	char_cnt = ft_display_width(flag, src, flag->width - ft_strlen(src));
	free(src);
	free(tmp);
	return (char_cnt);
}

int					ft_treat_num(va_list ap, t_flag *flag, char type)
{
	char			*src;
	int				char_cnt;
	int				num;

	src = 0;
	num = va_arg(ap, int);
	if (flag->dot && flag->precision >= 0)
		flag->space = ' ';
	if (flag->dot && flag->precision == 0 && num == 0)
		src = ft_strdup("");
	else
	{
		if (type == 'd' || type == 'i')
			src = ft_itoa_precision(num, flag);
		else if (type == 'X')
			src = ft_uitoa_base(num, "0123456789ABCDEF", flag);
		else if (type == 'x')
			src = ft_uitoa_base(num, "0123456789abcdef", flag);
		else if (type == 'u')
			src = ft_uitoa_base(num, "0123456789", flag);
	}
	char_cnt = ft_display_width(flag, src, flag->width - ft_strlen(src));
	free(src);
	return (char_cnt);
}
