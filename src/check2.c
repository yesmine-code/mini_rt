/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:07:16 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:07:21 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	check_if_strings_are_n_floats(char **tab, int n)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (check_if_float(tab[i]) == 1 || value_is_int(tab[i]) == 1)
			i++;
		else
			return (-1);
	}
	if (i == n)
		return (0);
	return (-1);
}

int	check_if_value_is_tab_of_n_floats(char *value, int n)
{
	char	**tab;

	tab = ft_split(value, ',');
	if (check_if_strings_are_n_floats(tab, n) == 0)
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

int	converting_ints_or_floats(char **tab, int *i, double min, double max)
{
	char	*str;
	double	new_float;

	str = NULL;
	if (convert_char_to_float(tab[*i], &new_float) == -1)
	{
		str = ft_itoa(ft_atoi(tab[*i]));
		if (str != NULL && ft_strlen(str) == ft_strlen(tab[*i]))
			new_float = (double)ft_atoi(tab[*i]);
		else
		{
			if (str != NULL)
				free(str);
			return (-1);
		}
		if (str != NULL)
			free(str);
	}
	if (min == max || (new_float >= min && new_float <= max))
		*i = *i + 1;
	else
		return (-1);
	return (1);
}

int	check_limitted_n_floats_or_int(char **tab, double min, double max, int n)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (converting_ints_or_floats(tab, &i, min, max) == -1)
			return (-1);
	}
	if (i == n)
		return (0);
	return (-1);
}

int	check_n_limitted_floats_or_int(char *value, double min, double max, int n)
{
	char	**tab;
	int		ret;

	ret = -1;
	tab = ft_split(value, ',');
	if (check_limitted_n_floats_or_int(tab, min, max, n) == 0)
		ret = 1;
	ft_free_tab((void**)tab, 1);
	return (ret);
}
