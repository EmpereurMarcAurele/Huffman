#include	"huff.h"

t_list		*insert_end(t_elem *newelem, t_list *table)
{
  t_elem	*tmp;

  tmp = table->end;
  newelem->prev = tmp;
  newelem->next = NULL;
  tmp->next = newelem;
  table->end = newelem;
  table->length++;
  return (table);
}

t_list		*insert_newnode(t_elem *newelem, t_list *table)
{
  t_elem	*tmp;
  int		i;

  i = 1;
  tmp = table->start;
  while (newelem->occu >= tmp->occu && i <= table->length)
    {
      if (i == table->length)
	{
	  insert_end(newelem, table);
	  return (table);
	}
      tmp = tmp->next;
      i++;
    }
  newelem->prev = tmp->prev;
  newelem->next = tmp;
  tmp->prev->next = newelem;
  tmp->prev = newelem;
  table->length++;
  return (table);
}

t_list		*remove_elem(t_list *table)
{
  t_elem	*tmp;
  int		i;

  tmp = table->start;
  i = 0;
  while (i < 2)
    {
      tmp = tmp->next;
      i++;
    }
  table->start = tmp;
  table->length = table->length - 2;
  tmp->prev = NULL;
  return (table);
}

t_list		*add_node(t_list *table)
{
  t_elem	*newelem;
  t_elem	*current;

  if (table->length < 2)
    {
      table->length = 0;
      return(table);
    }
  newelem = make_elem();
  current = table->start;
  newelem->gauche = current;
  newelem->droite = current->next;
  current->dad = newelem;
  current->next->dad = newelem;
  newelem->occu = current->occu + current->next->occu;
  remove_elem(table);
  insert_newnode(newelem, table);
  return (table);
}

t_list		*make_tree(t_list *table)
{
  t_elem	*endelem;
  t_elem	*tmp;
  int		i;

  i = 0;
  endelem = make_elem();
  //showlist(table);
  table->length_table = table->length;
  while (table->length > 2)
    {
      add_node(table);
      i++;
      //      showlist(table);
    }
  //printf("i = %d\n", i);
  tmp = table->start;
  endelem->gauche = tmp;
  endelem->droite = tmp->next;
  endelem->occu = tmp->occu + tmp->next->occu;
  tmp->dad = endelem;
  tmp->next->dad = endelem;
  table->start = endelem;
  table->end = endelem;
  table->length--;
  return (table);
}
