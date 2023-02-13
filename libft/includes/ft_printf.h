/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:15:56 by jbok              #+#    #+#             */
/*   Updated: 2023/01/30 15:25:55 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef enum e_type
{
	FT_ERROR = 0,
	PLAIN,
	PERCENT,
	CHAR,
	PRINTF_STR,
	PTR,
	SINT,
	UINT,
	LHEX,
	UHEX,
}	t_type;

typedef enum e_flag
{
	FT_FLAG_ERROR = 0,
	FT_FLAG_HYPHEN = 1,
	FT_FLAG_ZERO = 1 << 1,
	FT_FLAG_PERIOD = 1 << 2,
	FT_FLAG_HASH = 1 << 3,
	FT_FLAG_SPACE = 1 << 4,
	FT_FLAG_PLUS = 1 << 5,
}	t_flag;

typedef struct s_arg
{
	void		*content;
	t_flag		flag;
	int			width;
	int			precision;
	t_type		type;
	ssize_t		prt_len;
}	t_arg;

typedef void	(*t_f)(va_list*, t_arg*);

//ft_printf.c
int		ft_printf(const char *str, ...);
int		ft_printf2(const char **str, va_list *ap, ssize_t *count);
t_arg	*ft_get_arg(const char **str, va_list *ap, ssize_t *count);
//ft_printf_utils
int		ft_abs(int n);
void	*ft_memset(void *dst, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_simple_atoi(const char **str);
t_flag	ft_chr_to_type(const char c);
ssize_t	ft_putstr(void *ptr);
void	ft_free_arg(void *ptr);
size_t	ft_intlen(int n);
size_t	ft_uintlen(unsigned int n);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
size_t	ft_hexlen(size_t n);
char	*ft_ptrtoa(void *ptr);
char	*ft_lhextoa(unsigned int n);
char	*ft_uhextoa(unsigned int n);
//ft_printf_format
void	ft_make_str(va_list *ap, t_arg *arg);
void	ft_format_char(va_list *ap, t_arg *arg);
void	ft_format_str(va_list *ap, t_arg *arg);
void	ft_format_ptr(va_list *ap, t_arg *arg);
void	ft_format_sint(va_list *ap, t_arg *arg);
void	ft_format_uint(va_list *ap, t_arg *arg);
void	ft_format_lhex(va_list *ap, t_arg *arg);
void	ft_format_uhex(va_list *ap, t_arg *arg);
//ft_printf_parse
void	ft_parse_str(const char **str, t_arg *arg);
void	ft_parse_str2(const char **str, t_arg *arg);
void	ft_parse_str3(const char c, t_arg *arg);
#endif