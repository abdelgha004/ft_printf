/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:45:30 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/11 14:31:04 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsign(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsign(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
