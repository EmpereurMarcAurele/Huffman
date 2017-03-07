
#ifndef		HUFF_H_
#define		HUFF_H_

#include	<stdlib.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>

typedef	struct	s_elem	t_elem;
struct		s_elem
{
  t_elem	*dad;
  t_elem	*gauche;
  t_elem	*droite;
  t_elem	*next;
  t_elem	*prev;
  int		occu;
  char		deep;
  char		sym;
  char		bit;
  char		length_bit;
};

typedef	struct	s_list	t_list;
struct		s_list
{
  t_elem	*start;
  t_elem	*end;
  int		length;
  char		length_table;

};

typedef	struct	s_file	t_file;
struct		s_file
{
  int		fd;
  int		newfile;
  int		length;/*nb_symbole (taille table)*/
  signed char	tmp_oct;
};


typedef	struct	s_index t_index;
struct	s_index
{
  t_index	*prev;
  t_index	*next;
  char		sym;
  char		len_bitcode;
  char		*bitcode;
};

typedef	struct	s_table	t_table;
struct		s_table
{
  t_index	*start;
  t_index	*end;
  char		nb_sym;
  int		length;
};

/* PROTOSS */
int	main(int, char **);
int	my_compress(char *);
void	error_arg(int, char **);
void	make_symbole(t_file *, t_list *);

t_list	*make_list(void);
t_file	*set_file(void);
t_elem	*make_elem(void);
void	showlist(t_list *);
void	add_elem(char, t_list *);
int	add_occu(char, t_list *);
int	exist_oct(char, t_list *);
int	my_compare(char, char);

/**/
t_list	*make_tree(t_list *);
t_list	*add_node(t_list *);
t_list	*remove_elem(t_list *);
t_list	*insert_newnode(t_elem *, t_list *);
t_list	*insert_end(t_elem *, t_list *);

/**/
t_elem	*fill_bit(t_elem *, t_file *, char);
int	resolve_nb_oct(int);
int	depile_node(t_elem *, t_file *);
t_elem	*write_oct(t_elem *, t_file *);

/*stockage et reverse */
void	stock_tab(t_file *, t_table *, char *);
t_index	*set_index(void);
void	add_index(t_table *);
t_table	*make_table(void);
void	reverse_bitcode(t_table *);
char	*reverse_str(char *);

void	make_bigstring(t_file *, t_table *, char *, char *);
char	*sreach_occu(char, t_table *, char *);
void	write_big(t_file *, char *);

char	*brok_oct(char *, char);
void	make_big_dec(t_file *, t_table *, char *, char *);
int	my_decompress(char *);

int	my_strlen(char *);
/* DEBUG_AFF.C */
void	my_putstr(char *);
void	my_showtab(t_file *);
void	my_show_list(t_list *);
#endif	/* !HUFF_H_ */
