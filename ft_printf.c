/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:58:37 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/11 10:24:46 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

static int	ft_putarg(char C, va_list *args)
{
	if (C == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (C == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (C == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (C == 'd' || C == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (C == 'u')
		return (ft_putunsign(va_arg(*args, unsigned int)));
	else if (C == 'X' || C == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), C));
	else if (C == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_putarg(format[i], &args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
