/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:41:17 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/24 11:40:29 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	void	*content;
	t_list	*node;

	result = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		content = f(tmp->content);
		node = ft_lstnew(content);
		if (content == 0 || node == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, node);
		tmp = tmp->next;
	}
	return (result);
}
