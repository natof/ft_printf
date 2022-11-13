/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrallo <nrallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 00:18:28 by nrallo            #+#    #+#             */
/*   Updated: 2022/11/12 20:23:26 by nrallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static char	*ft_rev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	while (i < j / 2)
	{
		tmp = str[i];
		str[i] = str[j - i - 1];
		str[j - i - 1] = tmp;
		i++;
	}
	return (str);
}

static int	ft_number_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	*rnull(void)
{
	char	*res;

	res = malloc(2 * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		neg;

	if (n == 0)
		return (rnull());
	neg = (n <= 0);
	i = 0;
	res = malloc((ft_number_size(n) + 1 + neg) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (n != 0)
	{
		res[i++] = ft_abs(n % 10) + '0';
		n = (n / 10);
	}
	if (neg)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_rev(res));
}
