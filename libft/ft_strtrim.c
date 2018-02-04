/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:58:46 by ollevche          #+#    #+#             */
/*   Updated: 2017/12/03 15:29:59 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isok(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 0 : 1);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	while (!isok(*s) && *s)
		s++;
	i = ft_strlen(s) - 1;
	while (i + 1 > 0 && !isok(s[i]) && s[i])
		i--;
	if (!(str = ft_strnew(i + 1 > 0 ? i + 1 : 0)))
		return (NULL);
	if (ft_strlen(s))
		ft_strncpy(str, s, i + 1 > 0 ? i + 1 : 0);
	return (str);
}
