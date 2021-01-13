/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:10:17 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:10:20 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	fill_cameras(t_config_map *element, t_vars *vars)
{
	t_camera	*cam;
	t_list		*new_camera;

	cam = get_camera_values(element, vars);
	if (cam != NULL)
	{
		new_camera = ft_lstnew(cam);
		ft_lstadd_back(&vars->scene->cameras, new_camera);
	}
}

void	fill_lumieres(t_config_map *element, t_vars *vars)
{
	t_lumiere	*lum;
	t_list		*new_lum;

	lum = get_lumiere_values(element, vars);
	if (lum != NULL)
	{
		new_lum = ft_lstnew(lum);
		ft_lstadd_back(&vars->scene->lumieres, new_lum);
	}
}

void	init_scene(t_vars *vars)
{
	vars->scene = malloc(sizeof(t_scene));
	if (vars->scene == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	vars->scene->cameras = NULL;
	vars->scene->lumieres = NULL;
	vars->scene->spheres = NULL;
	vars->scene->squares = NULL;
	vars->scene->triangles = NULL;
	vars->scene->planes = NULL;
	vars->scene->cylindres = NULL;
}

void	fill_resolution_and_lum(t_config_map *element, t_vars *vars)
{
	if (ft_strchr(element->key, 'R'))
		vars->scene->resolution = get_resolution_values(element);
	else if (ft_strchr(element->key, 'A'))
		vars->scene->lum_amb = get_lumiere_ambiante(element);
	else if (ft_strchr(element->key, 'l') && ft_strlen(element->key) == 1)
		fill_lumieres(element, vars);
}

void	fill_scene(t_vars *vars)
{
	t_list			*tmp_lines;
	t_config_map	*element;

	tmp_lines = vars->lines;
	init_scene(vars);
	vars->scene->current_cam_id = 0;
	while (tmp_lines != NULL)
	{
		element = tmp_lines->content;
		fill_resolution_and_lum(element, vars);
		if (ft_strnstr(element->key, "sp", 2))
			fill_spheres(element, vars);
		else if (ft_strchr(element->key, 'c') && ft_strlen(element->key) == 1)
			fill_cameras(element, vars);
		else if (ft_strnstr(element->key, "sq", 2))
			fill_squares(element, vars);
		else if (ft_strnstr(element->key, "cy", 2))
			fill_cylindres(element, vars);
		else if (ft_strnstr(element->key, "pl", 2))
			fill_planes(element, vars);
		else if (ft_strnstr(element->key, "tr", 2))
			fill_triangles(element, vars);
		tmp_lines = tmp_lines->next;
	}
}
