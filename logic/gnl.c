/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:54:19 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/17 13:09:44 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// static char	*make_line(int fd, char *buffer, char *storage)
// {
// 	int		read_bytes;
// 	char	*temp;

// 	read_bytes = 1;
// 	while (read_bytes)
// 	{
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 		buffer[read_bytes] = '\0';
// 		if (read_bytes == -1)
// 			return (NULL);
// 		else if (read_bytes == 0)
// 			break ;
// 		if (!storage)
// 			storage = ft_strdup("");
// 		temp = storage;
// 		storage = ft_strjoin(temp, buffer);
// 		free(temp);
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	return (storage);
// }

// static char	*extract(char *line)
// {
// 	size_t	count;
// 	char	*backup;

// 	count = 0;
// 	while (line[count] != '\n' && line[count] != '\0')
// 		count++;
// 	if (line[count] == '\0' || line[count + 1] == '\0')
// 		return (0);
// 	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
// 	if (*backup == '\0')
// 	{
// 		free(backup);
// 		backup = NULL;
// 	}
// 	line[count + 1] = '\0';
// 	return (backup);
// }

// // ALLOC
// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		*buffer;
// 	static char	*storage;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (0);
// 	line = make_line(fd, buffer, storage);
// 	free(buffer);
// 	buffer = NULL;
// 	if (!line)
// 	{
// 		return (NULL);

// 	}

// 	storage = extract(line);
// 	return (line);
// }


static char	*make_line(int fd, char *buffer, char *storage)
{
	char	*temp;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buffer); 
		free(temp);
		temp = NULL;
		if (!storage)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (NULL);
	return (storage);
}

static char	*my_extract(char *line)
{
	size_t	len;
	size_t	start;
	size_t	substring_len;
	char	*backup;
	char	*newline_pos;

	len = 0;
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos == NULL || *newline_pos == '\0')
		return (NULL);
	while (line[len] != '\0' && line + len != newline_pos)
		len++;
	if (line[len] == '\0')
		return (0);
	start = len + 1;
	substring_len = ft_strlen(line) - len;
	backup = ft_substr(line, start, substring_len);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[len + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*line;

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (0);
	}
	line = make_line(fd, buffer, storage);
	free(buffer);
	if (!line)
	{
		if (storage)
		{
			free(storage);
			storage = NULL;
		}
		return (NULL);
	}
	if (ft_strchr(line, '\n') || line != NULL)
		storage = my_extract(line);
	return (line);
}
