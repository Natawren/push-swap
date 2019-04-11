/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:08:45 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/14 16:12:20 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		error_function(t_info **len)
{
	write(2, "Error\n", 6);
	del_all(len);
	exit(0);
}

void		error_without_del(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void		check_help_flag(int number)
{
	if (number == 0)
		print_usage(0);
	print_usage(1);
}

void		print_usage(int flag)
{
	if (flag == 0)
	{
		ft_putstr("usage: ./checker [<options>] <integers of stack, the first");
		ft_putstr(" argument will be at the top of the stack>\n");
		write(1, "\n", 1);
		ft_putstr("    -h            help\n");
		ft_putstr("    -f <file>     reads instructions from file\n");
		ft_putstr("    -v            displays the stack’s status after each");
		ft_putstr(" operation\n");
		write(1, "\n", 1);
		exit(0);
	}
	ft_putstr("usage: ./push_swap [<options>] <integers of stack, the first");
	ft_putstr(" argument will be at the top of the stack>\n");
	write(1, "\n", 1);
	ft_putstr("    -h            help\n");
	ft_putstr("    -q            uses only quick sort\n");
	ft_putstr("    -i            uses only insertion sort.\n");
	ft_putstr("                  If options -q and -i are used together,\n");
	ft_putstr("                  on array, that less then 20 ints, is used");
	ft_putstr(" insertion sort,\n");
	ft_putstr("                  otherwise - quick sort\n");
	write(1, "\n", 1);
	exit(0);
}
