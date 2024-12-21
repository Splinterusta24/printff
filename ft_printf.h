/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakbas <nakbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:46:52 by nakbas            #+#    #+#             */
/*   Updated: 2024/12/20 20:04:13 by nakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, size_t *counter);
void	ft_putstr(char *str, size_t *counter);
void	ft_putnbr(int num, size_t *counter);
void	ft_printun(unsigned int num, size_t *counter);
void	ft_putptr(unsigned long long num, size_t *counter, char *base);
void	ft_printptr(void *ptr, size_t *counter, char *base);
void	ft_printhex(unsigned int num, size_t *counter, char *base);

#endif
