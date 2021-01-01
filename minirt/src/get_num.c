/*
 * get_num.c
 *
 *  Created on: 23 nov. 2020
 *      Author: user42
 */


#include "minirt.h"

int value_is_int(char *value)
{
	if(ft_strlen(ft_itoa(ft_atoi(value))) == ft_strlen(value))
		return 1;
	return -1;
}

/**
 * this function
 * @returns
 * 1 if value can be converted to float.
 * -1 if it can't.
 */

int Check_if_float(char *value)
{
	int	length;
	int	i;
	int	dots_num;

	i = 0;
	if(ft_isdigit(value[i]) == 1 || value[i] == '-' || value[i] == '+')
			i++;
	else
		return(-1);
	if((value[i - 1] == '-' || value[i - 1] == '+') && ft_isdigit(value[i]) != 1)
		return -1;
	dots_num = 0;
	length = ft_strlen(value);
	while(i < length)
	{
		if(ft_isdigit(value[i]) || value[i] == '.')
		{
			if(value[i] == '.')
				dots_num++;
			i++;
		}
		else
			break;
	}
	if(i == length && dots_num == 1 && value[length - 1] != '.')
		return 1;
	return -1;
}

int	check_if_limitted_float(char *value, double min, double max)
{
	if(Check_if_float(value) == 1 || value_is_int(value) == 1)
	{
		double	float_value;
		float_value = 0;
		convert_char_to_float(value, &float_value);
		if(float_value >= min && float_value <= max)
			return 1;
	}
	return -1;
}
/**
 * this function
 * @returns
 * 1 if value can be converted to float.
 * -1 if not.
 */

int convert_char_to_float(char *value, double *new_float)
{
	if(Check_if_float(value) == 1)
	{
		char	**tab;
		char	*new_value;
		int		length;

		tab = ft_split(value, '.');
		length = ft_strlen(tab[1]);
		new_value = ft_strjoin(tab[0], tab[1]);
		*new_float = ft_atoi(new_value) * pow(10, length * -1);
		ft_free_tab((void **)tab);
		free(new_value);
		return 1;
	}
	if(value_is_int(value) == 1)
	{
		*new_float = ft_atoi(value);
		return 1;
	}
	return -1;
}
/**
 * this function
 * @returns
 * 0 if values of the tab can be all converted to integers between[0-255] .
 * -1 if not.
 */
int	check_if_strings_can_be_integer(char **tab)
{
	int	i = 0;

	while(tab[i] != NULL )
	{
		if(ft_strlen(ft_itoa(ft_atoi(tab[i]))) == ft_strlen(tab[i]) && ft_atoi(tab[i]) >= 0 && ft_atoi(tab[i]) <= 255 )
			i++;
		else
			return -1;
	}
	if(i == 3)
		return 0;
	else
		return -1;
}

/**
 * this function
 * @returns
 * 1 if the string splitted returns tab of strings between 0 and 255.
 * -1 if it not.
 */
int	check_if_value_is_tab_of_colors(char *value)
{
	char	**tab;

	tab = ft_split(value, ',');
	if(check_if_strings_can_be_integer(tab) == 0)
	{
		ft_free_tab((void **)tab);
		return 1;
	}
	else
	{
		ft_free_tab((void **)tab);
		return -1;
	}
}
