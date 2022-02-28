/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:26:15 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:26:16 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_general *general)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!(general->a))
		return ;
	first = general->a;
	second = general->a->next;
	if (!first->next)
		return ;
	last = general->a;
	while (last->next)
		last = last->next;
	general->a->next = NULL;
	last->next = first;
	general->a = second;
	if (general->checker == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_general *general)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!(general->b))
		return ;
	first = general->b;
	second = general->b->next;
	if (!first->next)
		return ;
	last = general->b;
	while (last->next)
		last = last->next;
	general->b->next = NULL;
	last->next = first;
	general->b = second;
	if (general->checker == 0)
		write(1, "rb\n", 3);
}

void	rr(t_general *general)
{
	rotate_a(general);
	rotate_b(general);
}
