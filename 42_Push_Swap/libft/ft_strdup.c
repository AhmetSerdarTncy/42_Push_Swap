/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 15:43:23 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret_val;

	ret_val = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ret_val == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret_val[i] = s1[i];
		i++;
	}
	ret_val[i] = '\0';
	return (ret_val);
}
