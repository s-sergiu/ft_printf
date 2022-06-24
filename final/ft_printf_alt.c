/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:56:25 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/24 07:18:05 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"
#include <limits.h>

void dectohex(unsigned long n, int i)
{
	unsigned long temp; 
	if (i == 8)
		return ;
	else
	{
		i++;
		dectohex(n / 16, i);
		temp = n % 16;
		if (temp > 9)
		{
			temp += 87;
			ft_putchar_fd(temp, 1);
		}
		else
			ft_putnbr_fd(temp, 1);
	}
}

int main(void)
{
	dectohex(LONG_MAX, 0);
	return(0);
}
