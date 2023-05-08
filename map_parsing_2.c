/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 07:42:00 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/05 18:05:14 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cmap_path(t_data *map, size_t col, size_t line)
{
	if (!map->tab[line])
		return ;
	if (map->path == 'S' && map->item == 0)
		map->path = 'V';
	if (map->tab[line][col] == 'E')
		map->path = 'S';
	if (map->tab[line][col] == 'C')
		map->item--;
	if (map->tab[line][col] == '0' || map->tab[line][col] == 'C'
		|| map->tab[line][col] == 'E' || map->tab[line][col] == 'P')
	{
		map->tab[line][col] = '2';
		cmap_path(map, col + 1, line);
		cmap_path(map, col - 1, line);
		cmap_path(map, col, line + 1);
		cmap_path(map, col, line - 1);
	}
}
void	find_start(t_data *map)
{
	map->col = 0;
	map->line = 0;	
	while (map->tab[map->line])
	{
		map->col = 0;
		while (map->tab[map->line][map->col])
		{
			if (map->tab[map->line][map->col] == 'P')
			{
				map->tab[map->line][map->col] = '0';
				return ;
			}
			map->col++;
		}
		map->line++;
	}
}

int	map_parsing(char **tab)
{
	t_data	*map;
	if ((map = create_struct()) == NULL)
		return (0);
	map->tab = tab;
	cmap_inside(map);
	cmap_layout(map);
	cmap_left_right(map);
	cmap_up_down(map);
	item_count(map);
	find_start(map);
	printf("%lu\n", map->col);
	printf("%lu\n", map->line);
	printf("%lu\n", map->item);
	cmap_path(map, map->col, map->line);
	//printf("%i\n",map->path);
	//while (++tab)
		//printf("%s\n", *tab);
	if (map->path == 'V')
		write(1, "Carte valide.\n", 14);
	else
		write(1, "[ERREUR] : Carte non valide.\n", 29);
	free_table(tab);
	free(map);
	return (1);
}

