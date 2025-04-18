# **************************************************************************** #
#                                    PROGRAM                                   #
# **************************************************************************** #

NAME		:=	philo_bonus

# **************************************************************************** #
#                                     UTILS                                    #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-O0 -Wall -Wextra -Werror
DEP_FLAGS	:=	-MMD -MP
RM			:=	rm -rf

# **************************************************************************** #
#                                  DIRECTORIES                                 #
# **************************************************************************** #

SRCS_DIR 	:=	srcs
INCLD_DIR 	:=	includes
OBJS_DIR 	:=	objs

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #

NEW			:=	\r\033[K
DEFAULT		:=	\033[0m
BLACK		:=	\033[0;30m
WHITE		:=	\033[0;37m
RED			:=	\033[0;31m
NEON_RED	:=	\033[38;5;196m
GREEN		:=	\033[0;32m
U_GREEN		:=	\033[4;32m
NEON_GREEN	:=	\033[38;5;82m
YELLOW		:=	\033[0;33m
BLUE		:=	\033[0;34m
PURPLE		:=	\033[0;35m
CYAN		:=	\033[0;36m
BOLD		:=	\033[1m
ITALIC		:=	\033[3m

# **************************************************************************** #
#                                    SOURCES                                   #
# **************************************************************************** #

INC			:=	includes
INCLUDES	:=	$(strip $(INC))
INCLD_FLAG	:=	$(addprefix -I , $(INCLUDES))

# SOURCES #
SRC			=	data/data.c\
				data/semaphore.c\
				main.c\
				parsing.c\
				error_msg.c\
				str_utils.c\
				time.c\
				watcher.c\
				processus_gestion.c\
				philo_processus/philo_init.c\
				philo_processus/philo_routine.c\
				philo_processus/watchdog.c\
				philo_processus/alone.c\
				philo_processus/philo_eat.c\
				philo_processus/philo_sleep.c\
				philo_processus/philo_think.c\
				philo_processus/philo_delay.c\
				format/format.c\
				format/format2.c\
				format/gen_msg.c\





OBJS 		:=	$(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
DEPS		:=	$(patsubst %.c,$(OBJS_DIR)/%.d,$(SRC))

# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "$(NEW) [🧠 $(NAME) 🍝] $(U_GREEN)Building:$(DEFAULT) $<"
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) -lm
	@printf "\r\033[K[🧠 $(NAME) 🍝] \033[0;32mDone!\033[0m\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@clear
	@printf "$(NEW) [🧠 $(NAME) 🍝] $(U_GREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(dir $@)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

# **************************************************************************** #
#                                       TEST                                   #
# **************************************************************************** #

test: 
	@cp -f test/checker_linux .
	@cp -f test/test.sh .
	@bash test.sh

# **************************************************************************** #
#                                    CLEANING                                  #
# **************************************************************************** #

clean:
	@printf "[🧠 $(NAME) 🍝] $(RED)Cleaning .o$(DEFAULT)\n"
	@$(RM) $(OBJS_DIR) 
	@printf "[🧠 $(NAME) 🍝] $(RED)Cleaned objects!$(DEFAULT)\n"

fclean: clean
	@printf "[🧠 $(NAME) 🍝] \033[0;31mDeleting philo_bonus executables\033[0m\n"
	@$(RM) $(NAME)
	@printf "[🧠 $(NAME) 🍝] \033[1;32mDone\033[0m\n\n"

re: fclean all

.PHONY: all clean fclean re bonus test