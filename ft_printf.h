/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrallo <nrallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:57:11 by nrallo            #+#    #+#             */
/*   Updated: 2022/11/12 20:17:56 by nrallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define B16U "0123456789ABCDEF"
# define B16L "0123456789abcdef"

char			*ft_itoa(int n);
int				ft_print_hexadecimal(unsigned int n, const char hex);
int				ft_print_char(char c);
int				ft_printf(const char *str, ...);
int				ft_print_str(char *s);
unsigned int	ft_strlen(const char *s);
int				print_nbr_base(int base, unsigned long long n, int u, int a);
int				ft_print_pourcent(void);
int				ft_print_address(va_list ap);

#endif