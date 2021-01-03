/*
 * get_structs.c
 *
 *  Created on: 9 déc. 2020
 *      Author: user42
 */


#include "vec.h"

/**
 * this function parses camera values
 * @return
 * 1 if element is a camera
 * 0 if element is not
 */
t_camera *get_camera_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_camera *cam = NULL;

	cam = malloc(sizeof(t_camera));
	if (cam == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(cam->origine.x));
	convert_char_to_float(tab[1], &(cam->origine.y));
	convert_char_to_float(tab[2], &(cam->origine.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[1], ',');
	convert_char_to_float(tab[0], &(cam->direction.x));
	convert_char_to_float(tab[1], &(cam->direction.y));
	convert_char_to_float(tab[2], &(cam->direction.z));
	ft_free_tab((void**)tab, 1);
	convert_char_to_float(element->value[2], &cam->fov);
	return (cam);
}

t_resolution get_resolution_values(t_config_map *element)
{
	t_resolution r;
	r.width = ft_atoi(element->value[0]);
	r.height = ft_atoi(element->value[1]);
	return(r);
}

t_lum_ambiante get_lumiere_ambiante(t_config_map *element)
{
	t_lum_ambiante lum;
	char	**tab;
	convert_char_to_float(element->value[0], &lum.ratio);
	tab = ft_split(element->value[1], ',');
	lum.couleur.r = ft_atoi(tab[0]);
	lum.couleur.g = ft_atoi(tab[1]);
	lum.couleur.b = ft_atoi(tab[2]);
	ft_free_tab((void **)tab, 1);
	return(lum);
}

t_lumiere	*get_lumiere_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_lumiere	*lum = NULL;

	lum = malloc(sizeof(t_lumiere));
	if (lum == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(lum->pos.x));
	convert_char_to_float(tab[1], &(lum->pos.y));
	convert_char_to_float(tab[2], &(lum->pos.z));
	ft_free_tab((void**)tab, 1);
	convert_char_to_float(element->value[1], &lum->ratio);
	tab = ft_split(element->value[2], ',');
	lum->color.r = ft_atoi(tab[0]);
	lum->color.g = ft_atoi(tab[1]);
	lum->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (lum);
}
