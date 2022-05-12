/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:58:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/12 17:43:19 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft/libft.h"

int	count_symbols(char const *format)
{
	int	count;

	count = 0;
	while (ft_strlen(format))
	{
		if (ft_strncmp(format, "%d", 2))
				format++;
		else
		{
			count++;
			format = format + 2;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		args;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	args = count_symbols(format);
	ft_putchar_fd(format[i], 1);
	while (format[i++])
	{
		if (format[i] == '%' && ft_strncmp(format, "%d", 2))
		{
			ft_putnbr_fd(va_arg(ap, int), 1);
			i = i + 2;
		}
		ft_putchar_fd(format[i], 1);
	}
	va_end(ap);
	return (1);
}
