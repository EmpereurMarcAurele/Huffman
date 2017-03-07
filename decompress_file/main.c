#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>

int		main()
{
  int		fd;
  char		a;
  int		i;

  a = '\0';
  fd = open("alltable", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
  while (a < 127)
    {
      i = 0;
      while (i < 1000000)
	{
	  write(fd, &a, 1);
	  i++;
	}
      a++;
    }
  printf("long = %d\n", sizeof(long double));
  return (0);
}
