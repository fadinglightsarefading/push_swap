/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:34:42 by cclarke           #+#    #+#             */
/*   Updated: 2026/04/27 13:34:49 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_list **head)
{
	int	tmp;

	tmp = *(int *)(*head)->content;
	*(int *)(*head)->content = *(int *)(*head)->next->content;
	*(int *)(*head)->next->content = tmp;
}

void	rotate(t_list **lst, t_list *head)
{
	t_list	*tmp;

	tmp = head;
	*lst = head->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = (NULL);
}

void	push(t_list **hence_lst, t_list *hence, t_list **hither_lst)
{
	*hence_lst = hence->next;
	ft_lstadd_front(hither_lst, hence);
}

void	reverse_rotate(t_list **lst, t_list *head)
{
	t_list	*tmp;

	tmp = ft_lstlast(head);
	while (head->next->next)
		head = head->next;
	head->next = (NULL);
	ft_lstadd_front(lst, tmp);
}
