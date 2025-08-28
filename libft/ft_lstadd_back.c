/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:01:28 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/23 12:51:44 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *lc)
{
	t_list	*tmp;

	if (!lc)
		return ;
	if (*lst == (void *)0)
	{
		*lst = lc;
		return ;
	}
	tmp = *lst;
	while (tmp->content)
	{
		if (tmp->next != (void *)0)
			tmp = tmp->next;
		else
		{
			tmp->next = lc;
			break ;
		}
	}
}
