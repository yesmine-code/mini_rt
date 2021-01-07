/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:06:40 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:06:55 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	check_values(t_config_map *element, t_vars *vars)
{
	if (check_values_if_rkey(element, vars) != -1
		&& check_values_if_akey(element, vars) != -1
		&& check_values_if_ckey(element, vars) != -1
		&& check_values_if_lkey(element, vars) != -1
		&& check_values_if_sp_key(element, vars) != -1
		&& check_values_if_plkey(element, vars) != -1
		&& check_values_if_sq_key(element, vars) != -1
		&& check_values_if_cy_key(element, vars) != -1
		&& check_values_if_trkey(element, vars) != -1)
		return (1);
	else
		return (-1);
}

int	check_values_if_akey(t_config_map *element, t_vars *vars)
{
	if (ft_strchr(element->key, 'A'))
	{
		if (get_num_of_non_null_value(element->value) != 2)
		{
			vars->error_msg =
				ft_strdup("number of values for A is not correct");
			return (-1);
		}
		if (check_if_limitted_float(element->value[0], 0.0, 1.0) != 1
			|| check_if_value_is_tab_of_colors(element->value[1]) != 1)
		{
			vars->error_msg =
				ft_strdup("incorrect values for A");
			return (-1);
		}
		else
			return (1);
	}
	return (0);
}

int	check_values_if_rkey(t_config_map *element, t_vars *vars)
{
	if (ft_strchr(element->key, 'R'))
	{
		if (get_num_of_non_null_value(element->value) != 2)
		{
			vars->error_msg =
				ft_strdup("number of values for R is not correct");
			return (-1);
		}
		else
		{
			if (value_is_int(element->value[0]) == 1
				&& ft_atoi(element->value[0]) > 0
				&& value_is_int(element->value[1]) == 1
				&& ft_atoi(element->value[1]) > 0)
				return (1);
			else
			{
				vars->error_msg = ft_strdup("incorrect values for R");
				return (-1);
			}
		}
	}
	return (0);
}

int	check_values_if_ckey(t_config_map *element, t_vars *vars)
{
	if (ft_strchr(element->key, 'c') && ft_strlen(element->key) == 1)
	{
		if (get_num_of_non_null_value(element->value) != 3)
		{
			vars->error_msg =
				ft_strdup("number of values for c key is not correct");
			return (-1);
		}
		if (check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1 ||
			check_n_limitted_floats_or_int(element->value[1], -1, 1, 3) != 1 ||
			check_if_value_is_an_integer_between_0_and_180(element->value[2])
			!= 1)
		{
			vars->error_msg = ft_strdup("incorrect values for c");
			return (-1);
		}
		return (1);
	}
	return (0);
}

int	get_num_of_non_null_value(char *value[])
{
	int	i;

	i = 0;
	while (value[i] != NULL)
		i++;
	return (i);
}
