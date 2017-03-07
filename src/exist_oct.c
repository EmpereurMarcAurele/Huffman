#include	"huff.h"

int		exist_oct(char oct, t_list *table)
{
  t_elem	*tmp;
  int		i;

  tmp = table->start;
  i = 0;
  while (i < table->length)
    {
      if (my_compare(oct, tmp->sym) == 0)
	return (0);
      tmp = tmp->next;
      i++;
    }
  return (-1);
}
