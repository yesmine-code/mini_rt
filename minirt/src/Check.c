/*
 * Check.c
 *
 *  Created on: 19 nov. 2020
 *      Author: user42
 */

#include "minirt.h"

int Check_key(t_config_map map)
{
	if(ft_strlen(map.key) > 2 || ft_strlen(map.key) == 0 || ft_isalpha(map.key[0]) == 0 || ft_isalpha(map.key[1]) == 0)
	{
		perror("error");
		return -1;
	}
	return 1;
}
