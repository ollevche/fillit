/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:04:00 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/11 18:05:27 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			a;
	long long int	num;

	if (n < 0)
		write(fd, "-", 1);
	num = n;
	num = num > 0 ? num : -num;
	a = num + '0';
	if (num / 10 == 0)
		write(fd, &a, 1);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		a = num % 10 + '0';
		write(fd, &a, 1);
	}
}
