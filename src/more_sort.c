/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:15:18 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:15:19 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	execute(t_general *general, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			rotate_a(general);
		else
			reverse_rotate_a(general);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			rotate_b(general);
		else
			reverse_rotate_b(general);
		steps->count_b--;
	}
	push_a(general);
}

static void	minimum_insertion_steps(t_general *general, t_steps *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	steps->count_a = -1;
	steps->count_b = -1;
	steps->dest_a = 0;
	steps->dest_b = 0;
	min_action = -1;
	first_a = general->a;
	first_b = general->b;
	while (general->b)
	{
		min_action = get_place(general, general->b,
				steps, min_action);
		general->a = first_a;
		general->b = general->b->next;
	}
	general->b = first_b;
}

static void	steps_markup(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*temp;

	i = -1;
	iter = count / 2;
	temp = b;
	while (++i <= iter)
	{
		temp->step = i;
		temp->rotate = 1;
		temp = temp->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		temp->step = i;
		temp->rotate = -1;
		temp = temp->next;
	}
}

static int	sorting(t_general *general)
{
	t_steps	*steps;

	steps = NULL;
	steps = (t_steps *)malloc(sizeof(*steps));
	if (!steps)
		return (0);
	while (general->count_b != 0)
	{
		steps_markup(general->a, general->count_a);
		steps_markup(general->b, general->count_b);
		minimum_insertion_steps(general, steps);
		execute(general, steps);
	}
	if ((count_to_min(general->a, general->min))
		> general->count_a / 2)
	{
		while (general->a->value != general->min)
			reverse_rotate_a(general);
	}
	else
		while (general->a->value != general->min)
			rotate_a(general);
	free(steps);
	return (1);
}

int	more_sort(t_general *general)
{
	while (general->count_a > 2)
	{
		if (general->a->value != general->min
			&& general->a->value != general->max)
		{	
			push_b(general);
			if (general->a->value > general->med)
				rotate_b(general);
		}
		else
			rotate_a(general);
	}
	if (general->a->value < general->a->next->value)
		swap_a(general);
	push_a(general);
	if (!sorting(general))
		return (0);
	return (1);
}
