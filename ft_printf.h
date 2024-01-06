/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:02:41 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/28 17:28:21 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	deformat(const char *format, va_list arguments);
int	use_placeholder(const char type, va_list arguments);
int	print_num(char *base, size_t number, int is_signed);
int	print_pointer(size_t p);
int	print_char(int c);
int	print_str(char *s);

#endif