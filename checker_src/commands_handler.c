/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:47:27 by akitty            #+#    #+#             */
/*   Updated: 2022/02/27 12:47:29 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	get_next_line(char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buf;

	rd = 1;
	i = 0;
	buf = malloc(5);
	if (!buf)
		return (0);
	*line = buf;
	while (rd > 0 && ch != '\n')
	{
		rd = read(0, &ch, 1);
		buf[i++] = ch;
	}
	buf[i] = '\0';
	return (rd);
}

static void	execute(char *str, t_general *general)
{
	if (!ft_strcmp(str, "sa\n"))
		swap_a(general);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b(general);
	else if (!ft_strcmp(str, "ss\n"))
		ss(general);
	else if (!ft_strcmp(str, "pa\n"))
		push_a(general);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(general);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a(general);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b(general);
	else if (!ft_strcmp(str, "rr\n"))
		rr(general);
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate_a(general);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate_b(general);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(general);
}

int	commands_handler(t_general *general)
{
	int		i;
	char	*str;
	int		rd;

	str = NULL;
	rd = 1;
	i = 0;
	while (rd)
	{
		rd = get_next_line(&str);
		execute(str, general);
		free(str);
	}
	if (check_sorting(general->a) && general->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}
