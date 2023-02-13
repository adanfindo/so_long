/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:26:50 by afindo          #+#    #+#             */
/*   Updated: 2022/03/01 14:28:52 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

char	*printline(char *str)
{
	int		i;
	char	*newbuffer;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
		return (NULL);
	newbuffer = malloc(sizeof(char) * i + 2);
	if (!newbuffer)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		newbuffer[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		newbuffer[i++] = '\n';
	newbuffer[i] = '\0';
	return (newbuffer);
}

char	*prepnext(char *str)
{
	int		i;
	int		j;
	char	*newbuffer;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	newbuffer = malloc(sizeof(char) * (i - j));
	if (!newbuffer)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		newbuffer[i++] = str[j++];
	newbuffer[i] = '\0';
	free(str);
	return (newbuffer);
}

int	numline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}	

char	*readresult(int fd, char *buffer, char *temp, char *str)
{
	int	res;

	res = 1;
	while (res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[res] = '\0';
		temp = str;
		if (temp == NULL)
		{
			temp = malloc(sizeof(char) * 1);
			temp[0] = '\0';
		}
		str = ft_strjoin(temp, buffer);
		free(temp);
		if (numline(str) == 1)
			break ;
	}
	free(buffer);
	return (str);
}	

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	char		*temp;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	str = readresult(fd, buffer, temp, str);
	if (str == NULL)
		return (NULL);
	line = printline(str);
	str = prepnext(str);
	return (line);
}
