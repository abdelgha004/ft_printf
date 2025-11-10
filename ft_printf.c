/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:58:37 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/10 19:54:51 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchr(char ch)
{
	return (write(1, &ch, 1));
}

static int	ft_putarg(char C, va_list *args)
{
	if (C == 'c')
		return (ft_putchr(va_arg(*args, int)));
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
		return (write(1, "%", 1));
	else
		return (write(1, &C, 1));
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


// int main(void)
// {
//     char *normal = "Hello, World!";
//     char *empty = "";
//     char *null_ptr = NULL;
//     char *special = "Line1\nLine2\tTabbed";

//     int ret1, ret2;

//     printf("=== Testing normal string ===\n");
//     ret1 = printf("printf:  '%s'\n", normal);
//     ret2 = ft_printf("ft_printf: '%s'\n", normal);
//     printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

//     printf("=== Testing empty string ===\n");
//     ret1 = printf("printf:  '%s'\n", empty);
//     ret2 = ft_printf("ft_printf: '%s'\n", empty);
//     printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

//     printf("=== Testing NULL string ===\n");
//     ret1 = printf("printf:  '%s'\n", null_ptr);
//     ret2 = ft_printf("ft_printf: '%s'\n", null_ptr);
//     printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

//     printf("=== Testing special characters ===\n");
//     ret1 = printf("printf:  '%s'\n", special);
//     ret2 = ft_printf("ft_printf: '%s'\n", special);
//     printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

//     printf("=== Testing very long string ===\n");
//     char long_str[300];
//     for (int i = 0; i < 299; i++)
//         long_str[i] = 'A' + (i % 26);
//     long_str[299] = '\0';

//     ret1 = printf("printf:  '%s'\n", long_str);
//     ret2 = ft_printf("ft_printf: '%s'\n", long_str);
//     printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

//     return 0;
// }
