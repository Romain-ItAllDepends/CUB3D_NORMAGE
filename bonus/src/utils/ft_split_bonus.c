/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:40:34 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:30:20 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static int	ft_charcount(char const *str, char c)
{
	int	i;
	int	j;

	if (!str[0])
		return (0);
	i = 0;
	j = 1;
	if (str[i] == c || str[ft_strlen(str) - 1] == c)
	{
		j = 0;
		if (str[ft_strlen(str) - 1] != c)
			j = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			j++;
		i++;
	}
	if (j == i)
		return (0);
	return (j);
}

static int	ft_gap(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_substr1(char const *s, char c)
{
	unsigned int	i;
	char			*tab;
	int				len;

	len = ft_gap(s, c);
	i = 0;
	tab = ft_calloc((1 + len), sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}

static int	is_map_splitted(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (j == 6)
			break ;
		j += is_parameter(&s[i]);
		i++;
	}
	while (s && s[i] && s[i] != '\n')
		i++;
	if (j != 6)
	{
		ft_putstr_fd("Error\nToo much or less parameters in the file!\n", 2);
		return (1);
	}
	if (verif_map_split(&s[i]) == 1)
		return (1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**tab;

	i = 0;
	x = 0;
	tab = NULL;
	if (!s || (c == '\n' && is_map_splitted((char *)s) == 1))
	{
		return (tab);
	}
	tab = ft_calloc((ft_charcount(s, c) + 2), sizeof(char *));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			tab[x++] = ft_substr1(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[x] = NULL;
	return (tab);
}
