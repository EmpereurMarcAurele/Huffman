#include	"huff.h"

char			*brok_oct(char *big, char current)
{
  size_t		newsize;
  static	int	j = 0;
  int			i;

  newsize = my_strlen(big) + 8;
  big = realloc(big, newsize);
  i = 7;
  while (i >= 0)
    {
      if (current & (1 << i))
	{
	  big[j] = '1';
	}
      else
	{
	  big[j] = '0';
	}
      i--;
      j++;
    }
  big[j] = '\0';
  return (big);
}

void		make_big_dec(t_file *file, t_table *table,
			     char *namefile, char *newfile)
{
  char		tmp;
  char		*big;

  big = malloc(sizeof(char));
  while (read(file->newfile, &tmp, 1) >= 1)
    {
      big = brok_oct(big, tmp);
    }
  close(file->newfile);
  printf("big decomp = %s\n", big);
  printf("big decomp = %d", my_strlen(big));
}

int		my_decompress(char *namefile)
{
  t_file	*file;
  t_table	*buff_table;
  char		name_dec[] = "test.decompress";

  buff_table = make_table();
  stock_tab(file, buff_table, namefile);
  if ((file->fd = open(name_dec, O_RDWR | O_TRUNC | O_CREAT,
                            S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR)) == -1)
    exit(EXIT_FAILURE);
  make_big_dec(file, buff_table, namefile, name_dec);
  return (0);
}
