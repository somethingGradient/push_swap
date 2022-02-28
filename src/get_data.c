/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:12:15 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:12:16 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	validate_chars(char const *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == ',' || str[i] == ' '
			|| str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	add_number(char const *str, long arr[], int *index)
{
	char	**numbers;
	int		i;

	i = -1;
	if (ft_strchr(str, ' ') || ft_strchr(str, ','))
	{
		if (ft_strchr(str, ' ') && !ft_strchr(str, ','))
			numbers = ft_split(str, ' ');
		else if (ft_strchr(str, ',') && !ft_strchr(str, ' '))
			numbers = ft_split(str, ',');
		else
			return (0);
		while (numbers[++i])
		{
			arr[(*index)++] = ft_atol(numbers[i]);
			free(numbers[i]);
		}
		free(numbers);
	}
	else
		arr[(*index)++] = ft_atol(str);
	return (1);
}

static int	check_argv(int argc, char const *argv[], t_data *data)
{
	long	*arr;
	int		index;
	int		i;

	if (argc > 1)
	{
		arr = calloc(sizeof(long), 5000);
		index = 0;
		i = 0;
		while (++i < argc)
		{
			if (!validate_chars(argv[i])
				|| !add_number(argv[i], arr, &index))
			{
				error();
				free(arr);
				return (0);
			}
		}
	}
	else
		return (0);
	data->count = index;
	data->arr = arr;
	return (1);
}

static int	check_dups_maxint(t_data *data)
{
	int	i;
	int	k;

	i = -1;
	while (++i < data->count)
	{
		k = i;
		while (++k < data->count)
		{
			if (data->arr[i] == data->arr[k])
				return (0);
		}
		if (((long)data->arr[i] > 2147483647)
			|| ((long)data->arr[i] <= -2147483649))
			return (0);
	}
	return (1);
}

int	get_data(int argc, char const *argv[], t_general *general)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(*(data)));
	if (!data)
	{
		free(general);
		exit (1);
	}
	if (!check_argv(argc, argv, data))
	{
		free(data);
		free(general);
		exit (1);
	}
	if (!check_dups_maxint(data))
	{
		error();
		free(data->arr);
		free(data);
		free(general);
		exit (1);
	}
	general->data = data;
	general->count_a = general->data->count;
	return (1);
}
