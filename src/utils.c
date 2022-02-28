/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:52 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:31:53 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
}

t_stack	*add_elem(t_stack *ex, int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = number;
	if (ex)
		new->next = ex;
	else
		new->next = NULL;
	return (new);
}

int	check_sorting(t_stack *a)
{
	t_stack	*temp;

	if (!(a))
		return (0);
	temp = a;
	while (temp)
	{
		if (!temp->next)
			break ;
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	temp = stack;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	count_to_min(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
