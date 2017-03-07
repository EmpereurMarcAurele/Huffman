#include	"huff.h"

int		main(int ac, char **av)
{
  char		namefile[] = "test.huff";

  error_arg(ac, av);
  my_compress(av[1]);
  my_decompress(namefile);
     /*
  if (is_huff_file(av[1]) == -1)
    {
      my_compress(namefile);
    }
  else
    {
      my_decompress(av[1]);
    }
     */
  return (0);
}
