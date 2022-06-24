/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:09:18 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/10 15:30:38 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	contains(char const *set, char s)
{
	int	i;

	i = 0;
	while (set[i])
		if (s == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	j;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (contains(set, s1[i]) == 1)
		i++;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, 1));
	while (contains(set, s1[j]) == 1)
		j--;
	trim = ft_substr(s1, i, j - i + 1);
	return (trim);
}
