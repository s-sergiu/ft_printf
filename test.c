/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:15:22 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/20 17:31:05 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	int x;
	char str[] = "ssergiu";

	x = 1234567888;
	printf("\n");
	ft_printf("%dthis is a decimal: %s %d ", x , x, str);
	return (0);
}
