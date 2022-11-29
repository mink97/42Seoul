/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:21:11 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/29 14:21:26 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

enum e_type
{
	T_LOWER,
	T_UPPER
};

int		ft_printf(const char *format, ...);
void	ft_putnbr_base(long long num, int base, int flag, int *len);
int		print_int(int num);
int		print_uint(unsigned int num);
int		print_hex(unsigned int num, int flag);
int		print_per(void);
int		print_char(char ch);
int		ft_strlen(char *str);
int		print_str(char *str);
void	ft_putnbr_base_u(unsigned long long num, int base, int *len);
int		print_addr(void *ptr);

#endif
