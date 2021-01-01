/*
 * rotation.c
 *
 *  Created on: 29 déc. 2020
 *      Author: user42
 */

#include "vec.h"

t_vector		rotation_x(t_vector vec, double x)
{
	t_vector	new_vec;

	x = x * PI / 180;
	new_vec.x = vec.x;
	new_vec.y = vec.y * cos(x) - vec.z * sin(x);
	new_vec.z = vec.y * sin(x) + vec.z * cos(x);
	return (new_vec);
}

t_vector		rotation_y(t_vector vec, double y)
{
	t_vector	new_vec;

	y = y * PI / 180;
	new_vec.x = vec.x * cos(y) + vec.z * sin(y);
	new_vec.y = vec.y;
	new_vec.z = vec.x * -sin(y) + vec.z * cos(y);
	return (new_vec);
}

t_vector		rotation_z(t_vector vec, double z)
{
	t_vector	new_vec;

	z = z * PI / 180;
	new_vec.x = vec.x * cos(z) - vec.y * sin(z);
	new_vec.y = vec.x * sin(z) + vec.y * cos(z);
	new_vec.z = vec.z;
	return (new_vec);
}

t_vector		rotation(t_vector vec, t_vector angle)
{
	t_vector new_vec;

	new_vec = rotation_x(vec, angle.x);
	new_vec = rotation_y(new_vec, angle.y);
	new_vec = rotation_z(new_vec, angle.z);
	return (new_vec);
}
