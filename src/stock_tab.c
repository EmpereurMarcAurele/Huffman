#include	"huff.h"

void		show_bufftable(t_table *table)
{
  t_index	*tmp;
  int		i;

  i = 0;
  tmp = table->start;
  while(i < table->length)
    {
      printf("sym = %c; ", tmp->sym);
      printf("len_bitcode = %x; ", tmp->len_bitcode);
      printf("bitcode = %s;\n", tmp->bitcode);
      tmp = tmp->next;
      i++;
    }
  printf("len i = %d, len table = %d\n", i, table->length);
}

void		stock_tab(t_file *file, t_table *table, char *name)
{
  int		i;
  char		tmp;

  if ((file->newfile = open(name, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  if (read(file->newfile, &tmp, 1) <= 0)
    exit(EXIT_FAILURE);
  table->nb_sym = tmp;
  while (table->length < table->nb_sym)
    {
      add_index(table);
      read(file->newfile, &tmp, 1);
      table->end->sym = tmp;
      read(file->newfile, &tmp, 1);
      table->end->len_bitcode = tmp;
      table->end->bitcode = malloc(sizeof(char) * table->end->len_bitcode + 1);
      i = 0;
      while (i < table->end->len_bitcode)
	{
	  read(file->newfile, &tmp, 1);
	  table->end->bitcode[i] = tmp;
	  i++;
	}
      table->end->bitcode[i] = '\0';
    }
}
