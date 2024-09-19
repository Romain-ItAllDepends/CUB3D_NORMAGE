NAME=cub3d

MY_SOURCES= src/core/main.c \
			src/core/init.c \
			src/core/game_init.c \
			src/core/init_parameters.c \
			src/core/raycast_vars_init.c \
			src/game/raycaster_move.c \
			src/game/raycaster_move_utils.c \
			src/game/display.c \
			src/parsing/parse_file.c \
			src/parsing/checker.c \
			src/parsing/map_check.c \
			src/utils/ft_atoi.c \
			src/utils/ft_calloc.c \
			src/utils/ft_putstr_fd.c \
			src/utils/ft_split.c \
			src/utils/ft_strlen.c \
			src/utils/ft_strcspn.c \
			src/utils/ft_strjoin.c \
			src/utils/getter.c \
			src/utils/parsing_utils.c \
			src/utils/parsing_map_utils.c \
			src/utils/free.c \
			src/error/args_error.c \
			src/error/fd_error.c \
			src/error/texture_error.c \
			src/error/verify_string.c

MY_OBJECTS=$(MY_SOURCES:.c=.o)

white='\033[1;37m'

RM=rm -f

CC=clang
CFLAGS=-Wall -Wextra -Werror -I./MLX42/include -g
MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext 

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(MLXFLAGS) ./MLX42/build/libmlx42.a -o $@
	@clear
	@if [ $$? -eq 0 ]; then \
		echo $(light_cyan)"\t   »»-————　Make　————-««\n"; \
	fi

mlx:
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4
	@clear
	@echo $(light_green)"\t  »»-————　MLX COMPILED　————-««\n"

clean: 
	@echo $(light_green)"\t  »»-————　Clean　————-««\n"
	@$(RM) $(MY_OBJECTS)

fclean: clean
	@$(RM) $(NAME)
	@echo $(white)"\t»»-————　Full clean　————-««\n"

re: fclean all
	@echo $(green_c)"\t   »»-————　Done　————-««"

.PHONY: all clean fclean header re
