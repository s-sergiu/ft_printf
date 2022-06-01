/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:58:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/01 15:42:39 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft/libft.h"

static int	dectohex(unsigned long n, int i)
{
	int	temp;

	if (n == 0)
	{
		i = i - 2;
		return(i);
	}
	else
	{
		i = i + dectohex(n / 16, 1);
		temp = n % 16;
		if (temp > 9)
		{
			temp += 87;
			ft_putchar_fd(temp, 1);
		}
		else
			ft_putnbr_fd(temp, 1);
	}
	return (i);
}

static int	pointerhex(unsigned long n, int i)
{
	int	temp;

	if (n == 0)
	{
		ft_putnbr_fd(n, 1);
		ft_putchar_fd('x', 1);
	}
	else
	{
		i = i + pointerhex(n / 16, 1);
		temp = n % 16;
		if (temp > 9)
		{
			temp += 87;
			ft_putchar_fd(temp, 1);
		}
		else
			ft_putnbr_fd(temp, 1);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;
	va_list	ap_null;
	char	*temp;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (!ft_strncmp(format + i, "%x", 2))
		{
			va_copy(ap_null, ap);
			if (va_arg(ap_null, unsigned long) == 0)
			{
				len ++;
				ft_putstr_fd("0", 1);
			}
			else 
				len += 2 + dectohex(va_arg(ap, unsigned long), 0);
			i = i + 2;
		}
		if (!ft_strncmp(format + i, "%p", 2))
		{
			va_copy(ap_null, ap);
			if (va_arg(ap_null, unsigned long) == 0)
			{
				len += 3;
				ft_putstr_fd("0x0", 1);
			}
			else 
				len += 2 + pointerhex(va_arg(ap, unsigned long), 0);
			i = i + 2;
		}
		if (!ft_strncmp(format + i, "%c", 2))
		{
			ft_putchar_fd(va_arg(ap, int), 1);
			len++;
			i = i + 2;
		}
		if (!ft_strncmp(format + i, "%s", 2))
		{
			va_copy(ap_null, ap);
			if (va_arg(ap, char *) == NULL)
				temp = strdup("(null)");
			else 
				temp = strdup(va_arg(ap_null, char *));	
			len += ft_strlen(temp);
			ft_putstr_fd(temp, 1);
			i = i + 2;
			free(temp);
		}
		if (!ft_strncmp(format + i, "%d", 2)
			|| !ft_strncmp(format + i, "%i", 2))
		{
			temp = ft_itoa(va_arg(ap, int));
			len += ft_strlen(temp);
			ft_putstr_fd(temp, 1);
			i = i + 2;
			free(temp);
		}
		if(format[i])
			len +=  write(1, &format[i], 1);	
		else 
			break;
		i++;
	}
	va_end(ap);
	return (len);
}
