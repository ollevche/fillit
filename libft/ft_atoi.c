/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:40:21 by ollevche          #+#    #+#             */
/*   Updated: 2017/12/03 15:50:12 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iscc(char c)
{
	if (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long int	num;
	unsigned long long int	max;
	size_t					i;
	size_t					m;

	if (!str)
		return (0);
	num = 0;
	i = 0;
	while (iscc(str[i]))
		i++;
	m = i;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	max = 9223372036854775807;
	while (str[i] && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
		if (num >= max && str[m] != '-')
			return (-1);
		if (num >= max + 1 && str[m] == '-')
			return (0);
	}
	return ((str[m] == '-') ? -num : num);
}
