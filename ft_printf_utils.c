/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:19:32 by mokarimi          #+#    #+#             */
/*   Updated: 2025/11/20 20:19:34 by mokarimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putunbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_puthexnbr(unsigned int nb, char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_puthexnbr(nb / 16, c);
	count += write(1, &base[nb % 16], 1);
	return (count);
}

int	ft_puthexnbr_long(unsigned long nb, char c)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_puthexnbr_long(nb / 16, c);
	count += write(1, &base[nb % 16], 1);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	return (ft_puthexnbr_long(address, 'x') + 2);
}
