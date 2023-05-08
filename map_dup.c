/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:35:32 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/05 17:00:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_path(char *str)
{
	char	*path;
	int		fd;

	path = ft_strjoin("./maps/", str);
	if (!path)
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		exit_err(errno);
	return (fd);
}

char	**ft_mdup(char *str)
{
	char	**tab;
	int		fd;
	size_t	tab_size;

	fd = file_path(str);
	tab_size = nb_of_line(fd);
	fd = file_path(str);
	tab = map_to_buffer(fd, tab_size);
	if (!tab)
		exit(EXIT_FAILURE);
	return(tab);
}

char	**map_to_buffer(int fd, size_t line)
{
	char	*str;
	char	**tab;
	size_t	i;

	tab = ft_calloc(line + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < line)
	{
		str = get_next_line(fd);
		tab[i] = ft_strdup(str);
		free(str);
		if (!tab[i])
		{
			free_error(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	if (close(fd) == -1)
		exit_err(errno);
	return (tab);
}

size_t	nb_of_line(int fd)
{
	char	*str;
	size_t	i;

	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		i++;
		str = get_next_line(fd);
		if (str)
			free(str);
	}
	if (close(fd) == -1)
		exit_err(errno);
	return (i);
}