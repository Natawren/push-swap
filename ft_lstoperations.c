/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstoperations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:56:43 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/12 11:00:27 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_struct	*ft_lstnew_new(int content)
{
	t_struct		*new;

	if (!(new = malloc(sizeof(t_struct))))
		return (NULL);
	new->content = content;
	new->level = 0;
	new->next = NULL;
	return (new);
}

void		ft_lstdel_new(t_struct **alst)
{
	t_struct		*temp;

	if (alst)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			free(*alst);
			*alst = temp;
		}
		*alst = NULL;
	}
}

t_struct	*ft_lstadd_new(t_struct **begin_list, int data)
{
	t_struct		*new_element;

	if (!(*begin_list))
	{
		if (!(*begin_list = ft_lstnew_new(data)))
			return (NULL);
	}
	else
	{
		if (!(new_element = ft_lstnew_new(data)))
			return (NULL);
		new_element->next = *begin_list;
		*begin_list = new_element;
	}
	return (*begin_list);
}

void		ft_lstadd_back(t_struct **begin_list, int content)
{
	t_struct		*last_element;
	t_struct		*first_element;

	last_element = ft_lstnew_new(content);
	if (!(*begin_list))
		*begin_list = last_element;
	else
	{
		first_element = *begin_list;
		while ((*begin_list)->next != NULL)
			*begin_list = (*begin_list)->next;
		(*begin_list)->next = last_element;
		*begin_list = first_element;
	}
}

int			ft_lstunmatch(t_struct *stack, int length)
{
	t_struct		*temp;
	t_struct		*temp2;

	temp = stack;
	temp2 = stack->next;
	if (length <= 0)
		return (0);
	while (temp->next && temp2)
	{
		while (temp2)
		{
			if (temp->content == temp2->content)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = temp->next;
	}
	return (1);
}
