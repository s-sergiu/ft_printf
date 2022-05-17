/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:58:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/17 15:33:26 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft/libft.h"

static int	nlen(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (!n)
		return (1);
	if (n < 0)
		sign = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

static int	count_symbols(char const *format)
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
	int		var_len;
	int		args;
	va_list	ap;
	va_list	ap_len;
	va_list ap_null;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	args = count_symbols(format);
	var_len = 0;
	while (format[i])
	{
		if (!ft_strncmp(format + i, "%c", 2))
		{
			var_len++;
			ft_putchar_fd(va_arg(ap, int), 1);
			i = i + 2;
		}
		if (!ft_strncmp(format + i, "%s", 2))
		{
			va_copy(ap_len, ap);
			va_copy(ap_null, ap);
			if (va_arg(ap_null, char *) == NULL)
			{
				ft_putstr_fd("(null)", 1);
				var_len += 6;
			}
			else
			{
				var_len += ft_strlen(va_arg(ap_len, char *));
				ft_putstr_fd(va_arg(ap, char *), 1);
			}
			i = i + 2;
		}
		if (!ft_strncmp(format + i, "%d", 2) || !ft_strncmp(format + i, "%i", 2))
		{
			va_copy(ap_len, ap);
			var_len += nlen(va_arg(ap_len, int));
			ft_putnbr_fd(va_arg(ap, int), 1);
			i = i + 2;
		}
		if (format[i])
			ft_putchar_fd(format[i], 1);
		else 
			break;
		len++;
		i++;
	}
	va_end(ap);
	return (len + var_len);
}
