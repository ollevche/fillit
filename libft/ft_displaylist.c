/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaylist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:43:10 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 17:00:08 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_displaylist(t_list *head, char *s)
{
	while (head)
	{
		write(1, head->content, ft_strlen(head->content));
		write(1, s, ft_strlen(s));
		head = head->next;
	}
}
