# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 09:35:29 by nfordoxc          #+#    #+#              #
#    Updated: 2025/02/20 13:06:25 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

################################################################################
#	Makefile variables														   #
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g
CC_OPT			=	

DEB				=	valgrind
DEB_OPT			=	--tool=memcheck \
					--leak-check=full \
					--show-leak-kinds=all \
					--track-fds=yes

ARG0			=	./test/file_in_1 \
					"cat" \
					"tr 'a-zA-Z0-9' 'd-za-cD-ZA-C!%*\#&§?:+'" \
					./test/file_out_1

ARG1			=	/dev/urandom \
					"cat" \
					"head -1" \
					out

ARG2			=	./test/file_in_2 \
					"cat" \
					"tr 'd-za-cD-ZA-C!%*\#&§?:+' 'a-zA-Z0-9'" \
					./test/file_out_2
					
ARG3			=	"here_doc" \
					"FIN" \
					"cat" \
					"./test/file_out" \
					< ./test/here_doc

RM				=	rm -f

################################################################################
#	Librairies																   #
################################################################################

LIB_LIBFT_DIR	=	./libft
LIB_PRINTF_DIR	=	./ft_printf
LIB_GNL_DIR		=	./gnl

LIBFT_NAME		=	-lft
FTPRINTF_NAME	=	-lft_printf
LIB_GNL_NAME	=	-lgnl

LIB_PROG		=
LIB_OPTI		=
LIB_OPTI		=
LIB_NAME		=

MYLIBS			=	-L$(LIB_LIBFT_DIR) $(LIBFT_NAME)

MYLIBS_BONUS	=	-L$(LIB_LIBFT_DIR) $(LIBFT_NAME)\
					-L$(LIB_GNL_DIR) $(LIB_GNL_NAME)

################################################################################
#	Mandatory part															   #
################################################################################

SRC				=	./src/main.c \
					./src/ft_check_arg.c \
					./src/ft_exec_process.c \
					./src/ft_free_info.c \
					./src/ft_get_access.c \
					./src/ft_get_info.c \
					./src/ft_init_info.c \
					./src/ft_run_pipex.c

OBJ				=	$(SRC:.c=.o)

NAME			=	pipex

################################################################################
#	Bonus part																   #
################################################################################

SRC_BONUS		=	./bonus/main_bonus.c \
					./bonus/ft_check_arg_bonus.c \
					./bonus/ft_exec_process_bonus.c \
					./bonus/ft_free_info_bonus.c \
					./bonus/ft_get_access_bonus.c \
					./bonus/ft_get_info_bonus.c \
					./bonus/ft_init_info_bonus.c \
					./bonus/ft_run_here_doc.c \
					./bonus/ft_run_pipex_bonus.c

OBJ_BONUS		=	$(SRC_BONUS:.c=.o)

NAME_BONUS		=	pipex

################################################################################
#	Tester part
################################################################################

SRC_TESTER		=	
BONUS_TESTER	=	

OBJ_TESTER		=	$(SRC_TESTER:.c=.o)
OBJ_BONUS_TESTER=	$(BONUS_TESTER:.c=.o)

TESTER			=	
TESTER_BONUS	=	

################################################################################
#	Colors																	   #
################################################################################

RESET			=	'\033[0m'

# Regular

BLACK			=	'\033[0;30m'
RED				=	'\033[0;31m'
GREEN			=	'\033[0;92m'
YELLOW			=	'\033[0;93m'
BLUE			=	'\033[0;94m'
PURPLE			=	'\033[0;95m'
CYAN			=	'\033[0;96m'
WHITE			=	'\033[0;97m'

# Bold

BBLACK			=	'\033[1;30m'
BRED			=	'\033[1;31m'
BGREEN			=	'\033[1;92m'
BYELLOW			=	'\033[1;93m'
BBLUE			=	'\033[1;94m'
BPURPLE			=	'\033[1;95m'
BCYAN			=	'\033[1;96m'
BWHITE			=	'\033[1;97m'

################################################################################
#	Progress bar															   #
################################################################################

CURRENT_FILE	= 	0
NB_SRC			=	$(words $(SRC))
NB_BONUS		=	$(words $(SRC_BONUS))
NB_TESTER		=	$(words $(SRC_TESTER))
NB_TESTER_BONUS	=	$(words $(BONUS_TESTER))
SLEEP_TIME		=	0.001

################################################################################
#	Functions
################################################################################

define compile_c_to_o
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(BLUE)"\r\033[K\033[0KCompiling files => $< ["
	@for i in $$(seq 0 $$(($(CURRENT_FILE)*100/$(NUM_FILES)))); do \
		printf $(YELLOW)"="; \
	done
	@printf $(BBLUE)"] $(CURRENT_FILE)/$(NUM_FILES)$(RESET)"
	@if [ $(CURRENT_FILE) -eq $(NUM_FILES) ]; then \
		echo ; \
	fi
	@$(eval CURRENT_FILE=$(if \
		$(filter $(CURRENT_FILE), $(NUM_FILES)), 0, $(CURRENT_FILE)))
endef

define optimise_lib
	@printf "$(BYELLOW)Optimisation of $(LIB_NAME)$(YELLOW)\n"
	@$(LIB_OPTI) $(LIB_NAME) > /dev/null 2>&1
	@for i in $$(seq 1 50); do \
		printf "\r\033[K\033[0K["; \
		for j in $$(seq 1 $$i); do \
			printf "=="; \
		done; \
		printf " %d%% ]" $$((i * 2)); \
		sleep $(SLEEP_TIME); \
	done; \
	echo $(RESET)
endef

define delete_progress
	@$(RM) $(1) > /dev/null 2>&1
	@for i in $$(seq 100 -1 0); do \
		printf "\r\033[K\033[0K"; \
		if [ $$((i % 4)) -eq 0 ]; then \
			printf "$(BRED)DELETE - ["; \
		elif [ $$((i % 4)) -eq 1 ]; then \
			printf "$(BRED)DELETE / ["; \
		elif [ $$((i % 4)) -eq 2 ]; then \
			printf "$(BRED)DELETE | ["; \
		else \
			printf "$(BRED)DELETE \\ ["; \
		fi; \
		for j in $$(seq 0 $$i); do \
			printf '='; \
		done; \
		printf " %d/100 ]$(RESET)" $$i; \
		sleep $(SLEEP_TIME); \
	done
	@printf "\r\033[K\033[0K$(GREEN)All files $(1) of $(NAME) deleted$(RESET)\n"
endef

define delete_file
	@$(RM) $(1) > /dev/null 2>&1
	@printf "\r\033[K\033[0K$(GREEN)$(1) deleted$(RESET)\n"
endef

################################################################################
#	Rules																	   #
################################################################################

.PHONY : all $(NAME) bonus deb clean fclean re

all: 		$(LIB_LIBFT_DIR)/libft.a \
			$(NAME)

$(NAME):	NUM_FILES=$(NB_SRC)
$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MYLIBS) -o $(NAME)

$(LIB_LIBFT_DIR)/libft.a:
	@$(MAKE) -sC $(LIB_LIBFT_DIR) bonus

$(LIB_GNL_DIR)/libgnl.a:
	@$(MAKE) -sC $(LIB_GNL_DIR)

%.o :		%.c
	$(call compile_c_to_o)

bonus:		NUM_FILES=$(NB_BONUS)
bonus:		$(LIB_LIBFT_DIR)/libft.a \
			$(LIB_GNL_DIR)/libgnl.a \
			$(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MYLIBS_BONUS) -o $(NAME_BONUS)

deb:		$(NAME)/libft.a \
			bonus

ifeq ($(arg),ARG0)
	@$(CC) $(CFLAGS) $(CC_OPT) $(OBJ) $(MYLIBS) -g -o $(NAME)
	@echo "\n$(RESET)==========	RUN DEBUG MODE	=========="
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG0)
else ifeq ($(arg),ARG1)
	@$(CC) $(CFLAGS) $(CC_OPT) $(OBJ) $(MYLIBS) -g -o $(NAME)
	@echo "\n$(RESET)==========	RUN DEBUG MODE	=========="
	$(DEB) $(DEB_OPT) ./$(NAME) $(ARG1)
else ifeq ($(arg),ARG2)
	@$(CC) $(CFLAGS) $(CC_OPT) $(OBJ_BONUS) $(MYLIBS_BONUS) -g -o $(NAME_BONUS)
	@echo "\n$(RESET)==========	RUN DEBUG MODE	=========="
	$(DEB) $(DEB_OPT) ./$(NAME_BONUS) $(ARG2)
else ifeq ($(arg),ARG3)
	@$(CC) $(CFLAGS) $(CC_OPT) $(OBJ_BONUS) $(MYLIBS_BONUS) -g -o $(NAME_BONUS)
	@echo "\n$(RESET)==========	RUN DEBUG MODE	=========="
	$(DEB) $(DEB_OPT) ./$(NAME_BONUS) $(ARG3)
else
	@echo "\n$(RESET)Usage: make deb arg=ARG0|ARG1|ARG2|ARG3"
endif

clean:
	$(call delete_progress, src/*.o)
	$(call delete_progress, bonus/*.o)
	@$(MAKE) -sC $(LIB_LIBFT_DIR) clean
	@$(MAKE) -sC $(LIB_GNL_DIR) clean

fclean: 	clean
	$(call delete_file, $(NAME))
	$(call delete_file, $(NAME_BONUS))
	@$(MAKE) -sC $(LIB_LIBFT_DIR) fclean
	@$(MAKE) -sC $(LIB_GNL_DIR) fclean

re : 		fclean all
