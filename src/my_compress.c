#include	"huff.h"

int		my_compress(char *namefile)
{
  t_list       	*table;
  t_file	*file;
  t_table      	*buff_table;
  char		name_huff[] = "test.huff";

  /*ici lajout du .huff au fichier*/
  table = make_list();
  buff_table = make_table();
  file = set_file();
  if ((file->fd = open(namefile, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  make_symbole(file, table);
  close(file->fd);
  make_tree(table);
  if ((file->newfile = open(name_huff, O_RDWR | O_TRUNC | O_CREAT,
			    S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR)) == -1)
    exit(EXIT_FAILURE);
  write(file->newfile, &table->length_table, 1);
  fill_bit(table->start, file, 0);
  close(file->newfile);

  stock_tab(file, buff_table, name_huff);
  reverse_bitcode(buff_table);
  show_bufftable(buff_table);
  make_bigstring(file, buff_table, namefile, name_huff);
  return (0);
}
