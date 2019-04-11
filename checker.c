/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:11:26 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/15 09:35:16 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		reading_from_input(t_info **len, int fd)
{
	char		*line;

	line = NULL;
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_strstr("sa", line) != NULL || ft_strstr("sb", line) ||
		ft_strstr("ss", line) != NULL || ft_strstr("pa", line) != NULL ||
		ft_strstr("pb", line) != NULL)
		{
			if (make_instructions_first(*len, line) == 0)
				error_function(len);
		}
		else if (ft_strstr("ra", line) != NULL || ft_strstr("rb", line) != NULL
		|| ft_strstr("rr", line) != NULL || ft_strstr("rra", line) != NULL ||
		ft_strstr("rrb", line) != NULL || ft_strstr("rrr", line) != NULL)
			make_instructions_second(*len, line);
		else
			error_function(len);
		if (line)
			ft_strdel(&line);
		if ((*len)->view != 0)
			printing_stack(*len);
	}
}

int				main(int argc, char **argv)
{
	t_info		*len;
	int			i;

	i = 1;
	len = NULL;
	if (argc < 2)
		error_without_del();
	if (!(init_len(&len)))
		error_function(&len);
	if ((i = search_flags(argc, argv, i, len)) == -1)
		error_function(&len);
	checking_usage_checker(len, i, argc);
	if_all_ints(i, argc, len, argv);
	if (ft_lstunmatch(len->stack_a, len->counter) == 0)
		error_function(&len);
	len->a = len->counter;
	reading_from_input(&len, len->file);
	len->checker = check_if_ok(len->stack_a);
	if (len->checker != 0 && len->a == len->counter && len->a != 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	del_all(&len);
	return (0);
}
