/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 15:43:23 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_seperation(t_stack *stack, int len)
{
	int	pivot_a;
	int	pivot_b;
	int	items;

	items = len;
	ft_get_middle(&pivot_a, stack->a, len);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot_a && (len--))
			pb(stack, 0);
		else
		{
			ft_get_middle(&pivot_b, stack->b, stack->size_b);
			if ((stack->b[0] <= pivot_b) && (stack->size_b > 2))
				rr(stack, 0);
			else
				ra(stack, 0);
		}
	}
	ft_quicksort_a(stack, items / 2 + items % 2, 0);
	ft_quicksort_b(stack, items / 2, 0);
	return (1);
}

int	ft_quicksort_a(t_stack *stack, int len, int count)
{
	int	pivot_a;
	int	items;

	if (ft_is_sorted(stack->a, len, 0) == 1)
		return (1);
	if (len == 2)
		return (ft_sort_small_a(stack));
	else if (len == 3 && stack->size_a == 3)
		return (ft_sort_three(stack));
	else if (len == 3)
		return (ft_sort_small_a2(stack, len));
	ft_get_middle(&pivot_a, stack->a, len);
	items = len;
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot_a && (len--))
			pb(stack, 0);
		else if (++count)
			ra(stack, 0);
	}
	while (items / 2 + items % 2 != stack->size_a && count--)
		rra(stack, 0);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0),
		ft_quicksort_b(stack, items / 2, 0));
}

int	ft_quicksort_b(t_stack *stack, int len, int count)
{
	int	pivot_b;
	int	items;

	if (!count && ft_is_sorted(stack->b, len, 1) == 1)
		while (len--)
			pa(stack, 0);
	if (len <= 3)
		return (ft_sort_small_b(stack, len));
	ft_get_middle(&pivot_b, stack->b, len);
	items = len;
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot_b && (len--))
			pa(stack, 0);
		else if (++count)
			rb(stack, 0);
	}
	while (items / 2 != stack->size_b && count--)
		rrb(stack, 0);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0),
		ft_quicksort_b(stack, items / 2, 0));
	return (1);
}
