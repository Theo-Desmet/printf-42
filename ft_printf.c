/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:53:37 by tdesmet           #+#    #+#             */
/*   Updated: 2021/12/30 17:02:41 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;
	
	if (!str)
		return (0);
	i = 0;
	j = 0;
	va_start(ap, str);
	while(str[j])
	{
		if(str[j] == '%')
			i = ft_printf_check(str, &i, &j, ap);
		else
			ft_putchar(str[j], &i);
		j++;
	}
	return (i);
}

int	ft_printf_check(const char *str, int *i, int *j,va_list ap)
{
	if (str[*j + 1] == 'c')
		ft_putchar(va_arg(ap, int), i);
	else if (str[*j + 1] == 's')
		ft_putstr(va_arg(ap, char*), i);
	else if (str[*j + 1] == 'p')
		ft_putaddress(va_arg(ap, unsigned long), i);
	else if (str[*j + 1] == 'd')
		ft_putnbr(va_arg(ap, int), i, 0);
	else if (str[*j + 1] == 'i')
		ft_putnbr(va_arg(ap, int), i, 0);
	else if (str[*j + 1] == 'u')
		ft_putnbr(va_arg(ap, int), i, 1);
	else if (str[*j + 1] == 'x')
		ft_putnbr_hex(va_arg(ap, unsigned int), i, "0123456789abcdef");
	else if (str[*j + 1] == 'X')
		ft_putnbr_hex(va_arg(ap, unsigned int), i, "0123456789ABCDEF");
	else
		ft_putchar('%', i);
	*j += 1;
	return (*i);
}
/*
int main()
{
	int i;

	i = 0;
	ft_printf("%d\n", ft_printf("%x\n", &i, 1234));
	printf("%d\n", printf("%x\n", &i, 1234));
}*/
