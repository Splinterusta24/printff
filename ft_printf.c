/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:37 by nakbas            #+#    #+#             */
/*   Updated: 2024/12/20 20:01:22 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr(va_arg(args, int), counter);
	else if (*str == 'u')
		ft_printun(va_arg(args, unsigned int), counter);
	else if (*str == 'p')
		ft_printptr(va_arg(args, void *), counter, HEX_BASE);
	else if (*str == '%')
		ft_putchar(*str, counter);
	else if (*str == 'x')
		ft_printhex(va_arg(args, unsigned int), counter, HEX_BASE);
	else if (*str == 'X')
		ft_printhex(va_arg(args, unsigned int), counter, HEX_BASE_UP);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &counter);
		}
		else
			ft_putchar(*str, &counter);
		str++;
	}
	return (counter);
}
