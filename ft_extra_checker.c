/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:56:18 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/15 09:34:41 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				make_instructions_first(t_info *len, char *line)
{
	if (ft_strstr("sa", line) != NULL)
		operation_sa_sb(&(len->stack_a), len->a, NULL);
	else if (ft_strstr("sb", line) != NULL)
		operation_sa_sb(&(len->stack_b), len->b, NULL);
	else if (ft_strstr("ss", line) != NULL)
	{
		operation_sa_sb(&(len->stack_a), len->a, NULL);
		operation_sa_sb(&(len->stack_b), len->b, NULL);
	}
	else if (ft_strstr("pa", line) != NULL)
	{
		if (!(operation_pa_pb(len, 0, NULL)))
			return (0);
	}
	else if (ft_strstr("pb", line) != NULL)
	{
		if (!(operation_pa_pb(len, 1, NULL)))
			return (0);
	}
	return (1);
}

void			make_instructions_second(t_info *len, char *line)
{
	if (ft_strstr("ra", line) != NULL)
		operation_ra_rb(&(len->stack_a), len->a, NULL);
	else if (ft_strstr("rb", line) != NULL)
		operation_ra_rb(&(len->stack_b), len->b, NULL);
	else if (ft_strstr("rr", line) != NULL)
	{
		operation_ra_rb(&(len->stack_a), len->a, NULL);
		operation_ra_rb(&(len->stack_b), len->b, NULL);
	}
	else if (ft_strstr("rra", line) != NULL)
		operation_rra_rrb(&(len->stack_a), len->a, NULL);
	else if (ft_strstr("rrb", line) != NULL)
		operation_rra_rrb(&(len->stack_b), len->b, NULL);
	else if (ft_strstr("rrr", line) != NULL)
	{
		operation_rra_rrb(&(len->stack_a), len->a, NULL);
		operation_rra_rrb(&(len->stack_b), len->b, NULL);
	}
}

void			printing_stack_a(int number)
{
	char		*str;
	char		*temp;
	char		*temp_2;
	int			len;

	temp_2 = ft_itoa(number);
	temp = ft_strjoin("\x1b[31m", temp_2);
	ft_strdel(&temp_2);
	str = ft_strjoin(temp, "\x1b[0m");
	ft_strdel(&temp);
	len = 0;
	len = ft_strlen(str);
	write(1, str, len);
	while (len++ < 30)
		write(1, " ", 1);
	ft_strdel(&str);
}

void			printing_stack_b(int number)
{
	char		*str;
	char		*temp;
	int			len;

	temp = ft_itoa(number);
	str = ft_strjoin("\x1b[36m", temp);
	ft_strdel(&temp);
	temp = ft_strjoin(str, "\x1b[0m");
	len = ft_strlen(temp);
	write(1, temp, len);
	ft_strdel(&temp);
	ft_strdel(&str);
}

void			printing_stack(t_info *len)
{
	int			i;
	int			count;
	t_struct	*temp_a;
	t_struct	*temp_b;

	i = 0;
	temp_a = len->stack_a;
	temp_b = len->stack_b;
	count = (len->a > len->b) ? len->a : len->b;
	write(1, "\n", 1);
	printing_stack_extra(count, len, temp_a, temp_b);
	write(1, "_________________________\n", 26);
	write(1, "stack_a              stack_b\n", 29);
}
