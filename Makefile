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
#    Created/Updated: 2021/06/04 21:38:09  /  2021/06/04 21:38:14 @cclarice    #
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
SRC_SORT   = p2b_sort.c sw1_sort.c sw2_sort.c sort_utils.c
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
SAY  = echo -e
RM   = rm -rf
CC   = clang

# Compile Rule
all: $(OBJF) $(NAME)

$(OBJF):
	@if [ ! -a "${OBJF}" ]; then $(MKDR) $(OBJF); $(MKDR) $(OBJFS) ;\
	$(SAY) "Created \033[33m$(OBJF) $(OBJFS)\033[0m"; fi

obj/%.o: src/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(SAY) "Compilng \033[33m$< \033[0mto \033[36m$@\033[0m"

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@$(SAY) "Compilng \033[35m$(NAME)\033[0m"
	@$(SAY) "Makefile \033[32mDone!\033[0m"

# Clean and recompile rules
clean:
	@if [ -a "${OBJF}" ]; then $(RM) $(OBJF); \
	$(SAY) "Removing \033[31m$(OBJF)\033[0m"; fi

fclean: clean
	@if [ -a "${NAME}" ]; then $(RM) $(NAME); \
	$(SAY) "Removing \033[31m$(NAME)\033[0m"; fi

re: fclean all
