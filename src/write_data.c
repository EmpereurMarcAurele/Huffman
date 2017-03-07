#include	"huff.h"

int			write_bitcode(int un_zero, t_file *file)
{
  static	char	buff = 0;
  static	int	pos_buff = 0;

  if (pos_buff == 7)
    {
      printf("ECRIT\n");
      write(file->newfile, &buff, 1);
      buff = 0;
      pos_buff = 0;
    }
  if (un_zero == 0)
    buff = buff | 0;
  else if (un_zero == 1)
    buff = buff | 1;
  buff = buff << 1;
  pos_buff++;
  
  printf("3\n");
  return (0);
}

int		write_octet(char octet_a_lire, int nb_bit, t_file *file)
{
  int		bit_a_lire;
  int		bit_lu;

  bit_a_lire = nb_bit;
  bit_lu = 0;
  while (bit_a_lire > 0 && bit_lu < nb_bit)
    {
      printf("2\n");
      if (octet_a_lire & (1 << bit_lu))
	write_bitcode(1, file);
      else
	write_bitcode(0, file);
      bit_a_lire--;
      bit_lu++;
    }
  return (bit_lu);
}

int		witch_octet(int pos_tab, t_file *file)
{
  int		nb_octet;
  int		len_bitcode;
  int		nb_bit_a_lire;
  int		bit_lu;
  char		octet_a_lire;

  nb_octet = resolve_nb_oct(file->tab[pos_tab][1]);
  len_bitcode = file->tab[pos_tab][1];
  printf("DEPART len_bitcode: %d\n", len_bitcode);
  nb_bit_a_lire = 0;
  bit_lu = 0;
  while (len_bitcode > 0)
    {
      printf("1\n");
      octet_a_lire = file->tab[pos_tab][nb_octet + 1];
      nb_bit_a_lire  = len_bitcode - ((nb_octet - 1) * 8);
      bit_lu = write_octet(octet_a_lire, nb_bit_a_lire, file);
      nb_octet--;
      len_bitcode = len_bitcode - bit_lu;
      printf("len_bitcode = %d\n", len_bitcode);
    }
  return (0);
}

/*
int		func(t_file *file, int i)
{
  int		len_bitcode;
  int		nb_oct;
  int		a_lire;
  int		bit_lu;
  static int	cmp_bit;
  static char	buff;
  int   	pos_bit_current;
  char		current;


  len_bitcode = file->tab[i][1];
  nb_oct = resolve_nb_oct(file->tab[i][1]);
  while (len_bitcode > 0 || nb_oct > 0)
    {
      bit_lu = len_bitcode - ((nb_oct - 1) * 8);
      a_lire = bit_lu;
      current = file->tab[i][nb_oct + 1];
      pos_bit_current = 0;    
      while (a_lire > 0)
	{
	  buff = (current & (1 << tmp)) ? buff | 1 : buff | 0;
	  if (cmp_bit == 7)
	    {
	      printf("\nECRIT!!!\n");
	      write(file->newfile, &buff, 1);
	      cmp_bit = 0;
	      buff = 0x0;
	    }
	  cmp_bit++;
	  buff = buff << 1;
	  pos_bit_current++;
	  a_lire--;
	}
      len_bitcode = len_bitcode - bit_lu;
      nb_oct--;
    }
  return (0);
}
*/

int		write_data(t_file *file)
{
  int		i;

  i = 0;
  while (i < file->length)
    {
      witch_octet(i, file);
      // func(file, i);
      i++;
    }
  printf("i = %d\n", i);
  return (0);
}
