/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:55:55 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/14 16:01:03 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		del_all(t_info **len)
{
	if (len)
	{
		if ((*len)->stack_a)
			ft_lstdel_new(&((*len)->stack_a));
		if ((*len)->stack_b)
			ft_lstdel_new(&((*len)->stack_b));
		if ((*len)->array_a)
		{
			free((*len)->array_a);
			(*len)->array_a = NULL;
		}
		free(*len);
		(*len) = NULL;
	}
}

int			init_len(t_info **len)
{
	if (!((*len) = malloc(sizeof(t_info))))
		return (0);
	(*len)->a = 0;
	(*len)->b = 0;
	(*len)->checker = 0;
	(*len)->counter = 0;
	(*len)->len = 0;
	(*len)->level = 0;
	(*len)->middle_number = 0;
	(*len)->median = 0;
	(*len)->number = 0;
	(*len)->view = 0;
	(*len)->quick = 0;
	(*len)->insertion = 0;
	(*len)->file = 0;
	(*len)->type = 0;
	(*len)->stack_a = NULL;
	(*len)->stack_b = NULL;
	(*len)->array_a = NULL;
	return (1);
}

void		init_key(t_info *push, t_key *el)
{
	el->first_a = init_key_elements(push->stack_a, 1, push->a);
	el->second_a = init_key_elements(push->stack_a, 2, push->a);
	el->last_a = init_key_elements(push->stack_a, 3, push->a);
	el->first_b = init_key_elements(push->stack_b, 1, push->b);
	el->second_b = init_key_elements(push->stack_b, 2, push->b);
	el->last_b = init_key_elements(push->stack_b, 3, push->b);
}

void		init_for_stack_b(t_info *push, t_key *el)
{
	push->level = push->stack_b->level;
	push->len = check_len_level(push->stack_b);
	push->median = finding_median_b(creating_stack_for_median(push->stack_b,
												push->b), push->len);
	push->middle_number = el->last_b->content;
}
