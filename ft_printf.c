/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:58:37 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/10 17:16:47 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putarg(char C, va_list *args)
{
	char	ch;

	if (C == 'c')
	{
		ch = va_arg(*args, int);
		return (write(1, &ch, 1));
	}
	else if (C == 's')
	{
	}
	else if (C == 'p')
	{
	}
	else if (C == 'd')
	{
	}
	else if (C == 'i')
	{
	}
	else if (C == 'u')
	{
	}
	else if (C == 'x')
	{
	}
	else if (C == 'X')
	{
	}
	else if (C == '%')
	{
		return (write(1, "%", 1));
	}
	return (0);
}

int	ft_printf(char *format, ...)
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
			count += write(1, format, i);
			i++;
			count += ft_putarg(format[i], &args);
			format += (i + 1);
			i = 0;
		}
		else
			i++;
	}
	count += write(1, format, i);
	va_end(args);
	return (count);
}
