NAME=cub3D

MY_SOURCES= mandatory/src/core/main.c \
			mandatory/src/core/init.c \
			mandatory/src/core/game_init.c \
			mandatory/src/core/init_parameters.c \
			mandatory/src/core/raycast_vars_init.c \
			mandatory/src/game/raycaster_move.c \
			mandatory/src/game/raycaster_move_utils.c \
			mandatory/src/game/display.c \
			mandatory/src/game/display_utils.c \
			mandatory/src/game/paint_screen.c \
			mandatory/src/parsing/parse_file.c \
			mandatory/src/parsing/checker.c \
			mandatory/src/parsing/map_check.c \
			mandatory/src/parsing/map_check_utils.c \
			mandatory/src/utils/ft_atoi.c \
			mandatory/src/utils/ft_calloc.c \
			mandatory/src/utils/ft_putstr_fd.c \
			mandatory/src/utils/ft_split.c \
			mandatory/src/utils/ft_strlen.c \
			mandatory/src/utils/ft_strcspn.c \
			mandatory/src/utils/ft_strjoin.c \
			mandatory/src/utils/getter.c \
			mandatory/src/utils/parsing_utils.c \
			mandatory/src/utils/parsing_map_utils.c \
			mandatory/src/utils/free.c \
			mandatory/src/error/args_error.c \
			mandatory/src/error/fd_error.c \
			mandatory/src/error/texture_error.c \
			mandatory/src/error/verify_string.c

MY_SOURCES_BONUS = bonus/src/core/main_bonus.c \
			bonus/src/core/init_bonus.c \
			bonus/src/core/game_init_bonus.c \
			bonus/src/core/init_parameters_bonus.c \
			bonus/src/core/raycast_vars_init_bonus.c \
			bonus/src/game/raycaster_move_bonus.c \
			bonus/src/game/raycaster_move_utils_bonus.c \
			bonus/src/game/raycaster_move_more_utils_bonus.c \
			bonus/src/game/mini_map_bonus.c \
			bonus/src/game/mini_map_utils_bonus.c \
			bonus/src/game/weapon_bonus.c \
			bonus/src/game/display_bonus.c \
			bonus/src/game/display_utils_bonus.c \
			bonus/src/game/paint_screen_bonus.c \
			bonus/src/parsing/parse_file_bonus.c \
			bonus/src/parsing/checker_bonus.c \
			bonus/src/parsing/map_check_bonus.c \
			bonus/src/parsing/map_check_utils_bonus.c \
			bonus/src/utils/ft_atoi_bonus.c \
			bonus/src/utils/ft_calloc_bonus.c \
			bonus/src/utils/ft_putstr_fd_bonus.c \
			bonus/src/utils/ft_split_bonus.c \
			bonus/src/utils/ft_strlen_bonus.c \
			bonus/src/utils/ft_strcspn_bonus.c \
			bonus/src/utils/ft_strjoin_bonus.c \
			bonus/src/utils/getter_bonus.c \
			bonus/src/utils/parsing_utils_bonus.c \
			bonus/src/utils/parsing_map_utils_bonus.c \
			bonus/src/utils/free_bonus.c \
			bonus/src/error/args_error_bonus.c \
			bonus/src/error/fd_error_bonus.c \
			bonus/src/error/texture_error_bonus.c \
			bonus/src/error/verify_string_bonus.c

MY_OBJECTS=$(MY_SOURCES:.c=.o)
OBJS_BONUS=$(MY_SOURCES_BONUS:.c=.o)
VERIF_DUP            = mkdir -p verif

BONUS := verif/bonus
STD := verif/mandatory

white='\033[1;37m'

RM=rm -f

CC=clang
CFLAGS=-Wall -Wextra -Werror -I ./mandatory/MLX42/include
CBFLAGS=-Wall -Wextra -Werror -I ./bonus/MLX42/include
MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext 

all: $(STD) $(NAME)

$(STD) : $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(MLXFLAGS) ./mandatory/MLX42/build/libmlx42.a -o $(NAME)
	$(VERIF_DUP)
	rm -f $(BONUS)
	touch $(STD)
	@clear
	@if [ $$? -eq 0 ]; then \
		echo $(light_cyan)"\t   »»-————　Make - Mandatory　————-««\n"; \
	fi

bonus: $(BONUS)

$(BONUS) : $(OBJS_BONUS)
	$(CC) $(CBFLAGS) $(OBJS_BONUS) $(MLXFLAGS) ./bonus/MLX42/build/libmlx42.a -o $(NAME)
	$(VERIF_DUP)
	rm -f $(STD)
	touch $(BONUS)
	@clear
	@if [ $$? -eq 0 ]; then \
		echo $(light_cyan)"\t   »»-————　Make - Bonus　————-««\n"; \
	fi
mlx:
	@cd mandatory && git clone https://github.com/codam-coding-college/MLX42.git
	@cd mandatory/MLX42 && cmake -B build
	@cd mandatory/MLX42 && cmake --build build -j4
	@clear
	@echo $(light_green)"\t  »»-————　MLX COMPILED - MANDATORY　————-««\n"

mlx_bonus:
	@cd bonus && git clone https://github.com/codam-coding-college/MLX42.git
	@cd bonus/MLX42 && cmake -B build
	@cd bonus/MLX42 && cmake --build build -j4
	@clear
	@echo $(light_green)"\t  »»-————　MLX COMPILED - BONUS　————-««\n"

clean: 
	@echo $(light_green)"\t  »»-————　Clean　————-««\n"
	@$(RM) $(MY_OBJECTS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME) $(STD) $(BONUS)
	@rm -rf verif
	@echo $(white)"\t»»-————　Full clean　————-««\n"

clean_mlx:
	@cd bonus && rm -rf MLX42 && cd ../mandatory && rm -rf MLX42

re: fclean all
	@echo $(green_c)"\t\t »»-————　Done　————-««\n"

.PHONY: all clean fclean header bonus mlx mlx_bonus re
