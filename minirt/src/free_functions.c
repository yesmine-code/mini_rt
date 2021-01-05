/*
 * free_functions.c
 *
 *  Created on: 10 déc. 2020
 *      Author: user42
 */

#include "vec.h"

void	ft_free_tab(void **tab, int freeTabParent)
{
	int	i;

	i = 0;
	while(tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	if(freeTabParent)
		free(tab);
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;
	t_list *tmp2;

	tmp = list;
	while(tmp != NULL)
	{
		free(tmp->content);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void ft_free_scene(t_scene *scene)
{
	if(scene != NULL)
	{
		if(scene->cameras != NULL)
			ft_free_list(scene->cameras);
		if(scene->cylindres != NULL)
			ft_free_list(scene->cylindres);
		if(scene->lumieres != NULL)
			ft_free_list(scene->lumieres);
		if(scene->planes != NULL)
			ft_free_list(scene->planes);
		if(scene->spheres != NULL)
			ft_free_list(scene->spheres);
		if(scene->squares != NULL)
			ft_free_list(scene->squares);
		if(scene->triangles != NULL)
			ft_free_list(scene->triangles);;
		free(scene);
	}
}

void	ft_free_map(t_list *list)
{
	t_list *tmp;
	t_list *tmp2;
	t_config_map *map;

	tmp = list;
	while(tmp != NULL)
	{
		map = tmp->content;
		if(map->key != NULL)
			free(map->key);
		if(map->value != NULL)
			ft_free_tab((void **)map->value, 0);
		free(map);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

size_t ft_exit_failure(t_vars vars)
{
	size_t size;

	size = write(1, "ERROR : ", 8);
	if(vars.error_msg != NULL)
	{
		size += write(1, vars.error_msg, ft_strlen(vars.error_msg));
		free(vars.error_msg);
	}
	ft_free_map(vars.lines);
	ft_free_scene(vars.scene);
	exit(EXIT_FAILURE);
	return(size);

}
