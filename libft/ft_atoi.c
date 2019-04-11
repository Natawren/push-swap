/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:54:30 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/13 15:58:58 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str, int *flag_false)
{
	int					i;
	long int			n;
	int					minus;

	n = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
						|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = 10 * n + (str[i++] - '0');
	if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '\t'
		&& str[i] != '\n' && str[i] != '\v' && str[i] != '\f' && str[i] != '\r'
		&& str[i] != '\0' && str[i] != '-' && str[i] != '+')
		(*flag_false) = -1;
	n = minus * n;
	if (n > 2147483647 || n < -2147483648)
		(*flag_false) = -1;
	return (n);
}
