/*
 * get_values.c
 *
 *  Created on: 28 nov. 2020
 *      Author: user42
 */


#include "vec.h"

int		create_trgb(t_color c, int endian)
{
	int t;

	t = 0;
	if(endian == 0)
		return(t << 24 | (int)c.r << 16 | (int)c.g << 8 | (int)c.b);
	return((int)c.b << 24 | (int)c.g << 16 | (int)c.r << 8 | t);
}
