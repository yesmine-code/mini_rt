/*
 * check4.c
 *
 *  Created on: 25 nov. 2020
 *      Author: user42
 */

#include "minirt.h"

int check_values_if_pl_key(t_config_map *element)
{
	if(ft_strnstr(element->key, "pl", 2))
	{
		if(get_num_of_non_null_value(element->value) != 3)
		{
			ft_putstr_fd("number of values for pl key is not correct", 1);
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				check_n_limitted_floats_or_int(element->value[1], -1, 1, 3) != 1 ||
				check_if_value_is_tab_of_colors(element->value[2]) != 1)
		{
			ft_putstr_fd("incorrect values for pl", 1);
			return(-1);
		}
		return 1;
	}
	return 0;
}

int check_values_if_sq_key(t_config_map *element)
{
	if(ft_strnstr(element->key, "sq", 2))
	{
		if(get_num_of_non_null_value(element->value) != 4)
		{
			ft_putstr_fd("number of values for sq key is not correct", 1);
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				check_n_limitted_floats_or_int(element->value[1], -1, 1, 3) != 1 ||
				(Check_if_float(element->value[2]) != 1 && value_is_int(element->value[2]) != 1) ||
				check_if_value_is_tab_of_colors(element->value[3]) != 1)
		{
			ft_putstr_fd("incorrect values for sq", 1);
			return(-1);
		}
		return 1;
	}
	return 0;
}

int check_values_if_cy_key(t_config_map *element)
{
	if(ft_strnstr(element->key, "cy", 2))
	{
		if(get_num_of_non_null_value(element->value) != 5)
		{
			ft_putstr_fd("number of values for cy key is not correct", 1);
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				check_n_limitted_floats_or_int(element->value[1], -1, 1, 3) != 1 ||
				(Check_if_float(element->value[2]) != 1 && value_is_int(element->value[2]) != 1) ||
				(Check_if_float(element->value[3]) != 1 && value_is_int(element->value[3]) != 1) ||
				check_if_value_is_tab_of_colors(element->value[4]) != 1)
		{
			ft_putstr_fd("incorrect values for cy", 1);
			return(-1);
		}
		return 1;
	}
	return 0;
}

int check_values_if_tr_key(t_config_map *element)
{
	if(ft_strnstr(element->key, "tr", 2))
	{
		if(get_num_of_non_null_value(element->value) != 4)
		{
			ft_putstr_fd("number of values for tr key is not correct", 1);
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
			check_if_value_is_tab_of__floats_or_int(element->value[1]) != 1 ||
			check_if_value_is_tab_of__floats_or_int(element->value[2]) != 1 ||
			check_if_value_is_tab_of_colors(element->value[3]) != 1)
		{
			ft_putstr_fd("incorrect values for tr", 1);
			return(-1);
		}
		return 1;
	}
	return 0;
}
