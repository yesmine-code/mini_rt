/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:17:17 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:17:25 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		ft_obj_info(int i, double t, t_obj_info *obj_info, t_ray *r)
{
	obj_info->object_id = i;
	obj_info->t_min = t;
	obj_info->pos = ft_vec_add(r->origine,
	ft_vec_mult_d(t, r->direction));
	return (1);
}

int		ft_intersection(t_scene *scene, t_ray *r, t_obj_info *obj_info)
{
	obj_info->t_min = MAX_VALUE;
	if (ft_inter_all_spheres(scene, r, obj_info) |
		ft_inter_all_planes(scene, r, obj_info) |
		ft_inter_all_squares(scene, r, obj_info) |
		ft_inter_all_triangles(scene, r, obj_info) |
		ft_inter_all_cylinders(scene, r, obj_info))
		return (1);
	return (0);
}

t_color	get_intersection_color(const t_obj_info *obj_info, t_scene *scene)
{
	t_color	inter_color;

	inter_color = (t_color){0, 0, 0};
	if (obj_info->type == SPHERE)
		inter_color = ((t_sphere *)get_from_list_by_id(scene->spheres,
		obj_info->object_id))->color;
	else if (obj_info->type == PLANE)
		inter_color = ((t_plane *)get_from_list_by_id(scene->planes,
		obj_info->object_id))->color;
	else if (obj_info->type == TRIANGLE)
		inter_color = ((t_triangle *)get_from_list_by_id(scene->triangles,
		obj_info->object_id))->color;
	else if (obj_info->type == SQUARE)
		inter_color = ((t_square *)get_from_list_by_id(scene->squares,
		obj_info->object_id))->color;
	else if (obj_info->type == CYLINDRE)
		inter_color = ((t_cylindre *)get_from_list_by_id(scene->cylindres,
		obj_info->object_id))->color;
	return (inter_color);
}
