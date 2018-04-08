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

	printf("test 15\n");
	i = 0;
	printf("test 16\n");
	if (rest)
		printf("la longueur de rest est [%zu]\n", ft_strlen(rest));
	while (rest && i < ((int)ft_strlen(rest) + 1))
	{
//		printf("test 16.1\n");
		if (rest[i] == '\n')
			return (i);
		else if (rest[i] == '\0')
			return (-2 * (i + 1));
//		printf("test 18\n");
		i++;
	}
	printf("test 17\n");
	return (-1);
}

void	ft_copy_to_line(char **rest, char **line)
{
	int 	i;
	size_t	j;
	char	*tmp;

	printf("test 19 || rest est [%s]\n", *rest);
	i = 0;
	j = ft_test_rest(*rest);
	if ((int)j < -1)
		j = (j / (-2)) - 1;
//	printf("test 20 | j est %d et i est %d\n", j, i);
	*line = malloc(sizeof(char) * (j + 1));
//	printf("test 21 | j est %d\n", j);
/*	while (i < j)
	{
		printf("test 22 | line est %s et i est %d et rest[i] est %c\n", line, i, rest[i]);
		line[i] = rest[i];
		rest[i + 32] = '\0';
		printf("test 22.5 | line est %s et i est %d et rest[i + 32] est %c\n", line, i, rest[i + 32]);
		printf("test 23 | line est [%s]et rest est [%s]\n", line, rest);
		i++;
	}
	printf("test 24\n");
	line[j] = '\0';
*/	*line = ft_strndup(*rest, j);
	printf("test 25 | le rest est [%s] et line est [%s]\n", (*rest + j), *line);
//	j = 0;
	tmp = ft_strdup(*rest + j + 1);
	printf("test 26 tmp est [%s]\n", tmp);
	printf("test 27 | rest [%s]\n", *rest);
	*rest = ft_strdup(tmp);
	free(tmp);
	printf("test 28 | rest [%s] et line est [%s]\n", *rest, *line);
}

int		get_next_line(const int fd, char **line)
{
	static char *rest = NULL;
	char		buff[BUFF_SIZE];
//	char 		*tmp;

	printf("test 1 | rest est [%s]\n", rest);
	printf("test_rest de rest est %d\n", ft_test_rest(rest));
	if (ft_test_rest(rest) <= -1)
	{
		// on read un buff de plus 
		// et on boucle si on ne trouve pas de '\n'
	//	printf("test 2\n");
		read(fd, buff, BUFF_SIZE);
		printf("test rest de buff est [%d]\n", ft_test_rest(buff));
		if (ft_test_rest(buff) == -1)
		{
			if (*line)
			{
				printf("test 6.5 si line existe [%s]\n", *line);
				free(*line);
			}
//			free(buff);
			printf("test 7\n");
			ft_copy_to_line(&(rest), line);
			free(rest);
			printf("test 8 | line est [%s]\n", *line);
			return (0);
		}
		else if (ft_test_rest(rest) == -1 && ft_test_rest(buff) != -1)
		{
			rest = ft_strdup(buff);
//			ft_strclr(buff);
		}
		else if (ft_test_rest(rest) < -1 && ft_test_rest(buff) != -1)
		{
			printf("test_rest de rest et %d et test_rest de buff est %d\n", ft_test_rest(rest), ft_test_rest(buff));
			printf("rest est [%s] et buff est [%s]\n", rest, buff);
			rest = ft_strjoin(rest, buff);
//			printf("rest est [%s] et buff est [%s]", rest, buff);
			printf("rest est [%s] et buff est [%s]\n", rest, buff);
//			free(buff);
		}
	//	printf("test 3\n");
		while(ft_test_rest(rest) < 0 && ft_test_rest(buff) != -1)
		{
			ft_strclr(buff);
			printf("test 4 | buff est [%s]\n", buff);
			read(fd, buff, BUFF_SIZE);
			printf("test 4.1 | rest est [%s]\n", rest);
//			rest = malloc(sizeof(char) * BUFF_SIZE);
			rest = ft_strjoin(rest, buff);
			ft_strclr(buff);
			printf("test 4.2 | rest est [%s]\n", rest);
			printf("test 5 | rest est [%s]\n", rest);
/*			if (ft_test_rest(rest) == 0)
			{
				printf("test 5.1 | verif non boucle\n");
				read(fd, buff, BUFF_SIZE);
			}
*/			printf("test 6\n");
		}
		if (*line)
		{
			printf("test 6.5 si line existe [%s]\n", *line);
			free(*line);
		}
		printf("test 7\n");
		ft_copy_to_line(&(rest), line);
		ft_strclr(buff);
		printf("test 8 | line est [%s]\n", *line);
		return (1);
	}
	else
	{
		if (*line)
		{
			printf("test 6.5 si line existe [%s]\n", *line);
			free(*line);
		}
		printf("test 10\n");
		ft_copy_to_line(&(rest), line);
		printf("test 11\n");
		ft_strclr(buff);
		return (1);
	}
/*	else
	{
		printf("test 12\n");
		free(rest);
		printf("test 13\n");
//		free(buff);
		printf("test 14\n");
		return (0);
	}*/
}
