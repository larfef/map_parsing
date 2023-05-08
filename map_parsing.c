/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:50:54 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/05 17:14:10 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cmap_inside(t_data *map)
{
	size_t	nb;

	nb = 0;	
	while (map->tab[map->line])
	{
		map->col = 0;
		while (map->tab[map->line][map->col] != '\n')
		{
			if (map->tab[map->line][map->col] != '1' && map->tab[map->line][map->col] != '0'
				&& map->tab[map->line][map->col] != 'C' && map->tab[map->line][map->col] != 'E' 
				&& map->tab[map->line][map->col] != 'P')
				free_n_exit(map);
			if (map->tab[map->line][map->col] == 'E')
				nb += 2;
			if (map->tab[map->line][map->col] == 'P')
				nb += 3;
			map->col++;
		}
		map->line++;
	}
	if (nb != 5)
		free_n_exit(map);
}

void	cmap_layout(t_data *map)
{
	map->line = 1;
	map->col = ft_strlen(map->tab[0]);
	while (map->tab[map->line])
	{
		if (ft_strlen(map->tab[map->line]) != map->col)
			free_n_exit(map);
		map->line++;
	}
}

void	cmap_left_right(t_data *map)
{
	size_t	last;
	size_t	tab_size;

	map->line = 0;
	last = ft_strlen(map->tab[0]);
	tab_size = ft_tabsize(map->tab);
	while (map->line < tab_size)
	{
		if (map->tab[map->line][0] != '1' 
			|| map->tab[map->line][last - 2] != '1')
			free_n_exit(map);
		map->line++;
	}
}

void	cmap_up_down(t_data *map)
{
	size_t	last;
	size_t	tab_size;

	map->line = 0;
	last = ft_strlen(map->tab[0]);
	tab_size = ft_tabsize(map->tab);
	while (map->line < last - 1)
	{
		if (map->tab[0][map->line] != '1'
			|| (map->tab[tab_size - 1][map->line] != '1'))
			free_n_exit(map);
		map->line++;
	}
}

void	item_count(t_data *map)
{
	map->line = 1;
	while (map->tab[map->line + 1])
	{
		map->col = 1;
		while (map->tab[map->col + 1])
		{
			if (map->tab[map->line][map->col] == 'C')
				map->item++;
			map->col++;
		}
		map->line++;
	}
}