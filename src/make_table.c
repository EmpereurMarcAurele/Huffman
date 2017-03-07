#include	"huff.h"

t_table		*make_table(void)
{
  t_table	*new;

  if ((new = malloc(sizeof(t_table))) == NULL)
    exit(EXIT_FAILURE);
  new->start = NULL;
  new->end = NULL;
  new->nb_sym = 0x0;
  new->length = 0;
  return (new);
}
