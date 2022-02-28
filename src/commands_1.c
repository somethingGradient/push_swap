/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:24:25 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:24:26 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_general *general)
{
	int	temp;

	if (!general->a || !general->a->next)
		return ;
	temp = general->a->next->value;
	general->a->next->value = general->a->value;
	general->a->value = temp;
	if (general->checker == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_general *general)
{
	int	temp;

	if (!general->b || !general->b->next
		|| general->b->next->value == -1)
		return ;
	temp = general->b->next->value;
	general->b->next->value = general->b->value;
	general->b->value = temp;
	if (general->checker == 0)
		write(1, "sb\n", 3);
}

void	ss(t_general *general)
{
	swap_a(general);
	swap_b(general);
}

void	push_a(t_general *general)
{
	t_stack	*begin_b;

	if (!(general->b))
		return ;
	begin_b = general->b;
	if (!(general->b) && !(general->b)->next)
		return ;
	general->count_a += 1;
	general->count_b -= 1;
	general->b = (general->b)->next;
	begin_b->next = general->a;
	general->a = begin_b;
	if (general->checker == 0)
		write(1, "pa\n", 3);
}

void	push_b(t_general *general)
{
	t_stack	*begin_a;

	if (!(general->a))
		return ;
	begin_a = general->a;
	if (!(general->a) && !(general->a)->next)
		return ;
	general->count_b += 1;
	general->count_a -= 1;
	general->a = (general->a)->next;
	begin_a->next = general->b;
	general->b = begin_a;
	if (general->checker == 0)
		write(1, "pb\n", 3);
}
