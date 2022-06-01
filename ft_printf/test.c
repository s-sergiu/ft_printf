/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:15:22 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/30 16:29:53 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int	main(void)
{
	int x;
	char str[] = "ssergiu";

	x = 1234567888;
	printf("\n");
	
	printf(" %x ", LONG_MAX);					
	printf("\n");
	ft_printf(" %x ", LONG_MAX);

	return(0);
}
