/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:04:39 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/15 09:33:48 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			if_all_ints(int i, int argc, t_info *push, char **argv)
{
	while (i < argc)
	{
		if (!(check_int(argv[i], push)))
			error_function(&push);
		i++;
	}
}

void			checking_usage(t_info *push, int i, int argc)
{
	if (push->file > 0 || push->view == 1)
	{
		ft_putstr("./push_swap: illegal option\n");
		print_usage(1);
	}
	if (i >= argc)
	{
		ft_putstr("./push_swap: need some integers\n");
		print_usage(1);
	}
}

void			checking_usage_checker(t_info *len, int i, int argc)
{
	if (i >= argc && (len->view == 1 || len->file > 0))
	{
		ft_putstr("./checker: not enouth args\n");
		print_usage(0);
	}
	if (len->insertion == 1 || len->quick == 1)
	{
		ft_putstr("./checker: illegal option\n");
		print_usage(0);
	}
}

void			printing_stack_extra(int count, t_info *len,
					t_struct *temp_a, t_struct *temp_b)
{
	int		i;
	int		space;

	i = -1;
	while (++i < count)
	{
		space = 15;
		if (count - i <= len->a && len->a > 0)
		{
			printing_stack_a(temp_a->content);
			temp_a = temp_a->next;
		}
		else
		{
			space += 6;
			while (space--)
				write(1, " ", 1);
		}
		if (count - i <= len->b && len->b > 0)
		{
			printing_stack_b(temp_b->content);
			temp_b = temp_b->next;
		}
		write(1, "\n", 1);
	}
}

void			extrackt_teil_from_going_throw(t_info *push, t_key *el)
{
	if (el->first_a->content > el->second_a->content)
		operation_sa_sb(&(push->stack_a), push->a, "sa\n");
	push->stack_a->level = push->stack_a->next->content;
	push->stack_a->next->level = push->stack_a->content;
	init_key(push, el);
}
