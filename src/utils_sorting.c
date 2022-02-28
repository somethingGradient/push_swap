/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:33:19 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:33:20 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	smaller_elem(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->value < buff && save->value > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

static void	find_place(t_general *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->value;
		if (b->value > s->a->value)
		{
			*action += 1;
			if (b->value < s->a->next->value)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (smaller_elem(s->a, *buff, b->value) == 1)
	{
		while (s->a)
		{
			if (s->a->value < *buff && s->a->value > b->value)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int	get_place(t_general *s, t_stack *b, t_steps *steps, int min)
{
	int	action;
	int	res;
	int	buff;

	action = 0;
	buff = 0;
	find_place(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}
