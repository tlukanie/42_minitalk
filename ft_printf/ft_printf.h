/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:49:37 by tlukanie          #+#    #+#             */
/*   Updated: 2023/02/10 18:14:54 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h> 
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		print_char(int c);
int		print_str(char *str);
int		ft_printf(const char *string, ...);
int		hexa_len(unsigned int num);
int		print_hexadecimal(unsigned int num, char format);
int		print_integer(int num);
int		print_pointer(uintptr_t num);
int		print_unsigned_num(unsigned int num);
void	*ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);

#endif
