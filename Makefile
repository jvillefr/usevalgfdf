NAME		= fdf

LIBFT		= ft
LIBFTDIR	= libft
MAKELIBFT	= @$(MAKE) -C $(LIBFTDIR)

FRAM 		= framework
MLX			= mlx
SRC			= src
INC			= include
OBJ			= obj
CFILES		= main.c entry.c data.c get_next_line.c file_one.c map.c
HFILES		= fdf.h
OFILES		= $(CFILES:.c=.o)
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(addprefix $(OBJ)/, $(OFILES))
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -Imlx  -g
RM			= rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(MLX) -I$(INC) -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(MAKELIBFT)
			$(CC) $(OBJS) -L$(MLX) -l$(MLX) -$(FRAM) OpenGL -$(FRAM) Appkit -L$(LIBFTDIR) -l$(LIBFT) -o $(NAME)	
$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

clean:
			$(MAKELIBFT) fclean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKELIBFT)
			norminette $(SRCS) $(HEADERS)

.PHONY:		all clean fclean re norme visual