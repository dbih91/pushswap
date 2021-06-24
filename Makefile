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
#    Created/Updated: 2021/06/24 05:27:44  /  2021/06/24 05:27:44 @cclarice    #
#                                                                              #
# **************************************************************************** #

# HEAD & NAME
NAME = push_swap
BNUS = checker
HEAD = src/pushswap.h
BNHD = src_bonus/checker.h

# SRCS
SRCF = src
SRC_RULES  = push.c reverse.c rotate.c swap.c
SRC_SORT   = sw1_sort.c whl_sort.c whl_sort_uu.c whl_sort_u.c sort_utils.c
SRC_UTILS  = ft_atoi.c ft_putint.c ft_strlen.c convert.c
SRC_VISUAL = put_digit.c visual.c
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

# B_SRCS
B_SRCF = src_bonus
B_SRC_RULES  = push.c reverse.c rotate.c swap.c
B_SRC_UTILS  = ft_atoi.c ft_putint.c ft_strlen.c convert.c sort_utils.c
B_SRC  = $(addprefix rules/, $(B_SRC_RULES)) \
         $(addprefix utils/, $(B_SRC_UTILS)) \
         checker.c \
         main.c
B_SRCS = $(addprefix $(B_SRCF)/, $(B_SRC))

# B_OBJS
B_OBJF = obj_bonus
B_OBJFS = $(addprefix $(B_OBJF)/, rules utils)
B_OBJS = $(patsubst src_bonus/%.c, obj_bonus/%.o, $(B_SRCS))

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

# Compile Bonus
bonus: $(B_OBJF) $(BNUS)

$(B_OBJF):
	@if [ ! -a "${B_OBJF}" ]; then $(MKDR) $(B_OBJF); $(MKDR) $(B_OBJFS) ;\
	$(SAY) "Created \033[33m$(B_OBJF) $(B_OBJFS)\033[0m\n"; fi

obj_bonus/%.o: src_bonus/%.c $(BNHD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(SAY) "Compiling \033[36m%s\033[0m\n" "$<" "$@"

$(BNUS): $(B_OBJS)
	@$(CC) $(FLAG) $(B_OBJS) -o $(BNUS)
	@$(SAY) "Compiling \033[35m$(BNUS)\033[0m\n"
	@$(SAY) "Makefile \033[32mDone!\033[0m\n"

# Clean and recompile rules
clean:
	@if [ -a "${OBJF}" ]; then $(RM) $(OBJF); \
	$(SAY) "Removing \033[31m$(OBJF)\033[0m\n"; fi
	@if [ -a "${B_OBJF}" ]; then $(RM) $(B_OBJF); \
	$(SAY) "Removing \033[31m$(B_OBJF)\033[0m\n"; fi

fclean: clean
	@if [ -a "${NAME}" ]; then $(RM) $(NAME); \
	$(SAY) "Removing \033[31m$(NAME)\033[0m\n"; fi
	@if [ -a "${BNUS}" ]; then $(RM) $(BNUS); \
	$(SAY) "Removing \033[31m$(BNUS)\033[0m\n"; fi

norm:
	@$(SAY) "\033[33;1m"
	@norminette src
	@$(SAY) "\033[36;1m"
	@norminette src_bonus
	@$(SAY) "\033[0m"

re: fclean all
