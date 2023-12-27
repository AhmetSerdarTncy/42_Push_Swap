/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 16:39:37 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"

void	ft_push_swap(char **av, int control)
{
	t_stack	*stack;
	int		sze;
	int		a;

	a = -1;
	stack = malloc(sizeof(t_stack));
	sze = ft_ps_strlen(av);
	stack->a = malloc(sizeof(int) * sze);
	if (!stack->a)
		return ;
	stack->size_a = sze;
	stack->b = malloc(sizeof(int) * sze);
	if (!stack->b)
	{
		free (stack->a);
		return ;
	}
	stack->size_b = 0;
	while (++a < sze)
		stack->a[a] = ft_ps_atoi(av[a], stack, av, control);
	ft_check_repeat(stack, sze, av, control);
	ft_sort(stack, sze);
	free (stack->a);
	free (stack->b);
	free (stack);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		av++;
		av = ft_split(*av, ' ');
		ft_push_swap(av, 2);
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	else
		ft_push_swap(++av, 1);
	return (0);
}
