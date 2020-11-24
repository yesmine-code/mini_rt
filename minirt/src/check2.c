/*
 * check2.c
 *
 *  Created on: 24 nov. 2020
 *      Author: user42
 */

#include "minirt.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <math.h>
#include <float.h>

void	ft_free_tab(char **tab);
int convert_char_to_float(char *value, double *new_float);
int Check_if_float(char *value);
int	check_if_value_is_an_integer_between_0_and_180(char *value);
int	check_if_strings_are_limitted__floats_or_int(char **tab, double min, double max);
int	get_num_of_non_null_value(char *value[]);

int	check_if_strings_are_floats(char **tab)
{
	int	i = 0;

	while(tab[i] != NULL )
	{
		if(Check_if_float(tab[i]) == 1)
			i++;
		else
			return -1;
	}
	if(i == 3)
		return 0;
	else
		return -1;
}

int	check_if_value_is_tab_of__floats(char *value)
{
	char	**tab;

	tab = ft_split(value, ',');
	if(check_if_strings_are_floats(tab) == 0)
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
int	check_if_strings_are_limitted__floats_or_int(char **tab, double min, double max)
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
	if(i == 3)
		return 0;
	else
		return -1;
}

int	check_if_value_is_tab_of_limitted__floats_or_int(char *value, double min, double max)
{
	char	**tab;

		tab = ft_split(value, ',');
		if(check_if_strings_are_limitted__floats_or_int(tab, min, max) == 0)
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

int check_values_if_c_key(t_config_map *element)
{
	if(ft_strchr(element->key, 'c') && ft_strlen(element->key) ==1)
	{
		if(get_num_of_non_null_value(element->value) != 3)
		{
			ft_putstr_fd("number of values for c key is not correct", 1);
			return -1;
		}
		else if(check_if_value_is_tab_of__floats_or_int(element->value[0]) != 1||
				check_if_value_is_tab_of_limitted__floats_or_int(element->value[1], -1, 1) != 1 ||
				check_if_value_is_an_integer_between_0_and_180(element->value[2]) != 1)
		{
			ft_putstr_fd("incorrect values for c", 1);
			return(-1);
		}
		else
			return 1;
	}
	return 0;
}
