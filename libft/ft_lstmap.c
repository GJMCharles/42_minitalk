/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:02:48 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/23 13:18:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*content;
	t_list	*tmp;

	if (!lst || !f || !del)
		return ((void *)0);
	result = (void *)0;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
			return ((void *)0);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			if (content != (void *)0)
				(*del)(content);
			if (lst->content != (void *)0)
				(*del)(lst->content);
			ft_lstclear(&result, del);
		}
		else
			ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
