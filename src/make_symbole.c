#include	"huff.h"

void		send_oct(char oct, t_list *table)
{
  if (table->length == 0)
    add_elem(oct, table);
  else
    {
      if (exist_oct(oct, table) == -1)
	add_elem(oct, table);
      else
	add_occu(oct, table);
    }
}

void		sort_list(t_list *table)
{
  t_elem	*curr;
  t_elem	*tmp;
  int		i;
  int		j;

  i = 0;
  tmp = make_elem();
  while (i < table->length)
    {
      curr = table->start;
      j = 0;
      while (j < table->length)
	{
	  if (curr->next != NULL && curr->occu > curr->next->occu)
	    {
	      tmp->sym = curr->sym;
	      tmp->occu = curr->occu;
	      curr->sym = curr->next->sym;
	      curr->occu = curr->next->occu;
	      curr->next->sym = tmp->sym;
	      curr->next->occu = tmp->occu;
	    }
	  curr = curr->next;
	  j++;
	}
      i++;
    }
}

void		make_symbole(t_file *file, t_list *table)
{
  char		oct;

  while (read(file->fd, &oct, 1) >= 1)
    {
      send_oct(oct, table);
    }
  sort_list(table);
}
