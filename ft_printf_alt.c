/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:56:25 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/17 20:12:25 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while(format[i++])
	{
		if (format[i] == '%')
		{
			while(!ft_isalpha(format[i++]))
				write(1, &format[i], 1);
		}
	}
	return (1);
}
