#include	"huff.h"

int		resolve_nb_oct(int deep)
{
  int		res;
  char		nb;

  res = deep;
  nb = 0;
  while (res > 0)
    {
      res = res - 8;
      nb++;
    }
  return (nb);
}

t_elem		*write_oct(t_elem *node, t_file *file)
{
  t_elem	*tmp;
  signed char	oct;

  tmp = node;
  while (tmp->dad != NULL)
    {
      oct = 0x0;/*ajout*/
      if (tmp->bit == '1')
	{
	  //	  oct = oct | 1;
	  oct = 49;
	  write(file->newfile, &oct, 1);
	}
      else
	{
	  oct = 48;
	  //oct = oct | 0;
	  write(file->newfile, &oct, 1);
	}
      tmp = tmp->dad;
    }
  return (tmp);
}

int			depile_node(t_elem *node, t_file *file)
{
  t_elem		*tmp;
  int			nb_oct;
  signed char	       	oct;

  tmp = node;
  node->deep = node->deep + 1;
  oct = 0x0;
  write(file->newfile, &node->sym, 1);
  write(file->newfile, &node->deep, 1);
  while (tmp->dad != NULL)
    {
      tmp = write_oct(tmp, file);
    }
  //  oct = oct | 1;
  oct = 49;
  write(file->newfile, &oct, 1);
  return (0);
}

t_elem		*fill_bit(t_elem *node, t_file *file, char pro)
{
  node->deep = pro;
  if (node->gauche == NULL)
    depile_node(node, file);
  else if (node->droite == NULL)
    depile_node(node, file);
  if (node->gauche != NULL)
    {
      node->gauche->bit = '0';
      fill_bit(node->gauche, file, pro + 1);
    }
  if (node->droite != NULL)
    {
      node->droite->bit = '1';
      fill_bit(node->droite, file, pro + 1);
    }
  return (node);
}
