/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:15:23 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:15:25 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	check_if_value_is_tab_of_colors(char *value)
{
	char	**tab;

	tab = ft_split(value, ',');
	if (check_if_strings_can_be_integer(tab) == 0)
	{
		ft_free_tab((void **)tab, 1);
		return (1);
	}
	else
	{
		ft_free_tab((void **)tab, 1);
		return (-1);
	}
}

int	check_if_strings_can_be_integer(char **tab)
{
	int		i;
	char	*str;

	i = 0;
	while (tab[i] != NULL)
	{
		str = ft_itoa(ft_atoi(tab[i]));
		if (str != NULL && ft_strlen(str) == ft_strlen(tab[i])
			&& ft_atoi(tab[i]) >= 0 && ft_atoi(tab[i]) <= 255)
			i++;
		else
		{
			if (str != NULL)
				free(str);
			return (-1);
		}
		if (str != NULL)
			free(str);
	}
	if (i == 3)
		return (0);
	else
		return (-1);
}
