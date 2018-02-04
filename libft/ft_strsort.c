/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:56:30 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 17:50:04 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsort(char **str)
{
	char	*tmp;
	int		i;
	int		t;

	if (!str)
		return (NULL);
	t = 0;
	while (str[t])
	{
		i = 0;
		while (str[i])
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			i++;
		}
		t++;
	}
	return (str);
}
