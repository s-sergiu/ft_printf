/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:15:22 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/17 19:58:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	int	x;

	x = 1234567888;
	printf("%p", &x);
	printf("\n");
	ft_printf(" %p %p ", 0, 0);
	return (0);
}
