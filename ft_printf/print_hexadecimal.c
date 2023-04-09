/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:37:01 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/07 18:35:51 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static char	*hexa_itoa(unsigned int num, char format)
{
	int		len;
	char	*hexa_num;
	int		nb;

	len = hexa_len(num);
	hexa_num = (char *)malloc((len + 1) * sizeof(char));
	if (!hexa_num)
		return (0);
	hexa_num[len] = '\0';
	while (num != 0)
	{
		nb = num % 16;
		if (nb < 10)
			hexa_num[len - 1] = nb + '0';
		else
			hexa_num[len - 1] = nb + format;
		num /= 16;
		len--;
	}
	return (hexa_num);
}

int	print_hexadecimal(unsigned int num, char format)
{
	int		len;
	char	*hexa_num;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (format == 'x')
		format = 87;
	else
		format = 55;
	hexa_num = hexa_itoa(num, format);
	len = print_str(hexa_num);
	free(hexa_num);
	return (len);
}
