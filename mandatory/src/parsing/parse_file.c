/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:08:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/15 08:42:11 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	parse_file_content(int fd)
{
	char	**file;
	char	**map;

	file = get_file(fd);
	close(fd);
	printf(" - Arg check  ✅\n");
	check_data(file);
	printf(" - Data check ✅\n");
	map = get_map(file);
	ft_free(file);
	if (!map)
		exit(1);
	check_map(map);
	printf(" - Map check  ✅\n");
	ft_free(map);
}

void	parse_file(char *file)
{
	int	fd;
	int	pos;

	if (!file)
		empty_arg();
	pos = ft_strcspn(file, ".");
	fd = -1;
	if (pos != 0 && ft_strlen(file) != pos)
	{
		if (file && file[pos] && file[pos + 1] && file[pos + 2] && file[pos + 3]
			&& file[pos + 1] == 'c' && file[pos + 2] == 'u'
			&& file[pos + 3] == 'b' && ft_strlen(file) == pos + 4)
		{
			fd = open(file, O_RDONLY);
			if (fd == -1)
				error_fd();
			else
				parse_file_content(fd);
		}
		else
			ft_putstr_fd("Error\nNeed .cub extension! ❌\n", 2);
	}
	else
		ft_putstr_fd("Error\nNeed .cub extension! ❌\n", 2);
}
