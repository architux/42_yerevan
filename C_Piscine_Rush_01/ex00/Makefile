CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c init.c errors.c solver.c check.c print.c
OBJ = $(SRC:.c=.o)
TARGET = rush01

RED_COLOR = \033[31m
BRIGHT_RED_COLOR = \033[1;31m
YELLOW_COLOR = \033[33m
GREEN_COLOR = \033[32m
BRIGHT_GREEN_COLOR = \033[1;32m
RESET_COLOR = \033[0m

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

exit: $(TARGET)
	@echo -e "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_CLUES_STRING${RESET_COLOR}"
	@echo "implemented exit code: 1"
	@echo -e "test command: ${YELLOW_COLOR}./rush01${RESET_COLOR}"
	@echo "clues: -"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) ; echo -e "${RESET_COLOR}returned exit code: $$?" || true
	@echo ""

	@echo -e "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_CLUES_TO_PARSE${RESET_COLOR}"
	@echo "implemented exit code: 2"
	@echo -e "test command: ${YELLOW_COLOR}./rush01 \" \"${RESET_COLOR}"
	@echo "clues: 0"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) " " ; echo -e "${RESET_COLOR}returned exit code: $$?" || true
	@echo ""

	@echo -e "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__INVALID_CLUES_COUNT${RESET_COLOR}"
	@echo "implemented exit code: 3"
	@echo ""
	@echo -e "test command: ${YELLOW_COLOR}./rush01 \"1 2 3 4 3\"${RESET_COLOR}"
	@echo "clues: 5"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) "1 2 3 4 3" ; echo -e "${RESET_COLOR}returned exit code: $$?" || true
	@echo ""
	@echo -e "test command: ${YELLOW_COLOR}./rush01 \"4 3 2 1 1 2 2 2 4 3 2 1\"${RESET_COLOR}"
	@echo "clues: 12"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1" ; echo -e "${RESET_COLOR}returned exit code: $$?" || true
	@echo ""
	@echo -e "test command: ${YELLOW_COLOR}./rush01 \"4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3\"${RESET_COLOR}"
	@echo "clues: 40"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) "4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3" ; echo -e "${RESET_COLOR}returned exit code: $$?" || true
	@echo ""

	@echo -e "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_SOLUTION_FOUND${RESET_COLOR}"
	@echo "implemented exit code: 4"
	@echo -e "test command: ${YELLOW_COLOR}./rush01 \"1 2 2 2 4 3 2 1 4 3 2 1 1 2 2 2\"${RESET_COLOR}"
	@echo "clues: 16"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) "1 2 2 2 4 3 2 1 4 3 2 1 1 2 2 2" ; echo -e "${RESET_COLOR}returned exit code: $$?" || true
	@echo ""

	@echo -e "${BRIGHT_GREEN_COLOR}EXIT_CODE__SUCCESS${RESET_COLOR}"
	@echo "implemented exit code: 0"
	@echo -e "test command: ${YELLOW_COLOR}./rush01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"${RESET_COLOR}"
	@echo "clues: 16"
	@echo -e "output: ${YELLOW_COLOR}" ; ./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" ; echo -e "${RESET_COLOR}returned exit code: $$?" || true

test: $(TARGET)
	@echo "=== Running 4x4 ==="
	@echo -e "Expected output:${YELLOW_COLOR}"
	@echo "1 2 3 4"
	@echo "2 3 4 1"
	@echo "3 4 1 2"
	@echo "4 1 2 3"
	@echo -e "${RESET_COLOR}Solver output:${GREEN_COLOR}"
	@./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" || true
	@echo -e "${RESET_COLOR}"

	@echo "=== Running 5x5 ==="
	@echo -e "Expected output:${YELLOW_COLOR}"
	@echo "1 2 3 4 5"
	@echo "2 3 4 5 1"
	@echo "3 4 5 1 2"
	@echo "4 5 1 2 3"
	@echo "5 1 2 3 4"
	@echo -e "${RESET_COLOR}Solver output:${GREEN_COLOR}"
	@./$(TARGET) "5 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2" || true
	@echo -e "${RESET_COLOR}"

	@echo "=== Running 6x6 ==="
	@echo -e "Expected output:${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6"
	@echo "2 3 4 5 6 1"
	@echo "3 4 5 6 1 2"
	@echo "4 5 6 1 2 3"
	@echo "5 6 1 2 3 4"
	@echo "6 1 2 3 4 5"
	@echo -e "${RESET_COLOR}Solver output:${GREEN_COLOR}"
	@./$(TARGET) "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2" || true
	@echo -e "${RESET_COLOR}"

	@echo "=== Running 7x7 ==="
	@echo -e "Expected output:${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7"
	@echo "2 3 4 5 6 7 1"
	@echo "3 4 5 6 7 1 2"
	@echo "4 5 6 7 1 2 3"
	@echo "5 6 7 1 2 3 4"
	@echo "6 7 1 2 3 4 5"
	@echo "7 1 2 3 4 5 6"
	@echo -e "${RESET_COLOR}Solver output:${GREEN_COLOR}"
	@./$(TARGET) "7 6 5 4 3 2 1 1 2 2 2 2 2 2 7 6 5 4 3 2 1 1 2 2 2 2 2 2" || true
	@echo -e "${RESET_COLOR}"

	@echo "=== Running 8x8 ==="
	@echo -e "Expected output:${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7 8"
	@echo "2 3 4 5 6 7 8 1"
	@echo "3 4 5 6 7 8 1 2"
	@echo "4 5 6 7 8 1 2 3"
	@echo "5 6 7 8 1 2 3 4"
	@echo "6 7 8 1 2 3 4 5"
	@echo "7 8 1 2 3 4 5 6"
	@echo "8 1 2 3 4 5 6 7"
	@echo -e "${RESET_COLOR}Solver output:${GREEN_COLOR}"
	@./$(TARGET) "8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2" || true
	@echo -e "${RESET_COLOR}"

	@echo "=== Running 9x9 ==="
	@echo -e "Expected output:${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7 8 9"
	@echo "2 3 4 5 6 7 8 9 1"
	@echo "3 4 5 6 7 8 9 1 2"
	@echo "4 5 6 7 8 9 1 2 3"
	@echo "5 6 7 8 9 1 2 3 4"
	@echo "6 7 8 9 1 2 3 4 5"
	@echo "7 8 9 1 2 3 4 5 6"
	@echo "8 9 1 2 3 4 5 6 7"
	@echo "9 1 2 3 4 5 6 7 8"
	@echo -e "${RESET_COLOR}Solver output:${GREEN_COLOR}"
	@./$(TARGET) "9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2" || true
	@echo -e "${RESET_COLOR}"
