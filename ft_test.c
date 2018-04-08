#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char 	ft_test(char *file)
{
	char	*buff;
	int		fd;
	
	buff = malloc(sizeof(char) * 20);
	fd = open(file, O_RDONLY);
	read(fd, buff, 18);
	return (*(buff));
}

int		main(int ac, char **av)
{
	char 	c;

	c = ft_test(av[1]);
	printf("%c\n", c);
	return(0);
}
