/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:38:10 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/12 13:02:42 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len_number(long int n, int base)
{
	int				len;

	len = 1;
	while (n > 1)
	{
		len++;
		n = n / base;
	}
	return (len);
}

static void			ft_transform_n_to_str(char *str,
											long int n, int base, int sign)
{
	int				i;

	i = 0;
	if (base == 10 && sign == 1)
	{
		str[0] = '-';
		sign = 0;
	}
	if (n >= base)
	{
		ft_transform_n_to_str(str, n / base, base, sign);
		ft_transform_n_to_str(str, n % base, base, sign);
	}
	else
	{
		if (n >= 10)
			n += 39;
		while (str[i] != '\0')
			i++;
		str[i] = n + '0';
	}
}

char				*ft_itoabase(int nb, int base)
{
	int				len;
	char			*str;
	int				sign;
	long int		n;

	if (base < 2 || base > 16)
		return (0);
	len = 0;
	sign = 0;
	n = (long int)nb;
	if (nb < 0 && base == 10)
	{
		n = (-1) * n;
		sign = 1;
		len++;
	}
	len += ft_len_number(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_transform_n_to_str(str, n, base, sign);
	return (str);
}
