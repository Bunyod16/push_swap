/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <bshamsid@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:24:45 by bshamsid          #+#    #+#             */
/*   Updated: 2021/10/01 02:24:45 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ps_lstnew(int content)
{
	t_lst	*ret;

	ret = (t_lst *)malloc(sizeof(t_lst));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->split = -1;
	ret->next = NULL;
	return (ret);
}

int	lst_len(t_lst *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ps_lstadd_back(t_lst **lst, int value)
{
	t_lst	*node;

	if (!*lst)
	{
		node = malloc(sizeof(t_lst *));
		node->content = value;
		node->next = NULL;
		node->split = 0;
		*lst = node;
	}
	else
	{
		while (*lst)
			lst = &(*lst)->next;
		node = ps_lstnew(value);
		*lst = node;
	}
}

t_lst	*last_item(t_lst *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
