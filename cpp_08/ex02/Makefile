################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = ex02
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -Wshadow -Wno-shadow 

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

INC_DIR = ./inc/
SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), main.cpp)
TMP = ./tmp

################################################################################
#                                  COLORS                                      #
################################################################################
RED		= "\033[0;31m"
GRN		= "\033[0;32m"  
YEL		= "\033[0;33m"
BLU		= "\033[0;34m"
BLA		= "\033[0;30m"
CYA		= "\033[0;36m"
GREY	= "\033[0;90m"
BBLA	= "\033[30;1m"
BRED 	= "\033[31;1m"
BGRN	= "\033[32;1m"
BYEL	= "\033[33;1m"
BBLU	= "\033[34;1m"
BMAG	= "\033[35;1m"
BCYA	= "\033[36;1m"
BWHI	= "\033[37;1m"
RESET	= "\033[0m"

################################################################################
#                                  Makefile objs                               #
################################################################################

all: $(NAME)

OBJS = $(SRCS:$(SRCS_DIR)%.cpp=$(TMP)/%.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@clear
	@echo $(BBLU) "   ______        ____            ____ "
	@echo $(BBLU) "  /      |      |    |          |    | "
	@echo $(BBLU) " |    ___|   ___|    |___    ___|    |___ "
	@echo $(BBLU) " |   |      |            |  |            |"
	@echo $(BBLU) " |   |____  |___      ___|  |___      ___|"
	@echo $(BBLU) " |        |     |    |          |    |  "
	@echo $(BBLU) "  \_______|     |____|          |____|" $(RESET) 
	
	@echo "\n"
	@echo $(BGRN) "Compilation Successful!"$(RESET)
	@echo $(BYEL)" The program $(NAME) was created by icunha-t!" $(RESET)

$(TMP)/%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@clear
	@rm -rf $(TMP)
	@echo $(BRED)"-> .o files removed"$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@clear
	@echo $(BRED)"-> $(NAME) and .o files removed"$(RESET)

re: fclean all

.PHONY: all clean fclean re