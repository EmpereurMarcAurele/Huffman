#include	<stdlib.h>
#include	"huff.h"

void		error_arg(int ac, char **av)
{
  if (ac != 2 || av == NULL)
    exit(EXIT_FAILURE);
}
