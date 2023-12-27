/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 16:43:19 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_small_a(t_stack *s)
{
	if (s->a[0] > s->a[1])
	{
		if (s->b[0] < s->b[1])
			ss(s, 0);
		else
			sa(s, 0);
	}
	return (1);
}

int	ft_sort_small_b(t_stack *s, int ln)
{
	if (ln == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, 0);
		pa(s, 0);
		pa(s, 0);
	}
	else if (ln == 3)
	{
		while (ln || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (ln == 1 && s->a[0] > s->a[1])
				sa(s, 0);
			else if (ln == 1 || (ln >= 2 && s->b[0] > s->b[1])
				|| (ln == 3 && s->b[0] > s->b[2]))
				ln = ft_push(s, ln, 1);
			else
				sb(s, 0);
		}
	}
	return (1);
}

int	ft_sort_small_a2(t_stack *s, int ln)
{
	while (ln != 3 || !(s->a[0] < s->a[1]
			&& s->a[1] < s->a[2]))
	{
		if (ln == 3 && s->a[0] > s->a[1] && s->a[2])
		{
			if ((s->a[0] > s->a[1]) && (s->b[0] < s->b[1]))
				ss(s, 0);
			else
				sa(s, 0);
		}
		else if (ln == 3 && !(s->a[2] > s->a[0]
				&& s->a[2] > s->a[1]))
			ln = ft_push(s, ln, 0);
		else if (s->a[0] > s->a[1])
			sa(s, 0);
		else if (ln++)
			pa(s, 0);
	}
	return (1);
}
