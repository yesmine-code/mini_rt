/*
 * mymlx.c
 *
 *  Created on: 1 déc. 2020
 *      Author: user42
 */

#include "minirt.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
