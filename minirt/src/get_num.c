/*
 * get_num.c
 *
 *  Created on: 23 nov. 2020
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

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while(tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int Check_if_float(char *value)
{
	int	length;
	int	i;
	int	var;

	i = 0;
	if(ft_isdigit(value[i]) == 1 || value[i] == '-' || value[i] == '+')
			i++;
	else
		return(-1);
	if((value[i - 1] == '-' || value[i - 1] == '+') && ft_isdigit(value[i]) != 1)
		return -1;
	var = 0;
	length = ft_strlen(value);
	while(i < length)
	{
		if(ft_isdigit(value[i]) || value[i] == '.')
		{
			if(value[i] == '.')
				var++;
			i++;
		}
		else
			break;
	}
	if(i == length && var == 1 && value[length - 1] != '.')
		return 1;
	else
		return -1;
}

double convert_char_to_flottant(char *value)
{
	if(Check_if_float(value) == 1)
	{
		double retour;
		char	**tab;
		char	*new_value;
		int	length;

		tab = ft_split(value, '.');
		length = ft_strlen(tab[1]);
		new_value = ft_strjoin(tab[0], tab[1]);
		retour = ft_atoi(new_value) * pow(10, length * -1);
		ft_free(tab);
		free(new_value);
		return(retour);
	}
	else
		return -1;
}

int	compare_number_of_digits_and_chars(char **tab)
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

int	check_if_values_are_colors(char *value)
{
	char	**tab;

	tab = ft_split(value, ',');
	if(compare_number_of_digits_and_chars(tab) == 0)
	{
		ft_free(tab);
		return 1;
	}
	else
	{
		ft_free(tab);
		return -1;
	}
}
