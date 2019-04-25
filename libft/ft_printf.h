/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:54:12 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/21 06:35:24 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"

int		g_count;

int		ft_printf(char *str, ...);
int		ft_isconversion(char a);
int		ft_isflag(char a);
void	ft_search_flags(char *str, int *flags);
char	*ft_itoa_base(unsigned long long int i, int base, char type);
char	*ft_itoa_long(long long int i);
char	*ft_itoa_char(char a, int base);
int		ft_defsize(long long int i, int base);
int		ft_defsize_char(char a, int base);
int		ft_un_defsize(unsigned long long int i, int base);
int		ft_defsize_float(long double ldb, int precision);
void	ft_joinchar(char c, int size);
void	ft_joinstr(char *str);
void	ft_joinstrn(char *str, int n);
void	ft_decimal(long long int decimal, int *flags);
void	ft_hh_decimal(char hh_dec, int *flags);
void	ft_dec(int *flags, va_list ap);
void	ft_un_decimal(unsigned long long int un_decimal, int *flags);
void	ft_hh_un_decimal(unsigned char hh_un_dec, int *flags);
void	ft_un_dec(int *flags, va_list ap);
char	*ft_itoa_un_char(unsigned char a, int base, char type);
int		ft_defsize_un_char(unsigned char a, int base);
void	ft_oct(int *flags, va_list ap);
void	ft_octal(unsigned long long int oct_hex, int *flags);
void	ft_hh_octal(char hh_oct_hex, int *flags);
void	ft_hex(int *flags, va_list ap, char type);
void	ft_hexal(unsigned long long int hex, int *flags, char type);
void	ft_hh_hexal(char hh_hex, int *flags, char type);
void	ft_char(int *flags, char a);
void	ft_string(int *flags, va_list ap);
void	ft_point(int *flags, va_list ap);
void	ft_float(int *flags, va_list ap);
char	*ft_ftoa(long double ldb, int precision);

#endif
