#include "get_next_line.h"
#include <stdio.h>

int        main(void)
{
	//int fd = open("one_big_fat_line.txt", O_RDONLY);
	int fd = open("large_file.txt", O_RDONLY);
	char    *line = NULL;
	int 	ret;
	ret = 0;
	printf("test 1 du main, fd est %d\n", fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
	printf("test 2 du main\n");
	//	printf("%s\n", line);
	ft_putstr(line);
	ft_putchar('\n');
	}
	printf("test 3 du main\n");
	close(fd);
	printf("test 4 du main\n");
	return (0);
}
/*
int	 main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = open(large_file.txt);
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	dup2(out, fd);
	close(p[1]);
//	get_next_line(p[0], &line);
	printf("[%d]", get_next_line(p[0], &line));
//	mt_assert(strcmp(line, "aaa") == 0);
	printf("1 line est [%s]\n", line);
//	get_next_line(p[0], &line);
	printf("[%d]", get_next_line(p[0], &line));
//	mt_assert(strcmp(line, "bbb") == 0);
	printf("2 line est [%s]\n", line);
//	get_next_line(p[0], &line);
//	printf("[%d]", get_next_line(p[0], &line));
//	mt_assert(strcmp(line, "ccc") == 0);
//	printf("3 line est [%s]\n", line);
//	printf("[%d]", get_next_line(p[0], &line));
	//get_next_line(p[0], &line);
//	printf("4 line est [%s]\n", line);
//	mt_assert(strcmp(line, "ddd") == 0);
//	printf("[%d]", get_next_line(p[0], &line));
	close fd
	return (0);
}*/
