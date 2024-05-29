/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoroz <wmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:40:46 by wmoroz            #+#    #+#             */
/*   Updated: 2024/05/29 19:40:46 by wmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	print_format(char specifier, va_list ap)
{
	void *ptr;
	int count;
	count = 0;

	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'X' || specifier == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'p')
	{
		ptr = va_arg(ap, void *);
		if (ptr)
			return (ft_putaddress(ptr));
		// return (ft_putstr("0x0"));
	}
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...) // tez dokladnie zrozumiec
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	// int count;
// 	// count = ft_printf("Hello");
// 	char *c = "Hello world!";
// 	int n = 255;
// 	ft_printf("W");
// 	ft_printf("%s\n", c);
// 	// ft_printf("%d", n);
// 	// printf("%s", c);
// 	ft_printf("%i\n", n);
// 	ft_printf("%d\n", n);
// 	ft_printf("%u\n", n);
// 	ft_printf("%x\n", n);
// 	ft_printf("%X\n", n);
// 	ft_printf("\n");
// 	// ft_printf("%p\n %p\n", 0, 0);
// 	ft_printf("\n");
// 	ft_printf("HEllo woEWSd;!\n");
// 	printf("%i\n", n);
// 	printf("%d\n", n);
// 	printf("%u\n", n);
// 	printf("%x\n", n);
// 	printf("%X\n", n);
// }
	// printf("%p\n", n);
// 	printf("M\n");
// 	ft_printf("%s, %d, %i\n", "asdasda", 11, -6);
// 	ft_printf("%s, %d, %i\n", "rwererwe", 15, -19);
// 	ft_printf("%s, %d, %i\n", "dfgdfgf", 16, -10);
// 	ft_printf("%s, %d, %i\n", "afgfg", 17, -11);
// 	ft_printf("%s, %d, %i\n", "asddfgdfgda", 18, -17);
// 	ft_printf("%s, %d, %i\n", "asdaszxcda", 19, -18);
// 	ft_printf("%s, %d, %i\n", "asdsdf", 10, -176);
// 	ft_printf("%s, %d, %i\n", "asdasdsdfsda", 16, -1643);
// 	ft_printf("%s, %d, %i\n", "asdazxcsda", 19, -1436);
// 	ft_printf("%s, %d, %i\n", "asdassadsdda", 18, -1345);

// 	return (0);
// }