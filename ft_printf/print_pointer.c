/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:38 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/08 18:51:21 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	hexa_p_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static char	*hexa_itoa_p(uintptr_t num)
{
	int					len;
	char				*ptr_num;
	int					nb;

	len = hexa_p_len(num);
	ptr_num = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr_num)
		return (0);
	ptr_num[len] = '\0';
	while (num != 0)
	{
		nb = num % 16;
		if (nb < 10)
			ptr_num[len - 1] = nb + '0';
		else
			ptr_num[len - 1] = nb + 87;
		num /= 16;
		len--;
	}
	return (ptr_num);
}

int	print_pointer(uintptr_t num)
{
	int		len;
	char	*ptr;

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ptr = hexa_itoa_p(num);
	len = print_str(ptr) + 2;
	free(ptr);
	return (len);
}
