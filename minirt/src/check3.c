/*
 * check3.c
 *
 *  Created on: 24 nov. 2020
 *      Author: user42
 */
#include "minirt.h"

int	check_if_strings_are__floats_or_int(char **tab)
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
			ft_free_tab(tab);
			return 1;
		}
		else
		{
			ft_free_tab(tab);
			return -1;
		}
}

int	check_if_value_is_an_integer_between_0_and_180(char *value)
{
	if(ft_strlen(ft_itoa(ft_atoi(value))) == ft_strlen(value) &&
			ft_atoi(value) >= 0 && ft_atoi(value) <= 180)
		return 1;
	return -1;
}
