/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:58:02 by sehwang           #+#    #+#             */
/*   Updated: 2021/03/19 02:23:28 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flag
{
	int			left;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			space;
}				t_flag;

t_flag			ft_init_flag(void);
int				ft_display_width(t_flag *flag, char *src, int len);
int				ft_printf(const char *fmt, ...);
int				ft_parse(const char **fmt, t_flag *flag, va_list ap);
void			ft_flag_zero_minus(const char **fmt, t_flag *flag);
void			ft_flag_width(const char **fmt, va_list ap, t_flag *flag);
void			ft_flag_precision(const char **fmt, va_list ap, t_flag *flag);

int				ft_treat_str(va_list ap, t_flag *flag);
int				ft_treat_address(va_list ap, t_flag *flag);
int				ft_treat_char(va_list ap, t_flag *flag, char type);
int				ft_treat_num(va_list ap, t_flag *flag, char type);

int				ft_atoi_pointer(const char **nptr);
char			*ft_itoa_precision(long int n, t_flag *flag);
char			*ft_uitoa_base(unsigned int n, char *base, t_flag *flag);
char			*ft_ultoa_base(unsigned long num, char *base, t_flag *flag);
#endif
