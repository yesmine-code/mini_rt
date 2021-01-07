/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:17:56 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:17:59 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	compute_window_resolution(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_get_screen_size(vars->mlx, &x, &y);
	if (vars->scene->resolution.width > x)
		vars->scene->resolution.width = x;
	if (vars->scene->resolution.height > y)
		vars->scene->resolution.height = y;
}

void	vars_init(t_vars *vars)
{
	vars->lines = NULL;
	vars->error_msg = NULL;
	vars->scene = NULL;
	vars->save = 0;
	vars->mlx = mlx_init();
}

void	get_data(t_vars *vars, t_data *img)
{
	compute_window_resolution(vars);
	img->img = mlx_new_image(vars->mlx,
			vars->scene->resolution.width, vars->scene->resolution.height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	vars->img = img;
}

void	get_window(t_vars *vars)
{
	if (vars->save != 1)
	{
		vars->win = mlx_new_window(vars->mlx, vars->scene->resolution.width,
				vars->scene->resolution.height, "yesmine.rt");
		mlx_hook(vars->win, 2, 1L << 0, &press_key, vars);
		mlx_hook(vars->win, 33, 1L << 17, &ft_exit, vars);
		mlx_loop_hook(vars->mlx, &thread_init, vars);
		mlx_loop(vars->mlx);
	}
	else
		thread_init(vars);
}

int		main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	char	*str;

	str = NULL;
	vars_init(&vars);
	if (argc == 2)
		str = ft_strjoin("/home/user42/Bureau/minirt2/minirt/", argv[1]);
	else
		str = ft_strdup("/home/user42/Bureau/minirt2/minirt/scenes/sphere.rt");
	if (!check_file_extention(str))
	{
		vars.error_msg = ft_strdup("wrong filename extension");
		ft_exit_failure(vars);
	}
	read_config_file(str, &vars);
	free(str);
	if (check_keys_and_values(&vars) != 1)
		ft_exit_failure(vars);
	fill_scene(&vars);
	get_data(&vars, &img);
	get_window(&vars);
	return (ft_exit(&vars));
}
