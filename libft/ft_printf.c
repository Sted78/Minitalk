/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:41:26 by svanmarc          #+#    #+#             */
/*   Updated: 2023/06/26 12:21:04 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putnbrbase(unsigned long long int nbr, char *base, char format)
{
	int				count;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < 10)
		count += ft_putchar_pf(nbr + '0');
	else if (nbr < base_len)
	{
		if (format == 'x' || format == 'p')
			count += ft_putchar_pf(nbr - 10 + 'a');
		else if (format == 'X')
			count += ft_putchar_pf(nbr - 10 + 'A');
	}
	else
	{
		count += ft_putnbrbase(nbr / base_len, base, format);
		count += ft_putnbrbase(nbr % base_len, base, format);
	}
	return (count);
}

int	ft_format_di(int num, char format)
{
	int				count;
	long long int	long_num;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar_pf('-');
		long_num = -(long long int)num;
	}
	else
		long_num = num;
	return (count + ft_putnbrbase((unsigned long long int)long_num,
			"0123456789", format));
}

int	ft_format_p(unsigned long long int num, char format)
{
	if (num == 0)
		return (ft_putstr_pf("(nil)"));
	write(1, "0x", 2);
	return (ft_putnbrbase(num, "0123456789ABCDEF", format) + 2);
}

int	ft_eval_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_format_di(va_arg(args, int), format));
	else if (format == 'u')
		return (ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789", format));
	else if (format == 'x' || format == 'X')
		return (ft_putnbrbase(va_arg(args, unsigned int),
				"0123456789ABCDEF", format));
	else if (format == 'p')
		return (ft_format_p(va_arg(args, unsigned long long int), format));
	else
		return (ft_putchar_pf(format));
}

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += ft_eval_format(*(++str), args);
		else
			count += ft_putchar_pf(*str);
		str++;
	}
	va_end(args);
	return (count);
}
