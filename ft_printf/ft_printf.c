/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:51 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/07 18:34:05 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	convert_frmt(va_list args, char format)
{
	int	num_char;

	num_char = 0;
	if (format == 'c')
		num_char = print_char(va_arg(args, int));
	else if (format == 's')
		num_char = print_str(va_arg(args, char *));
	else if (format == 'p')
		num_char = print_pointer(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		num_char = print_integer(va_arg(args, int));
	else if (format == 'u')
		num_char = print_unsigned_num(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		num_char = print_hexadecimal(va_arg(args, int), format);
	else if (format == '%')
	{
		num_char = 1;
		print_char(format);
	}
	return (num_char);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			printed_chars += convert_frmt(args, string[i + 1]);
			i++;
		}
		else
			printed_chars += print_char(string[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
