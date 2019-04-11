/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:43:23 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/15 10:04:59 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		checking_ifs_in_sort(t_info *push, t_key *el)
{
	if ((push->a > 1) && (el->first_a->content > el->last_a->content ||
		el->first_a->content > el->second_a->content))
		swap_three_a(push, el);
	else if (push->b > 1 && el->first_b->content < el->second_b->content)
		operation_sa_sb(&(push->stack_b), push->b, "sb\n");
	else if (push->b > 2 && el->first_b->content < el->last_b->content)
		operation_ra_rb(&(push->stack_b), push->b, "rb\n");
	else if (push->b > 1 && (el->first_a->content < el->first_b->content))
		operation_pa_pb(push, 0, "pa\n");
	else if ((push->b == 0 && push->a > 3) ||
							el->first_a->content > el->first_b->content)
	{
		if (check_if_ok(push->stack_a) == 1 &&
				(push->b == 0 || check_if_ok_reverse(push->stack_b) == 1))
			return (0);
		operation_pa_pb(push, 1, "pb\n");
	}
	else if (el->first_a->content < el->first_b->content)
		operation_pa_pb(push, 0, "pa\n");
	return (1);
}

void			sort_if_a_less_twenty(t_info *push, t_key *el)
{
	while (push->a > 0)
	{
		init_key(push, el);
		if (check_if_ok(push->stack_a) == 1 && (push->b == 0 ||
				el->first_b->content < el->first_a->content) &&
			check_if_ok_reverse(push->stack_b) == 1)
			return ;
		if (checking_ifs_in_sort(push, el) == 0)
			break ;
		init_key(push, el);
	}
}

void			push_swap(t_info *push, t_key *el)
{
	if ((push->insertion == 1 && push->quick == 1 && push->a <= 20) ||
	(push->insertion == 1 && push->quick != 1) ||
	(push->insertion == 0 && push->quick == 0 && push->a <= 20))
	{
		sort_if_a_less_twenty(push, el);
		while (push->b > 0)
			operation_pa_pb(push, 0, "pa\n");
		return ;
	}
	else
	{
		if (check_if_ok(push->stack_a) != 1)
		{
			going_throw_stack_a(push, el);
			going_throw_stack_ab(push, el);
			while (push->b > 0)
				operation_pa_pb(push, 0, "pa\n");
		}
	}
}

int				main(int argc, char **argv)
{
	t_info		*push;
	t_key		*elements;
	int			i;

	push = NULL;
	i = 1;
	if (argc < 2)
		error_without_del();
	if (!(init_len(&push)))
		error_function(&push);
	push->type = 1;
	if ((i = search_flags(argc, argv, i, push)) == -1)
		error_function(&push);
	checking_usage(push, i, argc);
	if_all_ints(i, argc, push, argv);
	if (ft_lstunmatch(push->stack_a, push->counter) == 0)
		error_function(&push);
	push->a = push->counter;
	elements = malloc(sizeof(t_key));
	init_key(push, elements);
	push_swap(push, elements);
	del_all(&push);
	free(elements);
	elements = NULL;
	return (0);
}
