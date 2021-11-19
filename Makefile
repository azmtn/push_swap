CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

NAME_PS = push_swap
NAME_CH = checker

SRC_DIR  = ./src/
INC_DIR  = ./inc/
OBJ_DIR  = ./obj/
FT_DIR   = ./libft/
GNL_DIR  = ./gnl/

FUNC = 		cmd_1 \
			cmd_2 \
			cmd_3 \
			place_search \
			basic_sort \
			init \
			q_sort \
			separation \
			small_sort \
			validation \
			initial_sort \
			dup_cut \
			sort4

SRC = $(patsubst %,%.c,$(FUNC))

GNL_SRC = 	get_next_line.c get_next_line_utils.c

PS_SRC = push_swap.c
PS_OBJ = $(addprefix $(OBJ_DIR),$(PS_SRC:.c=.o))

CH_SRC = checker.c
CH_OBJ = $(addprefix $(OBJ_DIR),$(CH_SRC:.c=.o)) $(addprefix $(GNL_DIR),$(GNL_SRC:.c=.o))

OBJ	= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
LIBFT = $(FT_DIR)libft.a

.PHONY: all bonus clean fclean re

all: $(NAME_PS)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(FT_DIR)/inc/ -o $@ -c $<

$(LIBFT):
	make -C $(FT_DIR) bonus

$(NAME_PS): obj $(LIBFT) $(OBJ) $(PS_OBJ)
	$(CC) $(OBJ) $(PS_OBJ) $(LIBFT) -o $(NAME_PS)

$(NAME_CH): obj $(LIBFT) $(OBJ) $(CH_OBJ)
	$(CC) $(OBJ) $(CH_OBJ) $(GNL_OBJ) $(LIBFT) -o $(NAME_CH)

bonus: $(NAME_CH)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(GNL_DIR)*.o
	@make -C $(FT_DIR) clean

fclean: clean
	@rm -f $(NAME_PS) $(NAME_CH)
	@make -C $(FT_DIR) fclean

re: fclean all
