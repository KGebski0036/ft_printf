/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:26:02 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/28 17:30:34 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_num(char *base, size_t number, int is_signed)
{
	size_t		length_of_number;
	size_t		length_of_base;
	long long	tmp;

	tmp = (unsigned long long)number;
	length_of_number = 0;
	if (tmp < 0 && is_signed)
	{
		length_of_number += print_char('-');
		tmp *= -1;
	}
	length_of_base = ft_strlen(base);
	if (tmp == 0)
		length_of_number += print_char('0');
	else if ((unsigned long long)tmp >= length_of_base)
	{
		length_of_number += print_num(base, tmp / length_of_base, is_signed);
		length_of_number += print_num(base, tmp % length_of_base, is_signed);
	}
	else if ((unsigned long long)tmp < length_of_base)
		length_of_number += print_char(base[tmp]);
	return (length_of_number);
}

int	print_pointer(size_t p)
{
	if (!p)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	return (print_num("0123456789abcdef", p, 0) + 2);
}

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
