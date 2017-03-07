#include	"huff.h"

char			*search_occu(char current, t_table *table,
				     char *big)
{
  t_index		*tmp;
  int			cmp;
  size_t		newsize;
  static	int	i = 0;

  tmp = table->start;
  while (current != tmp->sym)
    {
      tmp = tmp->next;
    }
  newsize = my_strlen(big) + tmp->len_bitcode;
  big = realloc(big, newsize);
  cmp = 0;
  while (tmp->bitcode[cmp] != '\0')
    {
      big[i] = tmp->bitcode[cmp];
      i++;
      cmp++;
    }
  big[i] = '\0';
  return (big);
}

void		write_big(t_file *file, char *big)
{
  int		i;
  char		buff;
  int		cmp;

  i = 0;
  cmp = 0;
  while (big[i] != '\0')
    {
      if (big[i] == '1')
	buff = buff | 1;
      else
	buff = buff | 0;
      if (cmp == 7 || big[i] == '\0')
	{
	  write(file->newfile, &buff, 1);
	  buff = 0x0;
	  cmp = 0;
	}
      else
	{
	  buff = buff << 1;
	  cmp++;
	}
      i++;
    }
  if (cmp != 0)
    write(file->newfile, &buff, 1);
}

void		make_bigstring(t_file *file, t_table *table,
			       char *namefile, char *name_huff)
{
  char		*big;
  char		tmp;

  if((file->fd = open(namefile, O_RDONLY)) == NULL)
    exit(EXIT_FAILURE);
  big = malloc(sizeof(char));
  while (read(file->fd, &tmp, 1) >= 1)
    {
      big = search_occu(tmp, table, big);
    }
  close(file->fd);
  printf("big = %s\n", big);
  printf("big = %d", my_strlen(big));
  if ((file->newfile = open(name_huff, O_WRONLY)) == NULL)
    exit(EXIT_FAILURE);
  if (lseek(file->newfile, 0, SEEK_END) == -1)
    exit(EXIT_FAILURE);
  write_big(file, big);
}
