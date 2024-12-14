/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:46:17 by lobenard          #+#    #+#             */
/*   Updated: 2024/12/12 17:24:12 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printchar(int c);
int		ft_printnbr(int n);
int		ft_printstr(char *str);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_ptr_len(uintptr_t num);
void	ft_putptr(uintptr_t n);
int		ft_printptr(unsigned long long ptr);
void	ft_ptr_to_hex(unsigned long long ptr, char *buffer, int *len);

#endif