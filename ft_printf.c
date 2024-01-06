/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:03:55 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/28 17:28:57 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		result;

	va_start(arguments, format);
	result = deformat(format, arguments);
	va_end(arguments);
	return (result);
}

int	deformat(const char *format, va_list arguments)
{
	int	i;
	int	length_of_print;

	i = 0;
	length_of_print = 0;
	(void)arguments;
	while (format[i])
	{
		if (format[i] == '%')
		{
			length_of_print += use_placeholder(format[++i], arguments);
			if (!format[i])
				break ;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			length_of_print++;
		}
		i++;
	}
	return (length_of_print);
}

int	use_placeholder(const char type, va_list arguments)
{
	int		l;

	l = 0;
	if (type == '\0')
		return (0);
	else if (type == 'c')
		l += print_char(va_arg(arguments, int));
	else if (type == 's')
		l += print_str(va_arg(arguments, char *));
	else if (type == 'd' || type == 'i')
		l += print_num("0123456789", va_arg(arguments, int), 1);
	else if (type == 'p')
		l += print_pointer(va_arg(arguments, size_t));
	else if (type == 'u')
		l += print_num("0123456789", va_arg(arguments, unsigned int), 0);
	else if (type == 'x')
		l += print_num("0123456789abcdef", va_arg(arguments, unsigned int), 0);
	else if (type == 'X')
		l += print_num("0123456789ABCDEF", va_arg(arguments, unsigned int), 0);
	else
		l += print_char(type);
	return (l);
}
