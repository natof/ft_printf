/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrallo <nrallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:46:43 by nrallo            #+#    #+#             */
/*   Updated: 2022/11/12 20:23:35 by nrallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_base(int base, unsigned long long n, int u, int a)
{
	char	c;
	int		i;

	i = 0;
	if (a)
		i += write(1, "0x", 2);
	if (n / base)
		i += print_nbr_base(base, n / base, u, 0);
	c = B16L[n % base];
	if (u)
		c = B16U[n % base];
	i += write(1, &c, 1);
	return (i);
}
