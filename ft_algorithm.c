/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:21:01 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/15 09:33:59 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		going_throw_stack_a_level_by_level(t_info *push, t_key *el)
{
	while (push->a > 0 && push->level == push->stack_a->level)
	{
		if (el->first_a->content == push->middle_number)
		{
			if (el->first_a->content < push->median)
			{
				push->stack_a->level = push->median;
				operation_pa_pb(push, 1, "pb\n");
				init_key(push, el);
			}
			break ;
		}
		if (el->first_a->content < push->median)
		{
			push->stack_a->level = push->median;
			operation_pa_pb(push, 1, "pb\n");
		}
		else if (el->first_a->content >= push->median)
			operation_ra_rb(&(push->stack_a), push->a, "ra\n");
		init_key(push, el);
		push->len = check_len_level(push->stack_a);
	}
}

void		going_throw_stack_b_level_by_level(t_info *push, t_key *el)
{
	while (push->b > 0 && push->level == push->stack_b->level)
	{
		if (push->len == 1 && el->first_b->content < el->first_a->content
								&& el->first_b->level != el->last_b->level)
		{
			operation_pa_pb(push, 0, "pa\n");
			init_key(push, el);
			break ;
		}
		if (el->first_b->content == push->middle_number)
		{
			if (el->first_b->content > push->median)
			{
				operation_pa_pb(push, 0, "pa\n");
				init_key(push, el);
			}
			break ;
		}
		if (push->b > 0 && el->first_b->content > push->median)
			operation_pa_pb(push, 0, "pa\n");
		else if (push->b > 0 && el->first_b->content <= push->median)
			operation_ra_rb(&(push->stack_b), push->b, "rb\n");
		init_key(push, el);
		push->len = check_len_level(push->stack_b);
	}
}

void		return_to_beginning_of_level(t_info *push, t_key *el, int flag)
{
	if (flag == 1)
	{
		while (push->a > 3 && el->last_a->level == push->level
								&& check_if_only_one_lvl(push->stack_a) != 0)
		{
			operation_rra_rrb(&(push->stack_a), push->a, "rra\n");
			init_key(push, el);
		}
	}
	else if (flag == 0)
	{
		while (push->b > 0 && el->last_b->level == push->level &&
							check_if_only_one_lvl(push->stack_b) != 0)
		{
			operation_rra_rrb(&(push->stack_b), push->b, "rrb\n");
			init_key(push, el);
		}
	}
}

void		going_throw_stack_a(t_info *push, t_key *el)
{
	if (push->stack_a && check_if_ok(push->stack_a) == 1 && (push->b == 0 ||
			push->len <= 2 || el->first_a->content > el->first_b->content))
		return ;
	push->len = check_len_level(push->stack_a);
	push->number = push->a - push->len;
	while (push->a > push->number)
	{
		push->len = check_len_level(push->stack_a);
		push->level = el->first_a->level;
		push->median = finding_median(creating_stack_for_median(push->stack_a,
														push->a), push->len);
		if (push->len == 1)
		{
			push->stack_a->level = push->stack_a->content;
			return ;
		}
		if (push->len == 2)
		{
			extrackt_teil_from_going_throw(push, el);
			return ;
		}
		push->middle_number = el->last_a->content;
		going_throw_stack_a_level_by_level(push, el);
		return_to_beginning_of_level(push, el, 1);
	}
}

void		going_throw_stack_ab(t_info *push, t_key *el)
{
	while (push->b > 0)
	{
		if (check_if_ok(push->stack_a) == 1 &&
			check_if_ok_reverse(push->stack_b) == 1 &&
				el->first_b->content < el->first_a->content)
			return ;
		init_for_stack_b(push, el);
		if (push->len == 2 && check_if_ok(push->stack_a) == 1 &&
						el->first_b->content < el->first_a->content)
		{
			move_if_len_two(push, el);
			continue;
		}
		if (push->len == 1 && el->first_b->content < el->first_a->content)
		{
			operation_pa_pb(push, 0, "pa\n");
			init_key(push, el);
			continue;
		}
		init_key(push, el);
		going_throw_stack_b_level_by_level(push, el);
		return_to_beginning_of_level(push, el, 0);
		going_throw_stack_a(push, el);
	}
}
