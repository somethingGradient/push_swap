/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:26:47 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:26:49 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_general *general)
{
	t_stack	*pre_last;
	t_stack	*last;

	if (!(general->a))
		return ;
	pre_last = general->a;
	if (!pre_last->next)
		return ;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = general->a;
	general->a = last;
	if (general->checker == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_general *general)
{
	t_stack	*pre_last;
	t_stack	*last;

	if (!(general->b))
		return ;
	pre_last = general->b;
	if (!pre_last->next)
		return ;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = general->b;
	general->b = last;
	if (general->checker == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_general *general)
{
	reverse_rotate_a(general);
	reverse_rotate_b(general);
}
