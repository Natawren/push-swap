/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:56:58 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/13 17:25:59 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int					count_int(char *str)
{
	int			i;
	int			counter;
	int			temp;

	i = 0;
	counter = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			temp = 1;
		else if (str[i] == ' ' && temp != 0)
		{
			counter++;
			temp = 0;
		}
		i++;
	}
	if (temp != 0)
		counter++;
	return (counter);
}

static int			ft_len_number(long int n)
{
	int			len;

	len = 1;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int					check_int(char *argv, t_info *len)
{
	int			i;
	int			temp;
	int			j;
	int			flag_false;

	i = 0;
	flag_false = 0;
	if (!argv)
		return (0);
	temp = len->counter;
	len->counter += count_int(argv);
	while (temp < len->counter)
	{
		j = ft_atoi(&argv[i], &flag_false);
		if (flag_false == -1)
			return (0);
		ft_lstadd_back(&(len->stack_a), j);
		i += ft_len_number(j);
		while (argv[i] == ' ')
			i++;
		temp++;
	}
	return (1);
}

int					search_flags(int argc, char **argv, int i, t_info *len)
{
	while (i < argc && (ft_strcmp("-v", argv[i]) == 0 ||
		ft_strcmp("-i", argv[i]) == 0 || ft_strcmp("-f", argv[i]) == 0 ||
		ft_strcmp("-q", argv[i]) == 0 || ft_strcmp("-h", argv[i]) == 0))
	{
		if (ft_strcmp("-v", argv[i]) == 0)
			len->view = 1;
		else if (ft_strcmp("-i", argv[i]) == 0)
			len->insertion = 1;
		else if (ft_strcmp("-h", argv[i]) == 0)
			check_help_flag(len->type);
		else if (ft_strcmp("-q", argv[i]) == 0)
			len->quick = 1;
		else if (ft_strcmp("-f", argv[i++]) == 0)
		{
			len->file = 1;
			if (i == argc)
				return (i);
			if ((len->file = open(argv[i], O_RDWR)) <= 0)
				return (-1);
		}
		i++;
	}
	return (i);
}

void				move_if_len_two(t_info *push, t_key *el)
{
	if (el->first_b->content > el->second_b->content)
	{
		operation_pa_pb(push, 0, "pa\n");
		operation_pa_pb(push, 0, "pa\n");
	}
	else
	{
		operation_sa_sb(&(push->stack_b), push->b, "sb\n");
		operation_pa_pb(push, 0, "pa\n");
		operation_pa_pb(push, 0, "pa\n");
	}
	init_key(push, el);
}
