/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:52:58 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/10 19:47:08 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char *format, ...);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunsign(unsigned int n);
int ft_puthex(unsigned int n, char format);
int ft_putptr(void *ptr);

#endif