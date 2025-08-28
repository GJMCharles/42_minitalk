/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:52:22 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/19 13:59:18 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	if (!lst)
		return (0);
	size = 0;
	tmp = lst;
	while (tmp->content)
	{
		size += 1;
		if (tmp->next != (void *)0)
			tmp = tmp->next;
		else
			break ;
	}
	return (size);
}
