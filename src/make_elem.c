#include	"huff.h"

t_elem		*make_elem(void)
{
  t_elem       	*new;

  if ((new = malloc(sizeof(t_elem))) == NULL)
    {
      printf("echec sur allocation d'elem\n");
      exit(EXIT_FAILURE);
    }
  new->dad = NULL;
  new->prev = NULL;
  new->next = NULL;
  new->deep = 0x0;
  new->sym = '\0';
  new->bit = '\0';
  new->length_bit = '\0';
  new->occu = 0;
  return (new);
}
