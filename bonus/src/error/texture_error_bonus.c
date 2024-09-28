/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:28:28 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:27:50 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	resize_error(t_vars *vars)
{
	ft_putstr_fd("Error\nAn error occured while resizing image!\n", 2);
	if (!vars->images->north)
		mlx_delete_image(vars->window, vars->images->north);
	if (!vars->images->south)
		mlx_delete_image(vars->window, vars->images->south);
	if (!vars->images->west)
		mlx_delete_image(vars->window, vars->images->west);
	if (!vars->images->east)
		mlx_delete_image(vars->window, vars->images->east);
	vars->images->north = NULL;
	vars->images->south = NULL;
	vars->images->west = NULL;
	vars->images->east = NULL;
	ft_free_vars(vars);
	exit(1);
}

void	screen_error(t_vars *vars)
{
	ft_putstr_fd("Error\nAn error occurred while creating the image!\n", 2);
	ft_free_vars(vars);
	exit(1);
}
