/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:45:34 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/10 19:56:24 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str){
    if(!str)
        return (write(1, "(null)", 6));
    int i;
    i = 0;
    while(str[i])
        i++;
    return (write(1, str, i));
}