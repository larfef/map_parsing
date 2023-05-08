/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 07:55:41 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/05 17:20:05 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*create_struct(void)
{
	t_data	*map;
	
	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	map->path = 0;
	map->tab = NULL;
	map->col = 0;	
	map->item = 0;	
	map->line = 0;	
	return (map);
}
//a retirer a la fin