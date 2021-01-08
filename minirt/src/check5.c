#include "vec.h"

void	check_scene(t_vars *vars)
{
	if (vars->scene->cameras == NULL)
	{
		vars->error_msg = ft_strdup("missing camera");
		ft_exit_failure(*vars);
	}
}

void	check_resolution(int var_r, t_vars *vars)
{
	if (var_r == 0)
	{
		vars->error_msg = ft_strdup("missing resolution");
		ft_exit_failure(*vars);
	}
}
