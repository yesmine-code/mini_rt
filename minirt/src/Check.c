/*
 * Check.c
 *
 *  Created on: 19 nov. 2020
 *      Author: user42
 */

#include "minirt.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

int	Check_values_if_Rkey(t_config_map *element)
{
	int	i = 0;
	char *first_num;
	char *second_num;

	if(strchr(element->key, 'R'))
	{
		first_num = ft_itoa(ft_atoi(element->value[0]));
		second_num = ft_itoa(ft_atoi(element->value[1]));
		if(get_num_of_non_null_value(element->value) != 2)
		{
			ft_putstr_fd("number of values for R key is not correct", 1);
			return -1;
		}
		else if(ft_strncmp(first_num, element->value[0], ft_strlen(element->value[0])) == 0 &&
				ft_strncmp(second_num, element->value[1], ft_strlen(element->value[1])) == 0 )
			return 1;
		else
		{
			ft_putstr_fd("number of values for R key is not correct", 1);
			return -1;
		}
	}
	return(0);
}

int Check_key(t_list *lines)
{
	t_list	*tmp;
	tmp = lines;
	t_config_map *element;
	char	*keys[9]={"R","A","c","l","pl","sp","sq","cy","tr"};
	int	i;
	while(tmp != NULL)
	{
		element = tmp->content;
		i = 0;
		while(i < sizeof(keys) / sizeof(char*))
		{
			if(ft_strnstr(keys[i], element->key, ft_strlen(keys[i])) && ft_strlen(element->key) == ft_strlen(keys[i]))
				break;
			else
				i++;
		}
		if(Check_values_if_Rkey(element) == -1)
			return -1;
		if(i == sizeof(keys) / sizeof(char*))
		{
		//	perror("error");
			ft_putstr_fd("the key ", 1);
			ft_putstr_fd(element->key, 1);
			ft_putstr_fd(" is not correct", 1);
			return -1;
		}
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

