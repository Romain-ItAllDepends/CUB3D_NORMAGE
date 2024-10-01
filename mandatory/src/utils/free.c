/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:06:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/02 00:20:47 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	free_textures(t_vars *vars)
{
	if (vars && vars->textures && vars->textures->crosshair)
		mlx_delete_texture(vars->textures->crosshair);
	if (vars && vars->textures && vars->textures->north)
		mlx_delete_texture(vars->textures->north);
	if (vars && vars->textures && vars->textures->south)
		mlx_delete_texture(vars->textures->south);
	if (vars && vars->textures && vars->textures->east)
		mlx_delete_texture(vars->textures->east);
	if (vars && vars->textures && vars->textures->west)
		mlx_delete_texture(vars->textures->west);
}

void	ft_free_vars(t_vars *vars)
{
	if (vars && vars->cursor)
		mlx_destroy_cursor(vars->cursor);
	if (vars && vars->window)
		mlx_close_window(vars->window);
	if (vars && vars->map)
		ft_free(vars->map);
	if (vars && vars->north)
		free(vars->north);
	if (vars && vars->south)
		free(vars->south);
	if (vars && vars->east)
		free(vars->east);
	if (vars && vars->west)
		free(vars->west);
	if (vars && vars->images)
		free(vars->images);
	free_textures(vars);
	if (vars && vars->textures)
		free(vars->textures);
	if (vars && vars->raycast)
		free(vars->raycast);
	if (vars && vars->window)
		mlx_terminate(vars->window);
	free(vars);
	exit(0);
}
