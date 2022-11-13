/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrallo <nrallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:01:09 by nrallo            #+#    #+#             */
/*   Updated: 2022/11/12 20:20:22 by nrallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_fawdawdawd(char c, va_list ap)
{
	char	*s;
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_print_char((char)va_arg(ap, int));
	else if (c == '%')
		len += ft_print_pourcent();
	else if (c == 's')
		len += ft_print_str((char *)va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		len += ft_print_str(s);
		free(s);
	}
	else if (c == 'x' || c == 'X')
		len += ft_print_hexadecimal(va_arg(ap, int), c);
	else if (c == 'u')
		len += print_nbr_base(10, va_arg(ap, unsigned int), 0, 0);
	else if (c == 'p')
		len += print_nbr_base(16, va_arg(ap, size_t), 0, 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{	
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_fawdawdawd(str[i], ap);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
