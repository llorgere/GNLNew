#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	printf("line est [%s] et strcmp est [%d]\n", line, strcmp(line, "abcd"));
	ret = get_next_line(p[0], &line);
	printf("line est [%s] et ret est [%d]\n", line, ret);
//	mt_assert(ret == 0);
}
/*
void	suite_12_test_line_of_4(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}*/
