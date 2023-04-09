/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_customized.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:19:37 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/10 18:12:27 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	ch = s;
	i = 0;
	while (i < n)
	{
		ch[i] = '\0';
		i++;
	}
	return (s);
}

static char	*convert_to_string(char *str, int num, int len)
{
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

static int	count_num_length(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		l = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		l++;
		n *= -1;
	}
	while (n > 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

static char	*zero_min(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		num_len;
	int		num;

	num_len = count_num_length(n);
	string = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!string)
		return (NULL);
	ft_bzero(string, (num_len + 1));
	string = zero_min(n, string);
	string[num_len--] = '\0';
	if (n == 0)
		string[0] = '0';
	if (n < 0 && n != -2147483648)
	{
		num = n * -1;
		string[0] = '-';
	}
	else
		num = n;
	string = convert_to_string(string, num, num_len);
	return (string);
}
