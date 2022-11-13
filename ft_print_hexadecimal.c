/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrallo <nrallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:40:00 by nrallo            #+#    #+#             */
/*   Updated: 2022/11/12 20:23:33 by nrallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned	int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	ft_put_hexadecimal(unsigned long n, const char hex)
{
	if (n >= 16)
	{
		ft_put_hexadecimal(n / 16, hex);
		ft_put_hexadecimal(n % 16, hex);
	}
	else
	{
		if (n <= 9)
			ft_print_char((n + '0'));
		else
		{
			if (hex == 'x')
				ft_print_char((n - 10 + 'a'));
			if (hex == 'X')
				ft_print_char((n - 10 + 'A'));
		}
	}
}

int	ft_print_hexadecimal(unsigned int n, const char hex)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hexadecimal(n, hex);
	return (ft_len(n));
}
