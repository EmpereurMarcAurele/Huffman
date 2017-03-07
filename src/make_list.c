#include	"huff.h"

t_file		*set_file(void)
{
  t_file	*new;

  if ((new = malloc(sizeof(t_file))) == NULL)
    {
      printf("fail malloc on t_file\n");
      exit(EXIT_FAILURE);
    }
  new->length = 0;
  new->tmp_oct = 0x0;
  return (new);
}

t_list		*make_list(void)
{
  t_list	*newlist;
  
  if ((newlist = malloc(sizeof(t_list))) == NULL)
    {
      printf("fail malloc on t_list\n");
      exit(EXIT_FAILURE);
    }
  newlist->start = NULL;
  newlist->end = NULL;
  newlist->length = 0;
  newlist->length_table = '\0';
  return (newlist);
}
