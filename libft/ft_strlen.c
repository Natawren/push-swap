/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:38:10 by mnarbert          #+#    #+#             */
/*   Updated: 2018/11/30 14:02:38 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t		i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
