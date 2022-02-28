/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:14:43 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:14:45 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_stacks(t_general *general)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	a = NULL;
	b = NULL;
	i = -1;
	while (++i < general->data->count)
	{
		a = add_elem(a, general->data->arr[general->data->count - i - 1]);
		if (!a)
			return (0);
	}
	general->a = a;
	general->b = b;
	return (1);
}

void	clear_stacks(t_general *general)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		i;

	i = general->data->count;
	while (i-- > 0)
	{
		if (general->a)
		{
			temp_a = general->a->next;
			free(general->a);
			general->a = temp_a;
		}
		if (general->b)
		{
			temp_b = general->b->next;
			free(general->b);
			general->b = temp_b;
		}
	}
	general->a = NULL;
	general->b = NULL;
}

void	cleaning_service(t_general *general)
{
	clear_stacks(general);
	free(general->data->arr);
	free(general->data);
	free(general);
}

int	main(int argc, char const *argv[])
{
	t_general	*general;

	general = NULL;
	general = (t_general *)malloc(sizeof(*general));
	general->count_a = 0;
	general->count_b = 0;
	general->checker = 0;
	general->data = NULL;
	if (!general)
		exit (0);
	get_data(argc, argv, general);
	if (!create_stacks(general))
	{
		error();
		cleaning_service(general);
		exit (0);
	}
	general_sorting(general);
	cleaning_service(general);
	return (0);
}
