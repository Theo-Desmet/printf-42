/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:22:03 by tdesmet           #+#    #+#             */
/*   Updated: 2021/12/30 17:03:21 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_putstr(char *str, int *i)
{
	int j;

	j = 0;
	while (str[j])
	{
		ft_putchar(str[j], i);
		j++;
	}
}

void	ft_putaddress(unsigned long adr, int *i)
{
	ft_putstr("0x", i);
	ft_putnbr_hex(adr, i, "0123456789abcdef");
}

void	ft_putnbr(int nb, int *i, int neg)
{
	unsigned int	nbr;

	if (nb < 0 && neg)
		nbr = nb * -1;
	if (nb < 0 && !neg)
	{
		nbr = nb * -1;
		ft_putchar('-', i);
	}
	else
		nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr /10, i, neg);
		ft_putnbr(nbr % 10, i, neg);
	}
	else
		ft_putchar(nbr + '0', i);
}

void	ft_putnbr_hex(unsigned long nbr, int *i, char *hex)
{
	if (nbr > 16)
	{
		ft_putnbr_hex(nbr / 16, i, hex);
		ft_putnbr_hex(nbr % 16, i, hex);
	}
	else
		ft_putchar(hex[nbr], i);
}
