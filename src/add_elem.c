#include	"huff.h"

void		add_elem(char data, t_list *list)
{
  t_elem       	*newelem;
  
  newelem = make_elem();
  if (list->length == 0)
    {
      list->start = newelem;
      list->end = newelem;
    }
  else
    {
      newelem->prev = list->end;
      newelem->prev->next = newelem;
      list->end = newelem;
    }
  newelem->sym = data;
  newelem->occu = 1;
  newelem->next = NULL;
  list->length++;
}
