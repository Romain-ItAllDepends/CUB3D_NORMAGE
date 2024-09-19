/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:10:35 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/19 09:48:16 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void raycast(t_vars *vars, int x)
{
    int hit = 0;
    int mapX = (int)vars->raycast->posx;
    int mapY = (int)vars->raycast->posy;
    int side;
    int drawStart;
    int drawEnd;
    int texX;
    int texY;
    double perpWallDist;
    double wallX;
    double step;
    double texPos;
    int lineHeight;
    uint32_t color;


    // Calcul de la position de la caméra
    vars->raycast->camerax = 2 * x / (double)WIDTH - 1;
    vars->raycast->ray_dirx = vars->raycast->dirx + vars->raycast->planex * vars->raycast->camerax;
    vars->raycast->ray_diry = vars->raycast->diry + vars->raycast->planey * vars->raycast->camerax;

    // Calcul des distances initiales
    vars->raycast->delta_distx = (vars->raycast->ray_dirx == 0) ? 1e30 : fabs(1 / vars->raycast->ray_dirx);
    vars->raycast->delta_disty = (vars->raycast->ray_diry == 0) ? 1e30 : fabs(1 / vars->raycast->ray_diry);

    if (vars->raycast->ray_dirx < 0)
    {
        vars->raycast->stepx = -1;
        vars->raycast->side_distx = (vars->raycast->posx - mapX) * vars->raycast->delta_distx;
    }
    else
    {
        vars->raycast->stepx = 1;
        vars->raycast->side_distx = (mapX + 1.0 - vars->raycast->posx) * vars->raycast->delta_distx;
    }
    if (vars->raycast->ray_diry < 0)
    {
        vars->raycast->stepy = -1;
        vars->raycast->side_disty = (vars->raycast->posy - mapY) * vars->raycast->delta_disty;
    }
    else
    {
        vars->raycast->stepy = 1;
        vars->raycast->side_disty = (mapY + 1.0 - vars->raycast->posy) * vars->raycast->delta_disty;
    }



    // Exécution du DDA
    while (hit == 0)
    {
        if (vars->raycast->side_distx < vars->raycast->side_disty)
        {
            vars->raycast->side_distx += vars->raycast->delta_distx;
            mapX += vars->raycast->stepx;
            side = 0;
        }
        else
        {
            vars->raycast->side_disty += vars->raycast->delta_disty;
            mapY += vars->raycast->stepy;
            side = 1;
        }
        if (vars->map[mapX][mapY] == '1')
            hit = 1;
    }

    // Calcul de la distance projetée
    if (side == 0)
        perpWallDist = (vars->raycast->side_distx - vars->raycast->delta_distx);
    else
        perpWallDist = (vars->raycast->side_disty - vars->raycast->delta_disty);
    lineHeight = (int)(TEXHEIGHT / perpWallDist);



    // Calcul des limites de dessin en tenant compte de la position verticale du joueur
    drawStart = -lineHeight / 2 + HEIGHT / 2;
    if (drawStart < 0)
        drawStart = 0;
    drawEnd = lineHeight / 2 + HEIGHT / 2;
    if (drawEnd >= HEIGHT)
	{
		drawEnd = HEIGHT - 1;
	}
	for (int y = 0; y < drawStart; y++)
    {
        mlx_put_pixel(vars->images->screen, x, y, (vars->ceiling[0] << 16) | (vars->ceiling[1] << 8) | vars->ceiling[2]);
    }





    // Calcul des coordonnées de texture
    if (side == 0)
        wallX = vars->raycast->posy + perpWallDist * vars->raycast->ray_diry;
    else
        wallX = vars->raycast->posx + perpWallDist * vars->raycast->ray_dirx;
    wallX -= floor((wallX));
    texX = (int)(wallX * (double)TEXWIDTH);
    if (side == 0 && vars->raycast->ray_dirx > 0)
        texX = TEXWIDTH - texX - 1;
    if (side == 1 && vars->raycast->ray_diry < 0)
        texX = TEXWIDTH - texX - 1;
    step = 1.0 * TEXHEIGHT / lineHeight;
    texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;

	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

    for (int y = drawStart; y < drawEnd; y++)
    {
        texY = (int)texPos & (TEXHEIGHT - 1);
        texPos += step;
		color = 4294967295;
        if (side == 0 && vars->raycast->ray_dirx < 0)
		{
			r = ((((int32_t *)vars->images->west->pixels)[TEXWIDTH * texY + texX] >> 24) & 0xFF);
			g = ((((int32_t *)vars->images->west->pixels)[TEXWIDTH * texY + texX] >> 16) & 0xFF);
			b = ((((int32_t *)vars->images->west->pixels)[TEXWIDTH * texY + texX] >> 8) & 0xFF);
			a = (((int32_t *)vars->images->west->pixels)[TEXWIDTH * texY + texX] & 0xFF);
			color = ((a << 24) | (b << 16) | (g << 8) | r);
		}
        else if (side == 0 && vars->raycast->ray_dirx >= 0)
		{
			r = ((((int32_t *)vars->images->east->pixels)[TEXWIDTH * texY + texX] >> 24) & 0xFF);
			g = ((((int32_t *)vars->images->east->pixels)[TEXWIDTH * texY + texX] >> 16) & 0xFF);
			b = ((((int32_t *)vars->images->east->pixels)[TEXWIDTH * texY + texX] >> 8) & 0xFF);
			a = (((int32_t *)vars->images->east->pixels)[TEXWIDTH * texY + texX] & 0xFF);
            color = ((a << 24) | (b << 16) | (g << 8) | r);
		}
        else if (side == 1 && vars->raycast->ray_diry < 0)
		{
			r = ((((int32_t *)vars->images->north->pixels)[TEXWIDTH * texY + texX] >> 24) & 0xFF);
			g = ((((int32_t *)vars->images->north->pixels)[TEXWIDTH * texY + texX] >> 16) & 0xFF);
			b = ((((int32_t *)vars->images->north->pixels)[TEXWIDTH * texY + texX] >> 8) & 0xFF);
			a = (((int32_t *)vars->images->north->pixels)[TEXWIDTH * texY + texX] & 0xFF);
            color = ((a << 24) | (b << 16) | (g << 8) | r);

		}
		else
		{
			r = ((((uint32_t *)vars->images->south->pixels)[TEXWIDTH * texY + texX] >> 24) & 0xFF);
			g = ((((uint32_t *)vars->images->south->pixels)[TEXWIDTH * texY + texX] >> 16) & 0xFF);
			b = ((((uint32_t *)vars->images->south->pixels)[TEXWIDTH * texY + texX] >> 8) & 0xFF);
			a = (((uint32_t *)vars->images->south->pixels)[TEXWIDTH * texY + texX] & 0xFF);
            color = ((a << 24) | (b << 16) | (g << 8) | r);

		}
    	mlx_put_pixel(vars->images->screen, x, y, color);
    }
}

void paint_on_screen(t_vars *vars)
{
	mlx_delete_image(vars->window, vars->images->screen);
	vars->images->screen = mlx_new_image(vars->window, WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH; x++)
	{
		raycast(vars, x);
	}
	mlx_image_to_window(vars->window, vars->images->screen, 0, 0);
}
