/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:58:16 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/12 13:20:06 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		operation_sa_sb(t_struct **stack, int len, char *str)
{
	t_struct		*temp_2;

	if (len > 1)
	{
		temp_2 = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		temp_2->next = (*stack);
		(*stack) = temp_2;
	}
	if (str != NULL)
		write(1, str, 3);
}

static int	operation_pb(t_info *push, t_struct *temp_1)
{
	if (!(push->stack_a))
		return (0);
	temp_1 = push->stack_a;
	push->stack_a = push->stack_a->next;
	temp_1->next = push->stack_b;
	push->stack_b = temp_1;
	(push->a)--;
	(push->b)++;
	return (1);
}

int			operation_pa_pb(t_info *push, int flag, char *str)
{
	t_struct		*temp_1;

	temp_1 = NULL;
	if (flag == 0)
	{
		if (!(push->stack_b))
			return (0);
		temp_1 = push->stack_b;
		push->stack_b = push->stack_b->next;
		temp_1->next = push->stack_a;
		push->stack_a = temp_1;
		(push->b)--;
		(push->a)++;
	}
	else
	{
		if (operation_pb(push, temp_1) == 0)
			return (0);
	}
	if (str != NULL)
		write(1, str, 3);
	return (1);
}

void		operation_ra_rb(t_struct **stack, int len, char *str)
{
	t_struct		*temp_1;
	t_struct		*temp_2;

	if (len > 1)
	{
		temp_1 = (*stack);
		(*stack) = (*stack)->next;
		temp_1->next = NULL;
		temp_2 = (*stack);
		while ((*stack)->next != NULL)
			(*stack) = (*stack)->next;
		(*stack)->next = temp_1;
		(*stack) = temp_2;
	}
	if (str != NULL)
		write(1, str, 3);
}

void		operation_rra_rrb(t_struct **stack, int len, char *str)
{
	t_struct		*temp_1;
	t_struct		*temp_2;

	if (len > 1)
	{
		temp_1 = (*stack);
		while ((*stack)->next->next != NULL)
			(*stack) = (*stack)->next;
		temp_2 = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = temp_1;
		temp_2->next = (*stack);
		(*stack) = temp_2;
	}
	if (str != NULL)
		write(1, str, 4);
}
