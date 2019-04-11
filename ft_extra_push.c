/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:30:58 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/13 15:30:59 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_struct	*init_key_elements(t_struct *stack, int counter, int len)
{
	t_struct		*temp;

	temp = NULL;
	if (!stack)
		return (NULL);
	if (counter == 1)
		temp = stack;
	else if (counter == 2 && len > 1)
		temp = stack->next;
	else if (counter == 3 && len >= 2)
	{
		temp = stack;
		while (temp->next)
			temp = temp->next;
	}
	return (temp);
}

void		swap_three_a(t_info *push, t_key *el)
{
	if (push->a == 2 && el->first_a->content > el->second_a->content)
		operation_sa_sb(&(push->stack_a), push->a, "sa\n");
	else if (el->first_a->content > el->last_a->content &&
			el->last_a->content > el->second_a->content && push->a <= 3)
		operation_ra_rb(&(push->stack_a), push->a, "ra\n");
	else if (el->first_a->content > el->last_a->content &&
			el->last_a->content > el->second_a->content && push->a > 3)
		operation_sa_sb(&(push->stack_a), push->a, "sa\n");
	else if (el->first_a->content > el->second_a->content &&
			el->second_a->content > el->last_a->content)
		operation_sa_sb(&(push->stack_a), push->a, "sa\n");
	else if (el->first_a->content > el->second_a->content &&
				el->first_a->content < el->last_a->content)
		operation_sa_sb(&(push->stack_a), push->a, "sa\n");
	else if (el->first_a->content > el->last_a->content &&
			el->last_a->content < el->second_a->content)
		operation_rra_rrb(&(push->stack_a), push->a, "rra\n");
	else if (el->first_a->content < el->last_a->content &&
			el->last_a->content < el->second_a->content)
		operation_rra_rrb(&(push->stack_a), push->a, "rra\n");
}

int			check_if_only_one_lvl(t_struct *stack)
{
	t_struct		*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->level != temp->next->level)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int			check_if_ok(t_struct *stack)
{
	t_struct		*temp;
	t_struct		*temp_2;

	if (!stack)
		return (1);
	temp = stack;
	temp_2 = stack->next;
	while (temp->next)
	{
		while (temp_2)
		{
			if (temp->content < temp_2->content)
				temp_2 = temp_2->next;
			else
				return (0);
		}
		temp = temp->next;
		temp_2 = temp->next;
	}
	return (1);
}

int			check_if_ok_reverse(t_struct *stack)
{
	t_struct		*temp;
	t_struct		*temp_2;

	if (!stack)
		return (1);
	temp = stack;
	temp_2 = stack->next;
	while (temp->next)
	{
		while (temp_2)
		{
			if (temp->content > temp_2->content)
				temp_2 = temp_2->next;
			else
				return (0);
		}
		temp = temp->next;
		temp_2 = temp->next;
	}
	return (1);
}
