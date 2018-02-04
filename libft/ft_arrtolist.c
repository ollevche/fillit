/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:06:04 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 16:49:18 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_arrtolist(char **arr)
{
	t_list	*head;
	t_list	*tmp;
	size_t	i;

	if (!arr || !arr[0])
		return (NULL);
	head = ft_lstnew(arr[0], ft_strlen(arr[0]));
	if (!(tmp = head))
		return (NULL);
	i = 1;
	while (arr[i])
	{
		if (!(tmp->next = ft_lstnew(arr[i], ft_strlen(arr[i]))))
		{
			ft_lstdel(&head, &ft_bzero);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	return (head);
}
