//#include <project.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "efghijkl", 8);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	printf("line est [%s], la valeur de strcmp est[%d]", line, strcmp(line, "efghijkl"));
}
/*
void	suite_16_test_line_of_8_without_nl(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
*/
