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
		while(i < 9)
		{
			if(ft_strnstr(keys[i], element->key, ft_strlen(keys[i])) && ft_strlen(element->key) == ft_strlen(keys[i]))
				break;
			else
				i++;
		}
		if(i == 9)
		{
			perror("error");
			ft_putstr_fd("the key is not right", 1);
			return -1;
		}
		tmp = tmp->next;
	}
	return 1;
}
