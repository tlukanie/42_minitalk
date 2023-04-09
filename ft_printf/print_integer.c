/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:24:31 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/07 18:37:11 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int num)
{
	char	*number;
	int		printed_char;

	number = ft_itoa(num);
	printed_char = print_str(number);
	free(number);
	return (printed_char);
}
