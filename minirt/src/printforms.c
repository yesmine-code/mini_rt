/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:19:07 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:19:09 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_ray	compute_ray_direction(int x, int y, t_camera *cam, t_scene *scene)
{
	t_ray	ray;

	ray.origine = cam->origine;
	ray.direction = ft_vec_norm(ft_vec_sub(ft_vec_add(cam->lower_left_corner,
			ft_vec_add(ft_vec_mult_d((double)x /
			(double)scene->resolution.width, cam->horizontal),
			ft_vec_mult_d((double)y / (double)scene->resolution.height,
			cam->vertical))), cam->origine));
	return (ray);
}

void	printf_pixels(void *args, t_scene *scene,
		t_camera *current_cam, t_data *img)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	x = 0;
	while (x < scene->resolution.width)
	{
		y = ((t_args*)args)->thread_id;
		while (y < scene->resolution.height)
		{
			ray = compute_ray_direction(x, y, current_cam, scene);
			color = get_color_obj_inter(&ray, scene);
			my_mlx_pixel_put(img, x, scene->resolution.height - y - 1,
				create_trgb(color, img->endian));
			y += THREADS_NUM;
		}
		x++;
	}
}

void	*print_scene(void *args)
{
	t_vars		*vars;
	t_camera	*current_cam;
	t_data		*img;
	t_scene		*scene;

	vars = ((t_args*)args)->vars;
	scene = vars->scene;
	img = vars->img;
	current_cam = get_from_list_by_id(vars->scene->cameras,
		vars->scene->current_cam_id);
	printf_pixels(args, scene, current_cam, img);
	pthread_exit(NULL);
}
