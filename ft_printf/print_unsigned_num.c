/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:34:06 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/08 18:24:27 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unum_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*unsigned_itoa(unsigned int num)
{
	int		len;
	char	*number;

	len = unum_len(num);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len] = '\0';
	while (num != 0)
	{
		number[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (number);
}

int	print_unsigned_num(unsigned int num)
{
	int		printed_char;
	char	*number;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		number = unsigned_itoa(num);
		printed_char = print_str(number);
		free(number);
	}
	return (printed_char);
}
