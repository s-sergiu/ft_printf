/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:58:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/20 17:25:25 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	char	**test;	
	char	*trim;
	char 	*join;
	char	*itoa;
	char	*temp;
	va_list	ap;
	int		i;
	int		flag;
	int		len;
	
	i = 0;
	len = 0;
	flag = 0;
	va_start(ap, format);
	test = ft_split(format, '%');
	
	ft_putstr_fd(test[0], 1);
	len += (int)(ft_strlen(test[0]));
	while (test[++i])
	{
		if (strncmp(test[i], "s", 1))
		{
			itoa = va_arg(ap, char *);
			flag = 1;
		}
		else 
			itoa = ft_itoa(va_arg(ap, int));
		trim = ft_strtrim(test[i], "dis");
		join = ft_strjoin(itoa, trim);
		temp = test[i];
		test[i] = join;
		len += (int)(ft_strlen(test[i]));
		ft_putstr_fd(test[i], 1);
		if (flag) 
		{
			free(temp);
			free(trim);
			free(test[i]);
		}
		else 
		{
			free(itoa);
			free(temp);
			free(trim);
			free(test[i]);
		}
	}
	free(test[0]);
	free(test);
	va_end(ap);
	return (len);
}
