/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:59:09 by nakbas            #+#    #+#             */
/*   Updated: 2024/12/20 20:08:55 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long num, size_t *counter, char *base)
{
	if (num >= 16)
		ft_putptr(num / 16, counter, base);
	ft_putchar(base[num % 16], counter);
}

void	ft_printptr(void *ptr, size_t *counter, char *base)
{
	unsigned long long	num;

	num = (unsigned long long)ptr;
	if (num == 0)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	ft_putstr("0x", counter);
	ft_putptr(num, counter, base);
}

void	ft_printhex(unsigned int num, size_t *counter, char *base)
{
	if (num >= 16)
		ft_printhex(num / 16, counter, base);
	ft_putchar(base[num % 16], counter);
}
