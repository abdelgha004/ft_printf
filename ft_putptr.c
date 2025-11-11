/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:45:37 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/11 14:43:03 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int		count;
	size_t	temp;
	char	arr[30];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	count = 0;
	if (!ptr)
		return (count += write(1, "(nil)", 5));
	temp = (size_t)ptr;
	count += write(1, "0x", 2);
	i = 0;
	while (temp)
	{
		arr[i] = base[temp % 16];
		temp /= 16;
		i++;
	}
	while (i)
	{
		i--;
		count += ft_putchar(arr[i]);
	}
	return (count);
}
