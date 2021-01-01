/*
 * check2.c
 *
 *  Created on: 1 janv. 2021
 *      Author: user42
 */



#include "minirt.h"

int	check_if_strings_are_n_floats(char **tab, int n)
{
	int	i = 0;

	while(tab[i] != NULL )
	{
		if(Check_if_float(tab[i]) == 1 || value_is_int(tab[i]) == 1)
			i++;
		else
			return -1;
	}
	if(i == n)
		return 0;
	return -1;
}

int	check_if_value_is_tab_of_n_floats(char *value, int n)
{
	char	**tab;

	tab = ft_split(value, ',');
	if(check_if_strings_are_n_floats(tab, n) == 0)
	{
		ft_free_tab(tab);
		return 1;
	}
	else
	{
		ft_free_tab(tab);
		return -1;
	}
}
int	check_limitted_n_floats_or_int(char **tab, double min, double max, int n)
{
	int	i = 0;

	while(tab[i] != NULL )
	{
		double	new_float;
		if(convert_char_to_float(tab[i], &new_float) == -1)
		{
			if(ft_strlen(ft_itoa(ft_atoi(tab[i]))) == ft_strlen(tab[i]))
				new_float = (double)ft_atoi(tab[i]);
			else
				return -1;
		}
		if(new_float >= min && new_float <= max)
			i++;
		else
			return -1;
	}
	if(i == n)
		return 0;
	return -1;
}

int	check_n_limitted_floats_or_int(char *value, double min, double max, int n)
{
	char	**tab;
	int ret = -1;

	tab = ft_split(value, ',');
	if(check_limitted_n_floats_or_int(tab, min, max, n) == 0)
		ret =1;
	ft_free_tab(tab);
	return ret;
}

int check_values_if_c_key(t_config_map *element)
{
	if(ft_strchr(element->key, C_KEY) && ft_strlen(element->key) ==1)
	{
		if(get_num_of_non_null_value(element->value) != 3)
		{
			ft_putstr_fd("number of values for c key is not correct", 1);
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				check_n_limitted_floats_or_int(element->value[1], -1, 1, 3) != 1 ||
				check_if_value_is_an_integer_between_0_and_180(element->value[2]) != 1)
		{
			ft_putstr_fd("incorrect values for c", 1);
			return(-1);
		}
		return 1;
	}
	return 0;
}
