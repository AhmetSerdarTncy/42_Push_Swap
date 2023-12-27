/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 15:43:23 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	**av;
}	t_stack;

int		singular_exec(t_stack *stack, char *instruction, int control);
int		doubles_exec(t_stack *stack, char *instruction);
void	ft_get_checker(t_stack *stack, int control);
void	ft_checker(char **av, int control);

void	free_error(t_stack *stack, int num, int control);
void	ft_free_av(char **av, t_stack *stack, int control);
void	ft_error(t_stack *stack);

char	*get_next_line(int fd);

void	ft_push_swap(char **av, int control);

int		ft_first_seperation(t_stack *stack, int len);
int		ft_quicksort_a(t_stack *stack, int len, int count);
int		ft_quicksort_b(t_stack *stack, int len, int count);

void	pa(t_stack *stack, int print);
void	sa(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	rra(t_stack *stack, int print);

void	pb(t_stack *stack, int print);
void	sb(t_stack	*stack, int print);
void	rb(t_stack	*stack, int print);
void	rrb(t_stack *stack, int print);

void	ss(t_stack	*stack, int print);
void	rr(t_stack	*stack, int print);
void	rrr(t_stack *stack, int print);

int		ft_push(t_stack *stack, int len, int operation);
int		ft_sort_three(t_stack *s);
void	ft_bubble_sort(int *tmp_stack, int size);
int		ft_get_middle(int *pivot, int *stack_a, int size);

int		ft_sort_small_a(t_stack *s);
int		ft_sort_small_a2(t_stack *s, int len);
int		ft_sort_small_b(t_stack *s, int len);

int		ft_strcmp(char *s1, char *s2);
int		ft_is_num(char *s);
int		ft_is_sorted(int *stack_a, int size, int flag);
int		ft_sort(t_stack *stack, int size);
void	ft_check_repeat(t_stack *stack, int size, char **av, int control);

int		ft_ps_strlen(char **str);
int		ft_ps_atoi_(char *str, int *sign);
int		ft_ps_atoi(char *str, t_stack *stack, char **av, int control);

#endif