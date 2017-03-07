#include	"huff.h"

t_index		*set_index(void)
{
  t_index	*new;

  if ((new = malloc(sizeof(t_index))) == NULL)
    exit(EXIT_FAILURE);
  new->prev = NULL;
  new->next = NULL;
  new->sym = 0x0;
  new->len_bitcode = 0x0;
  new->bitcode = NULL;
  return (new);
}

void		add_index(t_table *table)
{
  t_index	*new;

  new = set_index();
  if (table->length == 0)
    {
      table->start = new;
      table->end = new;
    }
  else
    {
      new->prev = table->end;
      new->prev->next = new;
      table->end = new;
    }
  new->next = NULL;
  table->length++;
}
