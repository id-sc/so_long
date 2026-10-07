/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:23:39 by hesainte          #+#    #+#             */
/*   Updated: 2025/12/23 16:45:44 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	hasline(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//called only when buffer contains a \n or all the remaining text
//new line: all the characters until the \n included
//new line: the rest of the characters if no \n
//returns new line
char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc((ft_strlen(buffer) + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

//keeps all the characters after the first \n found
//returns the updated buffer
char	*update_buffer(char	*buffer, char *line)
{
	char	*newbuffer;
	int		i;
	int		lenline;
	int		lenbuffer;

	if (!line || !buffer)
		return (NULL);
	lenline = ft_strlen(line);
	lenbuffer = ft_strlen(buffer);
	if (lenline >= lenbuffer)
		return (ft_reset(&buffer), NULL);
	newbuffer = ft_calloc((lenbuffer - lenline + 1), sizeof(char));
	if (!newbuffer)
		return (ft_reset(&buffer), NULL);
	i = ft_strlen(line);
	while (buffer[i])
	{
		newbuffer[i - lenline] = buffer[i];
		i++;
	}
	ft_reset(&buffer);
	return (newbuffer);
}

//reads until bytesread == 0 and breaks if there is a \n
//joins the buff to the buffer
//free the buff and return the buffer
char	*read_file(int fd, char *buffer)
{
	char	*buff;
	char	*tmp_buffer;
	int		bytesread;

	bytesread = 1;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!hasline(buffer) && bytesread > 0)
	{
		if (fd < 0 || BUFFER_SIZE <= 0)
			return (ft_reset(&buffer), ft_reset(&buff), NULL);
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread == -1)
			return (ft_reset(&buffer), ft_reset(&buff), NULL);
		buff[bytesread] = '\0';
		tmp_buffer = buffer;
		buffer = ft_strjoin(buffer, buff);
		if (!buffer)
			return (ft_reset(&tmp_buffer), ft_reset(&buff), NULL);
		ft_reset(&tmp_buffer);
	}
	return (ft_reset(&buff), buffer);
}

//calls read_file if buffer doesnt contain the \n (will read until \n or end)
//calls extract_line to extract the new line (until \n or the end)
//calls update_buffer to remove the new_line from it
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			ft_reset(&buffer);
		return (NULL);
	}
	if (!buffer)
	{
		buffer = ft_calloc(sizeof(char), 1);
		if (!buffer)
			return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer || !*buffer)
		return (ft_reset(&buffer), NULL);
	line = extract_line(buffer);
	if (*line == '\0')
		return (ft_reset(&buffer), ft_reset(&line), NULL);
	buffer = update_buffer(buffer, line);
	return (line);
}

/*
int	main()
{
//	printf("%s", extract_line("coucou \n ca \n va hehe"));
//	printf("%s", extract_line("coucou ca va \n hehe"));
	int	fd;
	int	count;
	char	*line;
	char	*file;

	file = "sample.txt";
	fd = open(file, O_RDONLY); //chercher video sur open()
	if (fd == -1)
		printf("\n Error opening file %s\n", file);
	else
		printf("\nFile %s opened successfully\n", file);
	count = 1;
	while (count <= 5)
	{
		line = get_next_line(fd);
		printf("[line %d] %s", count, line);
		count++;
		ft_reset(&line);
	}
	close(fd);
	return (0);
}
*/
