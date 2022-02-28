/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:11 by akitty            #+#    #+#             */
/*   Updated: 2022/02/21 15:31:12 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}	t_steps;

typedef struct s_data
{
	long	*arr;
	int		count;
}	t_data;

typedef struct s_stack
{
	int				step;
	int				rotate;
	int				tag;
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_general
{
	int			checker;
	int			count_a;
	int			count_b;
	int			min;
	int			max;
	int			med;
	t_data		*data;
	t_stack		*a;
	t_stack		*b;
}	t_general;

long		ft_atol(const char *str);
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
void		*ft_calloc(size_t n, size_t size);
void		*ft_memset(void *s, int c, size_t n);

int			get_data(int argc, char const *argv[], t_general *general);

void		error(void);
t_stack		*add_elem(t_stack *ex, int number);
int			check_sorting(t_stack *a);
int			find_max(t_stack *stack);
int			count_to_min(t_stack *a, int min);
void		clear_stacks(t_general *general);
void		cleaning_service(t_general *general);

int			general_sorting(t_general *general);
int			more_sort(t_general *general);
int			get_place(t_general *s, t_stack *b, t_steps *steps, int min);

void		swap_a(t_general *general);
void		swap_b(t_general *general);
void		ss(t_general *general);
void		push_a(t_general *general);
void		push_b(t_general *general);

void		rotate_a(t_general *general);
void		rotate_b(t_general *general);
void		rr(t_general *general);

void		reverse_rotate_a(t_general *general);
void		reverse_rotate_b(t_general *general);
void		rrr(t_general *general);

#endif
