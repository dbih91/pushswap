# **************************************************************************** #
#                                                                              #
#        ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::   #
#      :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+:  #
#     +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+   #
#    +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:    #
#   +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+            #
#  #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#      #
#   ######    ######  ############## ###    ### ###   ######    #######        #
#                                                                              #
# **************************************************************************** #
#                                                                              #
#    Makefile                                 cclarice@student.21-school.ru    #
#                                                                              #
#    Created/Updated: 2021/06/23 22:11:54  /  2021/06/23 22:11:55 @cclarice    #
#                                                                              #
# **************************************************************************** #

# HEAD & NAME
NAME = push_swap
HEAD = src/pushswap.h

# TEST
TEST = test_xtox.c
TSTN = test_xtox

# SRCS
SRCF = src
SRC_RULES  = push.c reverse.c rotate.c swap.c
SRC_SORT   = sw1_sort.c whl_sort.c whl_sort_uu.c whl_sort_u.c sort_utils.c
SRC_UTILS  = ft_atoi.c ft_putint.c ft_strlen.c convert.c
SRC_VISUAL = put_digit.c visual.c visual_utils.c
SRC  = $(addprefix rules/, $(SRC_RULES)) \
       $(addprefix sort/, $(SRC_SORT)) \
       $(addprefix utils/, $(SRC_UTILS)) \
       $(addprefix visual/, $(SRC_VISUAL)) \
       main.c
SRCS = $(addprefix $(SRCF)/, $(SRC))

# OBJS
OBJF = obj
OBJFS = $(addprefix $(OBJF)/, rules sort utils visual)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

# COMPILE
FLAG = -Wall -Wextra -Werror -O3
MKDR = mkdir -p
SAY  = printf
RM   = rm -rf
CC   = clang

# Compile Rule
all: $(OBJF) $(NAME)

$(OBJF):
	@if [ ! -a "${OBJF}" ]; then $(MKDR) $(OBJF); $(MKDR) $(OBJFS) ;\
	$(SAY) "Created \033[33m$(OBJF) $(OBJFS)\033[0m\n"; fi

obj/%.o: src/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(SAY) "Compiling \033[36m%s\033[0m\n" "$<" "$@"

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@$(SAY) "Compiling \033[35m$(NAME)\033[0m\n"
	@$(SAY) "Makefile \033[32mDone!\033[0m\n"

# Clean and recompile rules
clean:
	@if [ -a "${OBJF}" ]; then $(RM) $(OBJF); \
	$(SAY) "Removing \033[31m$(OBJF)\033[0m\n"; fi

fclean: clean
	@if [ -a "${NAME}" ]; then $(RM) $(NAME); \
	$(SAY) "Removing \033[31m$(NAME)\033[0m\n"; fi

re: fclean all
