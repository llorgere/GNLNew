/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:39:26 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/08 19:51:17 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
/*
int		ft_test_rest(char *rest)
{
	int		i;

	i = 0;
	if (rest)
	{
		while (rest && i < ((int)ft_strlen(rest) + 1))
		{
			if (rest[i] == '\n')
				return (i);
			else if (rest[i] == '\0')
				return (-2 * (i + 1));
			i++;
		}
	}
	return (-1);
}

void	ft_copy_to_line(char **rest, char **line)
{
	int		j;
	int		end;
	char	*tmp;
	char	*tmpl;

	end = 0;
	j = ft_test_rest(*rest);
	if (j < -1)
	{
		j = (j / (-2)) - 1;
		end++;
	}
	tmpl = ft_strndup(*rest, j);
	*line = tmpl;
	tmp = ft_strdup(*rest + j + 1 - end);
	free(*rest);
	*rest = ft_strdup(tmp);
	free(tmp);
}
*/
char	*gnl_read(char	**rest, char *str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	//printf("test de gread 1\n");
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = *rest;
	//	printf("test de gread 2 buff est [%s]\n", buff);
		if (!*rest)
			*rest = ft_strdup(buff);
		else
		{
			if(!(*rest = ft_strjoin(*rest, buff)))
				return (NULL);
		}
		//printf("test de gread 3 rest est [%s]\n", *rest);
		free(tmp);
		if ((str = ft_strchr(*rest, '\n')))
			return (str);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *rest = NULL;
	//char *rest;
	/*char		*buff;
	int			size;
	char		*tmp;
	*/
	char		*str;
	char			*tmp2;
	
	//printf("test 1\n");
	if (fd < 0 || !line || read(fd, rest, 0) < 0)
		return (-1);
	//printf("test 2 et rest est [%s]\n", rest);
	if (rest)
	str = ft_strchr(rest, '\n');
	//printf("test 3 str est [%s]\n", str);
	if (!str)
		str = gnl_read((char **)&rest, str, fd);
	//printf("test 4 str est [%s]\n", str);
	if (str)
	{
		*str = '\0';
		*line = ft_strdup(rest);
		tmp2 = rest;
		//printf("test boucle\n");
		rest = ft_strdup(str + 1);
		free(tmp2);
		return (1);
	}
	//printf("test 5 rest [%s]\n", rest);
	*line = ft_strdup(rest);
	//printf("test 6\n");
	rest = ft_strdup("\0");
	//printf("test 7\n");
	//return (0);
	if (**line)
		return (1);
	else
		return (0);
/*	size = -1;
	buff = ft_strnew(BUFF_SIZE); //test de malloc plutot que array
	if (fd < 0 || !line)
		return (-1);
	if (ft_test_rest(rest) <= -1)
	{
		size = read(fd, buff, BUFF_SIZE);
		if (size == -1)
		{
			if(buff) //ajout malloc
				free(buff);// ajout malloc
			return (-1);
		}
		if (ft_test_rest(buff) == -2 && ft_test_rest(rest) == -2)
		{
			if(buff) //ajout malloc
				free(buff);// ajout malloc
			*line = NULL;
			return (0);
		}
		else if (ft_test_rest(rest) == -1)
			rest = ft_strdup(buff);
		else if (ft_test_rest(rest) < -1 && ft_test_rest(buff) != -2)
		{
			tmp = ft_strjoin(rest, buff);
			free(rest);
			rest = tmp;
			//printf("1 buff est [%s]\n", buff);
		}
		while (ft_test_rest(rest) < -1 && ft_test_rest(buff) != -2)
		{
			//printf("test de buff 1\n");
			if(buff)
				free(buff);
			//printf("test de buff 2\n");
			buff = ft_strnew(BUFF_SIZE); //test de malloc plutot que array
			//printf("test de buff 3\n");
			size = read(fd, buff, BUFF_SIZE);
			//printf("rest = [%s] et buff est [%s]\n", rest, buff);
			tmp = ft_strjoin(rest, buff);
			free(rest);
			//printf("test de buff 4\n");
			//printf("2 buff est [%s]\n", buff);
			//printf("countc = [%d]\n", countc);
			countc++;
			rest = tmp;
		}
		ft_copy_to_line(&(rest), line);
		return (1);
	}
	else
	{
		ft_copy_to_line(&(rest), line);
		if (buff)
			free(buff);
		return (1);
	}*/
}
