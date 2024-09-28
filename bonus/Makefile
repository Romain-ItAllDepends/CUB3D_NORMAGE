NAME=cub3d

MY_SOURCES= src/core/main_bonus.c \
			src/core/init_bonus.c \
			src/core/game_init_bonus.c \
			src/core/init_parameters_bonus.c \
			src/core/raycast_vars_init_bonus.c \
			src/game/raycaster_move_bonus.c \
			src/game/raycaster_move_utils_bonus.c \
			src/game/mini_map_bonus.c \
			src/game/weapon_bonus.c \
			src/game/display_bonus.c \
			src/game/display_utils_bonus.c \
			src/game/paint_screen_bonus.c \
			src/parsing/parse_file_bonus.c \
			src/parsing/checker_bonus.c \
			src/parsing/map_check_bonus.c \
			src/parsing/map_check_utils_bonus.c \
			src/utils/ft_atoi_bonus.c \
			src/utils/ft_calloc_bonus.c \
			src/utils/ft_putstr_fd_bonus.c \
			src/utils/ft_split_bonus.c \
			src/utils/ft_strlen_bonus.c \
			src/utils/ft_strcspn_bonus.c \
			src/utils/ft_strjoin_bonus.c \
			src/utils/getter_bonus.c \
			src/utils/parsing_utils_bonus.c \
			src/utils/parsing_map_utils_bonus.c \
			src/utils/free_bonus.c \
			src/error/args_error_bonus.c \
			src/error/fd_error_bonus.c \
			src/error/texture_error_bonus.c \
			src/error/verify_string_bonus.c

MY_OBJECTS=$(MY_SOURCES:.c=.o)

white='\033[1;37m'

RM=rm -f

CC=clang
CFLAGS=-Wall -Wextra -Werror -I./MLX42/include
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
