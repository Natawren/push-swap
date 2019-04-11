/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:22:46 by mnarbert          #+#    #+#             */
/*   Updated: 2019/01/29 18:19:57 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		compare(int *tab, int length)
{
	int		i;

	i = 0;
	while (i < length - 1)
	{
		if (tab[i] == (tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		j;
	int		temp;

	j = 1;
	i = 0;
	if (length <= 0)
		return (0);
	while (i < length - 1)
	{
		while (j < length)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (compare(tab, length));
}
