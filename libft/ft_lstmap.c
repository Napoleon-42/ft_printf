/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:40:00 by lnelson           #+#    #+#             */
/*   Updated: 2019/11/29 14:25:41 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*ptr;
	t_list	*res;

	i = 0;
	if (!lst)
		return (NULL);
	(void)del;
	ptr = lst;
	res = ft_lstnew(f(ptr->content));
	while (ptr != 0)
	{
		if (res->content != 0)
			ft_lstadd_back(&res, ft_lstnew(f(ptr->content)));
		ptr = ptr->next;
	}
	return (res);
}
