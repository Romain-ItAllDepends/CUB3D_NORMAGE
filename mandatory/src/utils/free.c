/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:06:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/19 08:43:37 by rgobet           ###   ########.fr       */
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

static void	free_images(t_vars *vars)
{
	if (vars && vars->images && vars->images->screen)
		free(vars->images->screen);
	if (vars && vars->images && vars->images->crosshair)
		free(vars->images->crosshair);
	if (vars && vars->images && vars->images->north)
		free(vars->images->north);
	if (vars && vars->images && vars->images->south)
		free(vars->images->south);
	if (vars && vars->images && vars->images->east)
		free(vars->images->east);
	if (vars && vars->images && vars->images->west)
		free(vars->images->west);
}

static void	free_textures(t_vars *vars)
{
	if (vars && vars->textures && vars->textures->crosshair)
		free(vars->textures->crosshair);
	if (vars && vars->textures && vars->textures->north)
		free(vars->textures->north);
	if (vars && vars->textures && vars->textures->south)
		free(vars->textures->south);
	if (vars && vars->textures && vars->textures->east)
		free(vars->textures->east);
	if (vars && vars->textures && vars->textures->west)
		free(vars->textures->west);
}

void	ft_free_vars(t_vars *vars, int error)
{
	(void)error;
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
	free_images(vars);
	free_textures(vars);
	if (vars && vars->images)
		free(vars->images);
	if (vars && vars->textures)
		free(vars->textures);
	if (vars && vars->raycast)
		free(vars->raycast);
	free(vars);
	vars = NULL;
}
