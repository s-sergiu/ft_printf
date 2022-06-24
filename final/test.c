/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:39:00 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/24 08:47:53 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int	main(void)
{
	char str[] = "ssergiu";
	unsigned int x;
	int f;

	x = 4294967295;
	ft_printf("this is a %s", "test");
	return(f);
}
