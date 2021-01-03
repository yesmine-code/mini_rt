/*
 * check3.c
 *
 *  Created on: 1 janv. 2021
 *      Author: user42
 */


#include "vec.h"

int	check_if_strings_are__floats_or_int(char **tab)
{
	int	i = 0;
	char *str;

	while(tab[i] != NULL)
	{
		double	new_float;
		str = NULL;
		if(convert_char_to_float(tab[i], &new_float) == -1)
		{
			str = ft_itoa(ft_atoi(tab[i]));
			if(str != NULL && ft_strlen(str) == ft_strlen(tab[i]))
				new_float = (double)ft_atoi(tab[i]);
			else
			{
				if(str != NULL)
					free(str);
				return -1;
			}
		}
		if(str != NULL)
			free(str);
		i++;
	}
	if(i == 3)
		return 0;
	else
		return -1;
}

int	check_if_value_is_tab_of__floats_or_int(char *value)
{
	char	**tab;

		tab = ft_split(value, ',');
		if(check_if_strings_are__floats_or_int(tab) == 0)
		{
			ft_free_tab((void**)tab, 1);
			return 1;
		}
		else
		{
			ft_free_tab((void **)tab, 1);
			return -1;
		}
}

int	check_if_value_is_an_integer_between_0_and_180(char *value)
{
	char *str;
	int ret;

	ret = -1;
	str = ft_itoa(ft_atoi(value));
	if(str != NULL && ft_strlen(str) == ft_strlen(value) &&
			ft_atoi(value) >= 0 && ft_atoi(value) <= 180)
		ret = 1;
	if(str != NULL)
		free(str);
	return ret;
}

int check_values_if_l_key(t_config_map *element, t_vars *vars)
{
	if(ft_strchr(element->key, L_KEY) && ft_strlen(element->key) ==1)
	{
		if(get_num_of_non_null_value(element->value) != 3)
		{
			vars->error_msg = ft_strdup("number of values for l key is not correct");
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				check_if_limitted_float(element->value[1], 0.0, 1.0) != 1 ||
				check_if_value_is_tab_of_colors(element->value[2]) != 1)
		{
			vars->error_msg = ft_strdup("incorrect values for l");
			return(-1);
		}
		return 1;
	}
	return 0;
}

int check_values_if_sp_key(t_config_map *element, t_vars *vars)
{
	if(ft_strnstr(element->key, "sp", 2))
	{
		if(get_num_of_non_null_value(element->value) != 3)
		{
			vars->error_msg = ft_strdup("number of values for sp key is not correct");
			return -1;
		}
		if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				(Check_if_float(element->value[1]) != 1 && value_is_int(element->value[1]) != 1) ||
				check_if_value_is_tab_of_colors(element->value[2]) != 1)
		{
			vars->error_msg = ft_strdup("incorrect values for sp");
			return(-1);
		}
		return 1;
	}
	return 0;
}
