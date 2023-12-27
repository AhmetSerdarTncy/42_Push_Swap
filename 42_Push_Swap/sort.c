/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 16:36:43 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] && s2[a] && s1[a] == s2[a])
		++a;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

int	ft_is_num(char *s)
{
	int	a;

	a = 0;
	if (s[a] == '-')
		a++;
	if (s[a] == '\0')
		return (0);
	while (s[a])
	{
		if (!(ft_isdigit(s[a])))
			return (0);
		a++;
	}
	return (1);
}

int	ft_is_sorted(int *stack_a, int size, int flag)
{
	int	a;

	a = 0;
	while ((flag == 0) && (++a < size))
	{
		if (stack_a[a - 1] > stack_a[a])
			return (0);
	}
	while ((flag == 1) && (++a < size))
	{
		if (stack_a[a - 1] < stack_a[a])
			return (0);
	}
	return (1);
}

void	ft_check_repeat(t_stack *stack, int size, char **av, int control)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				ft_free_av(av, stack, control);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_sort(t_stack *stack, int size)
{
	if (ft_is_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			sa(stack, 0);
		else if (size == 3)
			ft_sort_three(stack);
		else
			ft_first_seperation(stack, size);
	}
	return (1);
}
