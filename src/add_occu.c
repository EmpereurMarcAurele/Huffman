#include	"huff.h"

int		add_occu(char oct, t_list *table)
{
  t_elem	*tmp;
  int		i;

  tmp = table->start;
  i = 0;
  while (i < table->length)
    {
      if (my_compare(tmp->sym, oct) == 0)
	{
	  tmp->occu++;
	  return (0);
	}
      tmp = tmp->next;
      i++;
    }
  return (-1);
}
