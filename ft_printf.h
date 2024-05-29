/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoroz <wmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:11:39 by wmoroz            #+#    #+#             */
/*   Updated: 2024/05/29 21:44:19 by wmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
int ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_puthexa(unsigned long n, char format);
int	rec_print(unsigned long n, char const *base);
int	ft_putaddress(void *format);
int print_format(char specifier, va_list ap);
int ft_printf(const char *format, ...);
int	print_unsigned(unsigned int nb);

#endif