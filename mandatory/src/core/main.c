/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:23:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/16 11:06:31 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = NULL;
	if (ac != 2)
		nb_arg_error();
	parse_file(av[1]);
	initialize_vars(&vars, av[1]);
	// initialize_window(vars);
	// setup_textures(vars);
	// initialize_mini_map(vars);
	// build_mini_map(vars);
	ft_free_vars(vars, 6);
	return (0);
}
