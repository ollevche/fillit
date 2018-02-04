/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:03:25 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 17:04:27 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	long long int	num;
	size_t			size;
	char			*res;

	num = n > 0 ? n : -(long long int)n;
	size = n > 0 ? 0 : 1;
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	if (!(res = ft_strnew(size)))
		return (NULL);
	num = n > 0 ? n : -(long long int)n;
	res[0] = n < 0 ? '-' : '0';
	while (num != 0)
	{
		size--;
		res[size] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
