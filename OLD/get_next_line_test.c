/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:39:26 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 16:49:22 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		ft_test_rest(char *rest)
{
	int		i;

	i = 0;
//	if (rest)
//	printf("test 1 de ft_test_rest {%s}\n", rest);
	if (rest)
	{
//	printf("test 1 de ft_test_rest {%s}\n", rest);
	//	printf("len de rest est [%zu]", ft_strlen(rest));
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

//	printf("test 1 de copy_toline\n");
	end = 0;
	if (*line)
		free(*line);
	j = ft_test_rest(*rest);
	if (j < -1)
	{
		j = (j / (-2)) - 1;
		end++;
	}
//	printf("test  de copy_toline rest : {%s} j est [%d] end est [%d] et rest + j + 1 - end est [%s]\n", *rest, j, end, *rest + j + 1 - end);
/*	if(!(*line = malloc(sizeof(char) * (j + 1))))
		return ;
*/	*linef = ft_strndup(*rest, j);
	tmp = ft_strdup(*rest + j + 1 - end);
	free(*rest);
	*rest = ft_strdup(tmp);
	free(tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char *rest = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*linef;
	int			size;
	char		*tmp;

	size = -1;
	if (fd < 0)
		return (-1);
	if(size >= 0)
		ft_strclr(buff);
	if (ft_test_rest(rest) <= -1)
	{
		size = read(fd, buff, BUFF_SIZE);
		buff[size] = '\0';
	//	printf("size est [%d], buff est [%s] test de buff est {%d} et test de rest est{%d}\n", size, buff, ft_test_rest(buff), ft_test_rest(rest));
		if (ft_test_rest(buff) == -2 && ft_test_rest(rest) == -2)
		{
//			printf("size est [%d], buff est [%s]\n", size, buff);
			if (rest)
				free(rest);
			if (*linef)
				free(*linef);
			*line = NULL;
			return (0);
		}
		else if (ft_test_rest(rest) == -1)
		{
//		printf("size est [%d], buff est [%s] test de buff est {%d} et test de rest est{%d}\n", size, buff, ft_test_rest(buff), ft_test_rest(rest));
		//	printf("rest est inconnu\n");
			rest = ft_strdup(buff);
//			printf("rest est [%s}\n", rest);
		}
		else if (ft_test_rest(rest) < -1 && ft_test_rest(buff) != -2)
		{
//			printf("size est [%d], buff est [%s]\n", size, buff);
			tmp = ft_strjoin(rest, buff);
			free(rest);
			rest = tmp;
		}
		while (ft_test_rest(rest) <= -1 && ft_test_rest(buff) != -2)
		{
			if (size >= 0)
				ft_strclr(buff);
			read(fd, buff, BUFF_SIZE);
			tmp = ft_strjoin(rest, buff);
			free(rest);
			rest = tmp;
		}
//		printf("test 2 de gnl\n");
		ft_copy_to_line(&(rest), linef);
		*line = linef;
		return (1)
	}
	else
	{
		ft_copy_to_line(&(rest), linef);
		*line = linef;
		if (size >= 0)
			ft_strclr(buff);
		return (1);
	}
}
