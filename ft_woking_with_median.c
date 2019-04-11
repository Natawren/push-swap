/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_woking_with_median.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:12:26 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/12 10:07:16 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	finding_half_of_stack(t_struct *temp, int len)
{
	int				number;

	number = -1;
	while (++number < len / 2)
		temp = temp->next;
	return (temp->content);
}

int			finding_median(t_struct *stack, int len)
{
	t_struct		*temp;
	t_struct		*temp_2;
	int				number;

	temp = stack;
	temp_2 = stack->next;
	while (temp->next)
	{
		while (temp_2)
		{
			if (temp->content > temp_2->content)
			{
				number = temp->content;
				temp->content = temp_2->content;
				temp_2->content = number;
			}
			temp_2 = temp_2->next;
		}
		temp = temp->next;
		temp_2 = temp->next;
	}
	temp = stack;
	number = finding_half_of_stack(temp, len);
	ft_lstdel_new(&stack);
	return (number);
}

int			finding_median_b(t_struct *stack, int len)
{
	t_struct		*temp;
	t_struct		*temp_2;
	int				number;

	temp = stack;
	temp_2 = stack->next;
	while (temp->next)
	{
		while (temp_2)
		{
			if (temp->content < temp_2->content)
			{
				number = temp->content;
				temp->content = temp_2->content;
				temp_2->content = number;
			}
			temp_2 = temp_2->next;
		}
		temp = temp->next;
		temp_2 = temp->next;
	}
	temp = stack;
	number = finding_half_of_stack(temp, len);
	ft_lstdel_new(&stack);
	return (number);
}

t_struct	*creating_stack_for_median(t_struct *stack, int len)
{
	t_struct		*new_stack;
	t_struct		*temp;
	int				i;

	i = 0;
	new_stack = NULL;
	temp = stack;
	while (i < len && temp)
	{
		ft_lstadd_back(&new_stack, temp->content);
		temp = temp->next;
	}
	return (new_stack);
}

int			check_len_level(t_struct *stack)
{
	int				level;
	int				counter;
	t_struct		*temp;

	if (!stack)
		return (-1);
	temp = stack;
	counter = 0;
	level = stack->level;
	while (temp && temp->level == level)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}
