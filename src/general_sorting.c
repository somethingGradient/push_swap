/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:10:51 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:10:52 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_index(long *arr, int start, int end)
{
	int	k;
	int	i;
	int	temp;
	int	j;

	k = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] <= k)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	return (i + 1);
}

static void	sort_arr(long *arr, int start, int end)
{
	int	i;

	if (start < end)
	{
		i = get_index(arr, start, end);
		sort_arr(arr, start, i - 1);
		sort_arr(arr, i + 1, end);
	}
}

static void	sort_3(t_general *general)
{
	int	max;

	max = find_max(general->a);
	if (general->count_a == 1)
		return ;
	else if (general->count_a == 2)
	{
		if (general->a->value > general->a->next->value)
			swap_a(general);
		return ;
	}
	else if (general->count_a == 3)
	{
		if (general->a->value == max)
			rotate_a(general);
		if (general->a->next->value == max)
			reverse_rotate_a(general);
		if (general->a->value > general->a->next->value)
			swap_a(general);
	}
}

static void	sort_5(t_general *general)
{
	while (general->count_b < 2)
	{
		if (general->a->value == general->min
			|| general->a->value == general->max)
			push_b(general);
		else
			rotate_a(general);
	}
	sort_3(general);
	push_a(general);
	push_a(general);
	if (general->a->value == general->max)
		rotate_a(general);
	else
	{
		swap_a(general);
		rotate_a(general);
	}
}

int	general_sorting(t_general *general)
{
	if (check_sorting(general->a))
		return (1);
	sort_arr(general->data->arr, 0, general->data->count - 1);
	general->min = general->data->arr[0];
	general->max = general->data->arr[general->data->count - 1];
	general->med = general->data->arr[general->count_a / 2];
	if (general->count_a <= 3)
		sort_3(general);
	else if (general->count_a <= 5)
		sort_5(general);
	else
	{
		if (!more_sort(general))
			return (0);
	}
	return (1);
}
