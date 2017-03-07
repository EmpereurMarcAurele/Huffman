#include	"huff.h"

char		*reverse_str(char *s)
{
  int		len;
  int		i;
  int		max;
  char		*new;

  len = my_strlen(s);
  max = len;
  i = 0;
  new = malloc(sizeof(char) * len + 1);
  len = len - 1;
  while (i < max)
    {
      new[i] = s[len];
      i++;
      len--;
    }
  new[i] = '\0';
  return (new);
}

void		reverse_bitcode(t_table *table)
{
  t_index	*tmp;
  int		i;

  tmp = table->start;
  i = 0;
  while (i < table->length)
    {
      tmp->bitcode = reverse_str(tmp->bitcode);
      tmp = tmp->next;
      i++;
    }
}
