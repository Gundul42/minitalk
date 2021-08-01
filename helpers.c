/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:09:14 by graja             #+#    #+#             */
/*   Updated: 2021/07/31 16:09:46 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int	ft_space(char c)
{
	if (((c >= 8) && (c <= 13)) || (c == 32))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	int			res;

	res = 0;
	sign = 1;
	while (ft_space(*nptr))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	res *= sign;
	return (res);
}
