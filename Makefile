NAME	=	huffman

CC	=	cc

CFLAGS	=	-Wall -Wextra -I include -g

SRC_PATH=	src/

SRC	=	$(SRC_PATH)main.c		\
		$(SRC_PATH)error_arg.c		\
		$(SRC_PATH)make_list.c		\
		$(SRC_PATH)add_elem.c		\
		$(SRC_PATH)add_occu.c		\
		$(SRC_PATH)exist_oct.c		\
		$(SRC_PATH)make_elem.c		\
		$(SRC_PATH)my_compare.c		\
		$(SRC_PATH)make_symbole.c	\
		$(SRC_PATH)make_tree.c		\
		$(SRC_PATH)make_table.c		\
		$(SRC_PATH)fill_bit.c		\
		$(SRC_PATH)my_compress.c	\
		$(SRC_PATH)add_index.c		\
		$(SRC_PATH)my_strlen.c		\
		$(SRC_PATH)make_bigstring.c	\
		$(SRC_PATH)reverse_bitcode.c	\
		$(SRC_PATH)my_decompress.c	\
		$(SRC_PATH)stock_tab.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

fclean	:
	rm -f $(OBJ) $(NAME)

re:	fclean all
