/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:11:57 by tdesmet           #+#    #+#             */
/*   Updated: 2021/12/30 17:04:57 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF
#define PRINTF
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printf_check(const char *str, int *i, int *j, va_list ap);

void	ft_putchar(char c, int *i);
void	ft_putstr(char *str, int *i);
void	ft_putnbr(int nb, int *i, int neg);
void	ft_putaddress(unsigned long adr, int *i);
void	ft_putnbr_hex(unsigned long nb, int *i, char *hex);
#endif
