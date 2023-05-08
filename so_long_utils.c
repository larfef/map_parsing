/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:33:33 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/08 17:48:41 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(int errnum)
{	
	perror(strerror(errnum));
	exit(EXIT_FAILURE);
}

void	free_error(char **buffer, size_t i)
{
	while (i--)
		free(buffer[i]);
	free(buffer);
}

void	free_n_exit(t_data *map)
{
	free_table(map->tab);
	write(1, "[ERREUR] : Carte non valide.\n", 29);
	free(map);
	exit(EXIT_FAILURE);
}

void	free_table(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		i++;
	while (--i > -1)
		free(buffer[i]);
	free(buffer);
}

size_t	ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
