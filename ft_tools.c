/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:46:39 by nakbas            #+#    #+#             */
/*   Updated: 2024/12/21 12:14:21 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, counter);
		str++;
	}
}

void	ft_putnbr(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648", counter);
		return ;
	}
	else if (num < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-num, counter);
	}
	else if (num < 10)
	{
		ft_putchar(num + '0', counter);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10, counter);
		ft_putnbr(num % 10, counter);
	}
}

void	ft_printun(unsigned int num, size_t *counter)
{
	if (num == 0)
	{
		ft_putchar('0', counter);
		return ;
	}
	if (num >= 10)
		ft_printun(num / 10, counter);
	ft_putchar((num % 10) + 48, counter);
}
