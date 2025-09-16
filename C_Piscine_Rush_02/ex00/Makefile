# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 15:17:13 by mvasilev          #+#    #+#              #
#    Updated: 2025/09/14 23:40:54 by mvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

TARGET = rush-02

RED_COLOR = \033[31m
BRIGHT_RED_COLOR = \033[1;31m
YELLOW_COLOR = \033[33m
GREEN_COLOR = \033[32m
BRIGHT_GREEN_COLOR = \033[1;32m
RESET_COLOR = \033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c ft_convert.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

docs:
	doxygen Doxyfile
	@echo "Docs have been generated in docs/html/index.html"

test: $(TARGET)
	@printf "${BRIGHT_RED_COLOR}EXIT_CODE__ARGS_ERROR${RESET_COLOR}\n"
	@echo "implemented exit code: 1"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET)${RESET_COLOR}\n"
	@printf "${RED_COLOR}" ; ./$(TARGET) ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) -42${RESET_COLOR}\n"
	@printf "${RED_COLOR}" ; ./$(TARGET) -42; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 10.4${RESET_COLOR}\n"
	@printf "${RED_COLOR}" ; ./$(TARGET) 10.4; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 10a4b${RESET_COLOR}\n"
	@printf "${RED_COLOR}" ; ./$(TARGET) 10a4b; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""




	@printf "${BRIGHT_RED_COLOR}EXIT_CODE__MAPPING_ERROR${RESET_COLOR}\n"
	@echo "implemented exit code: 2"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 451 1984${RESET_COLOR}\n"
	@printf "${RED_COLOR}" ; ./$(TARGET) 451 1984; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) wrong.dict 1984${RESET_COLOR}\n"
	@printf "${RED_COLOR}" ; ./$(TARGET) wrong.dict 1984; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""




	@printf "${BRIGHT_GREEN_COLOR}EXIT_CODE__SUCCESS${RESET_COLOR}\n"
	@echo "implemented exit code: 0"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 0${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) 0; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 42${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) 42; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 1234${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) 1234; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 10000${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) 10000; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) +42042${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) +42042; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) 08300${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) 08300; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) ' 1321456987  '${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) ' 1321456987  '; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./$(TARGET) custom.dict 42${RESET_COLOR}\n"
	@printf "${GREEN_COLOR}" ; ./$(TARGET) custom.dict 42; printf "${RESET_COLOR}returned exit code: $$?\n" || true
