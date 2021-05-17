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
#    Created/Updated: 2021/05/16 15:03:41  /  2021/05/17 23:49:20 @cclarice    #
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
SRC  = main.c ft_strlen.c ft_atoi.c ft_putint.c game_rules.c
SRCS = $(addprefix $(SRCF)/, $(SRC))

# OBJS
OBJF = obj
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

# COMPILE
FLAG = -Wall -Wextra -Werror -O3
MKDR = mkdir -p
SAY  = echo -e
RM   = rm -rf
CC   = clang

# Compile Rule
all: $(OBJF) $(NAME) done

$(OBJF):
	@$(MKDR) $(OBJF)

obj/%.o: src/%.c $(OBJF) $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(SAY) "Compilng \033[33m$< \033[0mto \033[36m$@\033[0m"

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@$(SAY) "Compilng \033[35m$(NAME)\033[0m"

done:
	@$(SAY) "Makefile \033[32mDone!\033[0m"

# Clean and recompile rules
clean:
	@$(RM) $(OBJF)
	@$(SAY) "Removing \033[31m$(OBJF)\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(SAY) "Removing \033[31m$(NAME)\033[0m"

re: fclean all
