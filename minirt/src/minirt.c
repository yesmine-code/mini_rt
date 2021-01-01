/*
 ============================================================================
 Name        : Minirt.c
 Author      : yesmine
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "mlx_int.h"
#include "vec.h"

void	read_config_file(char *config_file, t_vars *vars)
{
	t_list *lines = NULL;
	int fd;
	int ret;
	char *line;
	fd = open(config_file, O_RDONLY);
	if (fd == -1)
	{
		vars->error_msg = ft_strdup("corrupted file");
		ft_exit_failure(*vars);
	}
	ret = get_next_line(fd, &line);
	while(ret != -1)
	{
		if (ft_strlen(line) > 0 && line[0] != '#')
		{
			t_config_map *map = getMapFromLine(line);
			if(map == NULL)
			{
				vars->error_msg = ft_strdup("technical error");
				ft_exit_failure(*vars);
			}
			t_list	*el = ft_lstnew(map);
			ft_lstadd_back(&lines, el);
			free(line);
		}
		if(ret == 0)
			break;
		ret = get_next_line(fd, &line);
	}
	close(fd);
	if(lines == NULL)
	{
		vars->error_msg = ft_strdup("empty file");
		ft_exit_failure(*vars);
	}
	vars->lines = lines;
}

t_config_map *getMapFromLine(char *line)
{
	int i = 0;
	int j = 0;
	int start = 0;
	char *key = NULL;
	char *value = NULL;
	t_config_map *map = malloc(sizeof (t_config_map));

	if(map == NULL)
		return NULL;
	while ((unsigned)i < sizeof(map->value) / sizeof(char*))
		map->value[i++] = NULL;
	i = 0;
	while (line[i] && ft_isspace(line[++i]) == 0);
	if (i > 0) {
		key = ft_substr(line, 0, i);
		value = ft_strtrim(ft_substr(line, i, ft_strlen(line) - i), " \t\v\f");
	}
	if (key != NULL && value != NULL) {
		map->key = key;
		i = 0;
		while (value[i] != '\0' && (unsigned)j < sizeof(map->value) / sizeof(char*)) {
			start = i;
			while (ft_isspace(value[i]) == 0 && value[i] != '\0')
				i++;
			map->value[j] = ft_substr(value, start, i - start);
			while (ft_isspace(value[i]) == 1)
				i++;
			j++;
		}
	}
	return map;
}

void fill_lumieres(t_config_map *element, t_vars *vars)
{
	t_lumiere *lum;
	lum = get_lumiere_values(element, vars);
	if (lum != NULL)
	{
		t_list *new_lum = ft_lstnew(lum);
		ft_lstadd_back(&vars->scene->lumieres, new_lum);
	}
}

void fill_spheres(t_config_map *element, t_vars *vars)
{
	t_sphere *sp;
	sp = get_sphere_values(element, vars);
	if (sp != NULL)
	{
		t_list *new_sphere = ft_lstnew(sp);
		ft_lstadd_back(&vars->scene->spheres, new_sphere);
	}
}

void fill_cameras(t_config_map *element, t_vars *vars)
{
	t_camera *cam;

	cam = get_camera_values(element, vars);
	if (cam != NULL)
	{
		t_list *new_camera = ft_lstnew(cam);
		ft_lstadd_back(&vars->scene->cameras, new_camera);
	}
}

void fill_squares(t_config_map *element, t_vars *vars)
{
	t_square *sq;
	sq = get_square_values(element, vars);
	if (sq != NULL)
	{
		t_list *new_square = ft_lstnew(sq);
		ft_lstadd_back(&vars->scene->squares, new_square);
	}
}

void fill_cylindres(t_config_map *element, t_vars *vars)
{
	t_cylindre *cy;
	cy = get_cylindre_values(element, vars);
	if (cy != NULL)
	{
		t_list *new_cylindre = ft_lstnew(cy);
		ft_lstadd_back(&vars->scene->cylindres, new_cylindre);
	}
}

void fill_planes(t_config_map *element, t_vars *vars)
{
	t_plane *pl;
	pl = get_plane_values(element, vars);
	if (pl != NULL)
	{
		t_list *new_plane = ft_lstnew(pl);
		ft_lstadd_back(&vars->scene->planes, new_plane);
	}
}

void fill_triangles(t_config_map *element, t_vars *vars)
{
	t_triangle *tr;
	tr = get_triangle_values(element, vars);
	if (tr != NULL)
	{
		t_list *new_triangle = ft_lstnew(tr);
		ft_lstadd_back(&vars->scene->triangles, new_triangle);
	}
}

void init_scene(t_vars *vars)
{
	vars->scene = malloc(sizeof(t_scene));
	if(vars->scene == NULL)
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

void fill_scene(t_vars *vars)
{
	t_list *tmp_lines;
	tmp_lines = vars->lines;

	init_scene(vars);
	vars->scene->current_cam_id = 0;
	while (tmp_lines != NULL)
	{
		t_config_map *element = tmp_lines->content;
		if (ft_strchr(element->key, R_KEY))
			vars->scene->resolution = get_resolution_values(element);
		else if (ft_strchr(element->key, A_KEY))
			vars->scene->lum_amb = get_lumiere_ambiante(element);
		else if (ft_strchr(element->key, L_KEY) && ft_strlen(element->key) == 1)
			fill_lumieres(element, vars);
		else if (ft_strnstr(element->key, "sp", 2))
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



void	compute_window_resolution(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_get_screen_size(vars->mlx, &x, &y);
	if(vars->scene->resolution.width > x)
		vars->scene->resolution.width = x;
	if(vars->scene->resolution.height > y)
		vars->scene->resolution.height = y;
}

int thread_init(t_vars *vars)
{
	pthread_t p[THREADS_NUM];
	t_args 	args[THREADS_NUM];
	int i;

	i = 0;

	init_current_cam(vars->scene);
	while(i < THREADS_NUM)
	{
		args[i].thread_id = i;
		args[i].vars = vars;
		pthread_create(&p[i], NULL, &print_scene, &args[i]);
		i++;
	}
	while(i > 0)
		pthread_join(p[--i], NULL);
	if(vars->save == 1)
		save_image(vars);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	//free scene

	return 0;
}

int check_file_extention(char *filename)
{
	char *ptr;

	if(ft_strlen(filename) > 3)
	{
		ptr = ft_substr(filename, ft_strlen(filename) - 3, 3);
		if(ft_strncmp(ptr, ".rt", 3) == 0)
			return 1;
	}
	return 0;
}

int		main(int argc, char **argv)
{
   t_data   img;
   t_vars vars;
	char *str;

	str = NULL;
	if(argc == 2)
		ft_memcpy(str, argv[1], ft_strlen(argv[1]));
	else
		str = "/home/user42/Bureau/minirt/minirt_project/minirt/scenes/test/wolf.rt";
	vars.lines = NULL;
	vars.error_msg = NULL;
	vars.scene = NULL;
	if(!check_file_extention(str))
	{
		vars.error_msg = ft_strdup("wrong filename extension");
		ft_exit_failure(vars);
	}
	vars.save = 1;
	read_config_file(str, &vars);
	if(check_keys_and_values(&vars) != 1)
		ft_exit_failure(vars);
	fill_scene(&vars);
	ft_free_list(vars.lines);
	vars.lines = NULL;
	vars.mlx = mlx_init();
	compute_window_resolution(&vars);
	img.img = mlx_new_image(vars.mlx, vars.scene->resolution.width, vars.scene->resolution.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img = &img;
	if(vars.save != 1)
	{
		vars.win = mlx_new_window(vars.mlx, vars.scene->resolution.width, vars.scene->resolution.height, "yesmine.rt");
		mlx_hook(vars.win, 2, 1L<<0, press_key, &vars);
		mlx_loop_hook(vars.mlx, &thread_init, &vars);
		mlx_loop(vars.mlx);
	}
	else
		thread_init(&vars);
	ft_free_scene(vars.scene);
	exit(EXIT_SUCCESS);
	printf("%s", str);
	return 0;
}

