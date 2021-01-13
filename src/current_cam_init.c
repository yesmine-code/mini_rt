/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_cam_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:08:55 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/13 21:47:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	init_current_cam(t_scene *scene)
{
	t_camera	*cam;
	double		viewport_height;
	double		viewport_width;
	t_vector	u;
	t_vector	w;

	cam = get_from_list_by_id(scene->cameras, scene->current_cam_id);
	if (cam->direction.x == 0 && cam->direction.z == 0
		&& cam->direction.y != 0)
		cam->up = (t_vector){-1, 0, 0};
	else
		cam->up = (t_vector){0, -1, 0};
	viewport_height = 2 * tan((cam->fov * PI / 180) / 2);
	viewport_width = (scene->resolution.width / scene->resolution.height)
		* viewport_height;
	w = ft_vec_norm(ft_vec_sub(cam->origine,
		ft_vec_add(cam->origine, ft_vec_norm(cam->direction))));
	u = ft_vec_norm(ft_vec_cross(cam->up, w));
	cam->horizontal = ft_vec_mult_d(viewport_width, u);
	cam->vertical = ft_vec_mult_v(ft_vec_mult_d(viewport_height,
		ft_vec_cross(w, u)), cam->up);
	cam->lower_left_corner = ft_vec_sub(cam->origine,
		ft_vec_mult_d(0.5, cam->horizontal));
	cam->lower_left_corner = ft_vec_sub(ft_vec_sub(cam->lower_left_corner,
		ft_vec_mult_d(0.5, cam->vertical)), w);
}
