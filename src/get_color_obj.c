/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:10:48 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:10:50 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	intensite_pixel_calcul(t_scene *scene, t_lumiere *lum,
		t_obj_info obj_info, t_color *light_sum)
{
	t_obj_info	obj_info_light;
	int			has_inter_light;
	double		d_light;
	t_ray		ray_light;
	double		dt;

	d_light = sqrt(ft_get_norm_carre(ft_vec_sub(obj_info.pos, lum->pos)));
	dt = ft_vec_dot(ft_vec_norm(ft_vec_sub(lum->pos, obj_info.pos)),
		ft_vec_norm(obj_info.norm));
	ray_light.origine = lum->pos;
	ray_light.direction = ft_vec_norm(ft_vec_sub(obj_info.pos, lum->pos));
	has_inter_light = ft_intersection(scene, &ray_light, &obj_info_light);
	if (!(has_inter_light && obj_info_light.t_min + EPSILON < d_light))
		*light_sum = ft_col_mult_d(dt * lum->ratio,
		ft_col_div_d(255, lum->color));
}

void	get_intensite_pixel(t_scene *scene, t_lumiere *lum,
		t_obj_info obj_info, t_color *intensite_pixel)
{
	t_color col;
	t_color light_sum;

	light_sum = (t_color){0, 0, 0};
	col = ft_col_mult_v(ft_col_div_d(255,
		get_intersection_color(&obj_info, scene)),
		ft_col_mult_d(scene->lum_amb.ratio,
		ft_col_div_d(255, scene->lum_amb.couleur)));
	if (lum)
	{
		intensite_pixel_calcul(scene, lum, obj_info, &light_sum);
		col = ft_col_add(col, light_sum);
		*intensite_pixel = ft_col_clamp(ft_col_add(*intensite_pixel, col));
	}
	else
		*intensite_pixel = col;
}

t_color	get_color_obj_inter(t_ray *ray, t_scene *scene)
{
	int			first_time_color;
	t_color		intensite_pixel;
	t_list		*tmp;
	t_obj_info	obj_info;
	t_lumiere	*lum;

	obj_info.object_id = 0;
	intensite_pixel = (t_color){0, 0, 0};
	if (ft_intersection(scene, ray, &obj_info) == 1)
	{
		first_time_color = 1;
		tmp = scene->lumieres;
		while (tmp || first_time_color)
		{
			lum = tmp ? tmp->content : NULL;
			get_intensite_pixel(scene, lum, obj_info, &intensite_pixel);
			tmp = tmp ? tmp->next : NULL;
			first_time_color = 0;
		}
	}
	intensite_pixel = ft_col_mult_d(256, intensite_pixel);
	return (intensite_pixel);
}
