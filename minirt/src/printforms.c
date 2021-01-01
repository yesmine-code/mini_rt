/*
 * printforms.c
 *
 *  Created on: 2 déc. 2020
 *      Author: user42
 */


#include "vec.h"


void get_intensite_pixel(t_scene *scene, t_lumiere *lum, t_obj_info obj_info, t_color *intensite_pixel)
{
	t_obj_info obj_info_light;
	int has_inter_light ;
	double d_light;
	t_ray ray_light;
	t_color col;
	double dt;
	t_color light_sum;

	light_sum = (t_color){0,0,0};
	col = ft_col_mult_v(ft_col_div_d(255, get_intersection_color(&obj_info, scene)),
			ft_col_mult_d(scene->lum_amb.ratio, ft_col_div_d(255, scene->lum_amb.couleur)));

	if(lum)
	{
		d_light =  sqrt(ft_get_norm_carre(ft_vec_sub(obj_info.pos, lum->pos)));
		dt = ft_vec_dot(ft_vec_norm(ft_vec_sub(lum->pos, obj_info.pos)), ft_vec_norm(obj_info.norm));
		ray_light.origine = lum->pos;
		ray_light.direction = ft_vec_norm(ft_vec_sub(obj_info.pos, lum->pos));
		has_inter_light = ft_intersection(scene, &ray_light, &obj_info_light);
		if(!(has_inter_light && obj_info_light.t_min + EPSILON < d_light))
			light_sum = ft_col_mult_d(dt * lum->ratio, ft_col_div_d(255, lum->color));
		col = ft_col_add(col, light_sum);
		*intensite_pixel = ft_col_clamp(ft_col_add(*intensite_pixel, col));
	}
	else
		*intensite_pixel = col;

}

t_color get_color_obj_inter(t_ray *ray, t_scene *scene)
{
	int	inter;
	int	first_time_color;
	t_color intensite_pixel;
	t_list	*tmp;
	t_obj_info obj_info;

	intensite_pixel = (t_color){0, 0, 0};
	inter = ft_intersection(scene, ray, &obj_info);
	if (inter == 1)
	{
		first_time_color = 1;
		tmp = scene->lumieres;
		while(tmp || first_time_color)
		{
			t_lumiere *lum;
			lum = tmp ? tmp->content : NULL;
			get_intensite_pixel(scene, lum, obj_info, &intensite_pixel);
			tmp = tmp ? tmp->next : NULL;
			first_time_color = 0;
		}
	}
	intensite_pixel = ft_col_mult_d(256, intensite_pixel);
	return(intensite_pixel);
}


t_ray compute_ray_direction(int x, int y, t_camera *cam, t_scene *scene)
{
	t_ray ray;
	ray.origine = cam->origine;
	ray.direction = ft_vec_norm(ft_vec_sub(ft_vec_add(cam->lower_left_corner,
			ft_vec_add(ft_vec_mult_d((double)x / (double)scene->resolution.width, cam->horizontal),
			ft_vec_mult_d((double)y / (double)scene->resolution.height, cam->vertical))), cam->origine));

	return ray;
}

void init_current_cam(t_scene *scene)
{
	t_camera *cam;
	double viewport_height;
	double viewport_width;
	t_vector u;
	t_vector v;
	t_vector w;

	t_vector vUp = (t_vector) {0,-1,0};
	cam = get_from_list_by_id(scene->cameras, scene->current_cam_id);
	viewport_height = 2 * tan((cam->fov * PI / 180) / 2);
	viewport_width = (scene->resolution.width / scene->resolution.height) * viewport_height;
	w = ft_vec_norm(ft_vec_sub(cam->origine, ft_vec_add(cam->origine, ft_vec_norm(cam->direction))));
	u = ft_vec_norm(ft_vec_cross(vUp, w));
	v = ft_vec_cross(w, u);
	cam->horizontal = ft_vec_mult_d(viewport_width, u);
	cam->vertical = ft_vec_mult_v(ft_vec_mult_d(viewport_height, v), vUp);
	cam->lower_left_corner = ft_vec_sub(cam->origine, ft_vec_mult_d(0.5, cam->horizontal));
	cam->lower_left_corner = ft_vec_sub(ft_vec_sub(cam->lower_left_corner, ft_vec_mult_d(0.5, cam->vertical)), w);
}

void	*print_scene(void *args)
{
	t_vars *vars;
	int x;
	int y;
	vars = ((t_args*)args)->vars;
	t_ray ray;
	t_camera *current_cam;
	t_color color;
	t_data *img = vars->img;
	t_scene *scene = vars->scene;

	current_cam = get_from_list_by_id(vars->scene->cameras, vars->scene->current_cam_id);
	x = 0;
	while(x < scene->resolution.width)
	{
		y = ((t_args*)args)->thread_id;
		while(y < scene->resolution.height)
		{
			ray = compute_ray_direction(x, y, current_cam, scene);
			color =  get_color_obj_inter(&ray, scene);
			my_mlx_pixel_put(img,x, scene->resolution.height - y - 1, create_trgb(color, img->endian));
			y+= THREADS_NUM;
		}
		x++;
	}
	pthread_exit(NULL);
}
