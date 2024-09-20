/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:46:22 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/20 12:51:26 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int32_t	get_color(int32_t pixel)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;
	int32_t	color;

	r = ((pixel >> 24) & 0xFF);
	g = ((pixel >> 16) & 0xFF);
	b = ((pixel >> 8) & 0xFF);
	a = (pixel & 0xFF);
	color = ((a << 24) | (b << 16) | (g << 8) | r);
	return (color);
}

void	select_textures(t_vars *vars)
{
	if (vars->raycast->side == 0 && vars->raycast->ray_dirx < 0)
	{
		vars->raycast->color = get_color(((int32_t *)vars->images->west->pixels)
			[TEXWIDTH * vars->raycast->texY + vars->raycast->texX]);
	}
	else if (vars->raycast->side == 0 && vars->raycast->ray_dirx >= 0)
	{
		vars->raycast->color = get_color(((int32_t *)vars->images->east->pixels)
			[TEXWIDTH * vars->raycast->texY + vars->raycast->texX]);
	}
	else if (vars->raycast->side == 1 && vars->raycast->ray_diry < 0)
	{
		vars->raycast->color = get_color(
				((int32_t *)vars->images->north->pixels)
			[TEXWIDTH * vars->raycast->texY + vars->raycast->texX]);
	}
	else
	{
		vars->raycast->color = get_color(
				((int32_t *)vars->images->south->pixels)
			[TEXWIDTH * vars->raycast->texY + vars->raycast->texX]);
	}
}

void	put_pixels(t_vars *vars, int x)
{
	int	i;

	i = 0;
	while (i < vars->raycast->drawStart)
	{
		mlx_put_pixel(vars->images->screen, x, i, (vars->ceiling[0] << 16) | \
		(vars->ceiling[1] << 8) | vars->ceiling[2]);
		i++;
	}
	while (i < vars->raycast->drawEnd)
	{
		vars->raycast->texY = (int)vars->raycast->texPos & (TEXHEIGHT - 1);
		vars->raycast->texPos += vars->raycast->step;
		vars->raycast->color = 0;
		select_textures(vars);
		mlx_put_pixel(vars->images->screen, x, i, vars->raycast->color);
		i++;
	}
	while (i < HEIGHT)
	{
		mlx_put_pixel(vars->images->screen, x, i, (vars->floor[0] << 16) | \
		(vars->floor[1] << 8) | vars->floor[2]);
		i++;
	}
}

void	texture_coord(t_vars *vars)
{
	if (vars->raycast->side == 0)
	{
		vars->raycast->wallX = vars->raycast->posy + \
		vars->raycast->perpWallDist * vars->raycast->ray_diry;
	}
	else
	{
		vars->raycast->wallX = vars->raycast->posx + \
		vars->raycast->perpWallDist * vars->raycast->ray_dirx;
	}
	vars->raycast->wallX -= floor((vars->raycast->wallX));
	vars->raycast->texX = (int)(vars->raycast->wallX * (double)TEXWIDTH);
	if (vars->raycast->side == 0 && vars->raycast->ray_dirx > 0)
		vars->raycast->texX = TEXWIDTH - vars->raycast->texX - 1;
	if (vars->raycast->side == 1 && vars->raycast->ray_diry < 0)
		vars->raycast->texX = TEXWIDTH - vars->raycast->texX - 1;
	vars->raycast->step = 1.0 * TEXHEIGHT / vars->raycast->lineHeight;
	vars->raycast->texPos = (vars->raycast->drawStart - HEIGHT / 2 + \
	vars->raycast->lineHeight / 2) * vars->raycast->step;
}

void	wall_start_end(t_vars *vars)
{
	vars->raycast->drawStart = -vars->raycast->lineHeight / 2 + HEIGHT / 2;
	if (vars->raycast->drawStart < 0)
		vars->raycast->drawStart = 0;
	vars->raycast->drawEnd = vars->raycast->lineHeight / 2 + HEIGHT / 2;
	if (vars->raycast->drawEnd >= HEIGHT)
		vars->raycast->drawEnd = HEIGHT - 1;
}
