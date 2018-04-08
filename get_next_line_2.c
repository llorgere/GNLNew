/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 14:49:32 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 18:33:42 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		ft_strlen_int(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_buff_cpy(int i, char *buff)
{
	char	*str;
	int 	j;

	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	while (j < i)
	{
		str[j] = buff[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}


int			get_next_line(const int fd, char **line)
{
	static char		*tmp = NULL;
	//	char			*r_line;
	//	int				nb_read;
	int				i;
	char 			buff[BUFF_SIZE];

	//	nb_read = 1;
	//	free(&(line));
	printf("test 1\n");
	while (read(fd, buff, BUFF_SIZE))
	{
		printf("test 2\n");
		i = 0;
		while (i <  BUFF_SIZE)
		{
			printf("test 3\n");
			if (buff[i] == '\n')
			{
				printf("test 4\n");
				printf("la bonne partie de buff est [%s]\n", ft_buff_cpy(i, buff));
				printf("tmp est [%s]\n", tmp);
				// copie buff jusqu'a buff[i - 1] dans line
//				*line = (char *)malloc(sizeof(char) * (ft_strlen_int(tmp) + ft_strlen_int(ft_buff_cpy(i, buff)) + 1));
				printf("test du malloc de line\n");
				*line = ft_strjoin(tmp, ft_buff_cpy(i, buff));
				printf("line est [%s]\n", *line);
				free(tmp);
				free(ft_buff_cpy(i, buff));
				tmp = ft_strdup(buff + i);
				return (1);
			}
			//		printf("test 5\n");
			else if (buff[i] == '\0')
			{
				printf("test 6\n");
				*line = (char *)malloc(sizeof(char) * (ft_strlen_int(tmp) + ft_strlen_int(buff) + 1));
				*line = ft_strjoin(tmp, ft_buff_cpy(i, buff));
				free(ft_buff_cpy(i, buff));
				free(tmp);
				return (1);
			}
			printf("test 7\n");
			i++;
		}
		printf("test 8\n");
		//		tmp = (char*)malloc(sizeof(char) * BUFF_SIZE * nb_read);
		tmp = ft_strjoin(tmp, buff);
		//		nb_read++;
	}
	printf("test 9\n");
	return (0);
}
