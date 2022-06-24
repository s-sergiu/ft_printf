/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:48:05 by ssergiu           #+#    #+#             */
/*   Updated: 2022/04/10 15:27:02 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (++i < n + 1)
		if (*((unsigned char *)s1 + i - 1) != *((unsigned char *)s2 + i - 1))
			return (*((unsigned char *)s1 + i - 1)
				- *((unsigned char *)s2 + i - 1));
	return (0);
}
