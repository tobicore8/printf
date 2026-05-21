/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkern <tkern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:15:54 by tkern             #+#    #+#             */
/*   Updated: 2026/05/21 14:57:36 by tkern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BASE_LOW   "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"
# define BASE_DEC   "0123456789"

int		ft_printf(const char *format, ...);
int		ft_handle_format(char specifier, va_list *args);
char	*ft_htoa(uintptr_t n, char *b);
int		ft_print_char(va_list *args);
int		ft_print_str(va_list *args);
int		ft_print_ptr(va_list *args);
int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_hex(va_list *args, char specifier);

#endif