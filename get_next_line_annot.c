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

//	printf("test ft_test_rest 1\n");
	i = 0;
//	printf("test ft_test_rest 2\n");
	if (rest)
//		printf("test ft_test_rest 3 | la longueur de rest est [%zu]\n", ft_strlen(rest));
	while (rest && i < ((int)ft_strlen(rest) + 1))
	{
//		printf("test ft_test_rest 3.05|| rest[i] est [%c]\n", rest[i]);		
		if (rest[i] == '\n')
		{
//			printf("test de ft_test_rest 3.1 || i y a un ret ligne, i est %d\n", i);
			return (i);
		}
		else if (rest[i] == '\0')
		{
//			printf("test de ft_test_rest 3.2 || i y a pas un ret ligne, i est %d\n", i);
			return (-2 * (i + 1));
		}
//		printf("test 18\n");
		i++;
	}
//	printf("test ft_test_rest 4\n");
	return (-1);
}

void	ft_copy_to_line(char **rest, char **line)
{
	int		j;
	int 	end;
	char	*tmp;

	printf("test ft_copy_line 1 || rest est [%s]\n", *rest);
	end = 0;
	if (*line)
	{
		free(*line);
	}
	j = ft_test_rest(*rest);
//	printf("test ft_copy_line 1.5 || j est [%d]\n", j);
	if (j < -1)
	{
		j = (j / (-2)) - 1;
		end++;
	}
//	printf("test 20 | j est %d et i est %d\n", j, i);
	if(!(*line = malloc(sizeof(char) * (j + 1))))
		return ;
	printf("test 21 | j est %d\n", j);
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
	printf("test ft_copy_line 2 || le rest est [%s] et line est [%s]\n", (*rest), *line);
//	j = 0;
	tmp = ft_strdup(*rest + j + 1 - end);
	printf("test ft_copy_line 3.1 || tmp est [%s]\n", tmp);
//	ft_strclr(*rest);
	free(*rest);
	printf("test ft_copy_line 3.2 || tmp est [%s]\n", tmp);
	printf("test ft_copy_line 4 || rest [%s] et ft_test_rest est [%d]\n", *rest, ft_test_rest(*rest));
	*rest = ft_strdup(tmp);
	free(tmp);
	printf("test ft_copy_line 5 || rest [%s] et line est [%s] et ft_test_rest est [%d]\n", *rest, *line, ft_test_rest(*rest));
}

int		get_next_line(const int fd, char **line)
{
	static char *rest = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			size;

	if (!fd || fd < 0)
		return (-1);
	printf("test get_next_line 1 || rest est [%s]\n", rest);
	printf("test get_next_line 2 || test_rest de rest est %d\n", ft_test_rest(rest));
	ft_strclr(buff);
	printf("test get_next_line 2.1 || buff est [%s]\n", buff);
	printf("test get_next_line 2.2 || test_rest de buff est %d\n", ft_test_rest(buff));
	if (ft_test_rest(rest) <= -1)
	{
		// on read un buff de plus 
		// et on boucle si on ne trouve pas de '\n'
	//	printf("test 2\n");
		size = read(fd, buff, BUFF_SIZE);
		buff[size] = '\0';
		printf("test get_next_line 3 || test rest de buff est [%d], buff est [%s] et size est [%d] et buff[size] est [%c]\n", ft_test_rest(buff), buff, size, buff[size]);
		if (ft_test_rest(buff) == -2 && ft_test_rest(rest) == -2)
		{
			free(rest);
			free(*line);
			printf("verif du return 0\n");
			return (0);
		}
/*		else if (ft_test_rest(buff) == -1)
		{
			if (*line)
			{
				printf("test get_next_line 4 || si line existe [%s]\n", *line);
				free(*line);
			}
			ft_strclr(buff);
			printf("test get_next_line 5 || buff est [%s]\n", buff);
			ft_copy_to_line(&(rest), line);
			free(rest);
			printf("test get_next_line 6 || line est [%s]\n", *line);
			return (0);
		}
*/		else if (ft_test_rest(rest) == -1)
		{
			rest = ft_strdup(buff);
//			ft_strclr(buff);
		}
		else if (ft_test_rest(rest) < -1 && ft_test_rest(buff) != -2)
		{
			printf("test get_next_line 7 ||test_rest de rest et %d et test_rest de buff est %d\n", ft_test_rest(rest), ft_test_rest(buff));
			printf("test get_next_line 8 ||rest est [%s] et buff est [%s]\n", rest, buff);
			tmp = ft_strjoin(rest, buff);
			free(rest);
			rest = tmp;
			free (tmp);
//			printf("rest est [%s] et buff est [%s]", rest, buff);
			printf("test get_next_line 9 ||rest est [%s] et buff est [%s]\n", rest, buff);
//			ft_strclr(buff);
			printf("test get_next_line 9.1 ||rest est [%s] et buff est [%s]\n", rest, buff);
		}
	//	printf("test 3\n");
		while (ft_test_rest(rest) <= -1 && ft_test_rest(buff) != -2)
		{
			ft_strclr(buff);
			printf("test get_next_line 10 || rest est [%s]\n", rest);
			read(fd, buff, BUFF_SIZE);
			printf("test get_next_line 11 || buff est [%s]\n", buff);
//			rest = malloc(sizeof(char) * BUFF_SIZE);
			tmp = ft_strjoin(rest, buff);
			free(rest);
			rest = tmp;
//			free (tmp);
//			ft_strclr(buff);
			printf("test get_next_line 12 || rest est [%s]\n", rest);
//			printf("test get_next_line 13 || rest est [%s]\n", rest);
/*			if (ft_test_rest(rest) == 0)
			{
				printf("test 5.1 | verif non boucle\n");
				read(fd, buff, BUFF_SIZE);
			}
*/			printf("test get_next_line 14i test_rest de buff est [%d]\n", ft_test_rest(buff));
		}
/*		if (*line)
		{
			printf("test get_next_line 15 || si line existe [%s]\n", *line);
			ft_strclr(*line);
			free(*line);
			printf("test get_next_line 15.1 || si line existe [%s]\n", *line);
		}
*/		printf("test get_next_line 16 || buff est [%s]\n", buff);
		ft_copy_to_line(&(rest), line);
//		ft_strclr(buff);
		printf("test get_next_line 17 || line est [%s] et buff est [%s]\n", *line, buff);
		printf("verif du return 1\n");
		return (1);
	}
	else
	{
/*		if (*line)
		{
			printf("test get_next_line 18 || si line existe [%s]\n", *line);
			ft_strclr(*line);
			free(*line);
			printf("test get_next_line 18.1 || si line existe [%s]\n", *line);
		}
*/		printf("test get_next_line 19 ||\n");
		ft_copy_to_line(&(rest), line);
		printf("test get_next_line 20 || line est [%s] et buff est [%s]\n", *line, buff);
		ft_strclr(buff);
		printf("test get_next_line 21 || line est [%s] et buff est [%s]\n", *line, buff);
		printf("verif du return 1\n");
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
