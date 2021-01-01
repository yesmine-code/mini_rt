/*
 * Check.c
 *
 *  Created on: 19 nov. 2020
 *      Author: user42
 */

#include "vec.h"

int	check_values(t_config_map *element)
{
	if(Check_values_if_Rkey(element) != -1 && check_values_if_A_key(element) != -1 &&
			check_values_if_c_key(element) != -1 && check_values_if_l_key(element) != -1 &&
			check_values_if_sp_key(element) != -1 && check_values_if_pl_key(element) != -1 &&
			check_values_if_sq_key(element) != -1 && check_values_if_cy_key(element) != -1 &&
			check_values_if_tr_key(element) != -1)
		return(1);
	else
		return(-1);
}

int check_values_if_A_key(t_config_map *element)
{
	if(ft_strchr(element->key, A_KEY))
	{
		if(get_num_of_non_null_value(element->value) != 2)
		{
			ft_putstr_fd("number of values for A key is not correct", 1);
			return -1;
		}
		if(check_if_limitted_float(element->value[0], 0.0, 1.0) != 1 || check_if_value_is_tab_of_colors(element->value[1]) != 1)
		{
			ft_putstr_fd("incorrect values for A", 1);
			return(-1);
		}
		else
			return 1;
	}
	return 0;
}

int	Check_values_if_Rkey(t_config_map *element)
{
	if(ft_strchr(element->key, R_KEY))
	{
		if(get_num_of_non_null_value(element->value) != 2)
		{
			ft_putstr_fd("number of values for R key is not correct", 1);
			return -1;
		}
		else
			{
				if(value_is_int(element->value[0]) == 1 && ft_atoi(element->value[0]) > 0 &&
						value_is_int(element->value[1]) == 1 && ft_atoi(element->value[1]) > 0)
					return 1;
				else
					{
						ft_putstr_fd("incorrect values for R", 1);
						return -1;
					}
			}
	}
	return(0);
}

int check_keys_and_values(t_vars *vars)
{
	t_list	*tmp;
	tmp = vars->lines;
	t_config_map *element;
	int		var_R = 0;
	int 	var_A = 0;
	char	*keys[9]={"R","A","c","l","pl","sp","sq","cy","tr"};
	int	i;
	while(tmp != NULL)
	{
		element = tmp->content;
		i = 0;
		while((unsigned)i < sizeof(keys) / sizeof(char*))
		{
			if(ft_strnstr(keys[i], element->key, ft_strlen(keys[i])) && ft_strlen(element->key) == ft_strlen(keys[i]))
				break;
			else
				i++;
		}
		if(i == sizeof(keys) / sizeof(char*))
		{
			vars->error_msg = ft_strjoin(element->key, " is not correct");
			return -1;
		}
		if (ft_strchr(element->key, R_KEY) && ft_strlen(element->key) == 1)
			var_R++;
		else if (ft_strchr(element->key, A_KEY) && ft_strlen(element->key) == 1)
			var_A++;
		if(var_R > 1 || var_A > 1)
		{
			vars->error_msg = ft_strjoin(element->key, " couldn't be reused");
			return -1;
		}
		if(check_values(element) == -1)
			return -1;
		
		tmp = tmp->next;
	}
	return 1;
}

int	get_num_of_non_null_value(char *value[])
{
	int	i;
	i = 0;
	while(value[i] != NULL)
		i++;
	return i;
}

