CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c io.c logic.c parse.c parser.c solver.c checks.c
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

docs:
	doxygen Doxyfile
	@echo "Docs have been generated in docs/html/index.html"

test_exit_codes: $(TARGET)
	@printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_CLUES_STRING${RESET_COLOR}\n"
	@echo "implemented exit code: 1"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01${RESET_COLOR}\n"
	@echo "clues: -"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_CLUES_TO_PARSE${RESET_COLOR}\n"
	@echo "implemented exit code: 2"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \" \"${RESET_COLOR}\n"
	@echo "clues: 0"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) " " ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \"A B C D D C C C A B C D D C C C\"${RESET_COLOR}\n"
	@echo "clues: 0"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) "A B C D D C C C A B C D D C C C" ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__INVALID_CLUES_COUNT${RESET_COLOR}\n"
	@echo "implemented exit code: 3"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \"1 2 3 4 3\"${RESET_COLOR}\n"
	@echo "clues: 5"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) "1 2 3 4 3" ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \"4 3 2 1 1 2 2 2 4 3 2 1\"${RESET_COLOR}\n"
	@echo "clues: 12"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1" ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \"4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3\"${RESET_COLOR}\n"
	@echo "clues: 40"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) "4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3" ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_SOLUTION_FOUND${RESET_COLOR}\n"
	@echo "implemented exit code: 4"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \"1 2 2 2 4 3 2 1 4 3 2 1 1 2 2 2\"${RESET_COLOR}\n"
	@echo "clues: 16"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) "1 2 2 2 4 3 2 1 4 3 2 1 1 2 2 2" ; printf "${RESET_COLOR}returned exit code: $$?\n" || true
	@echo ""

	@printf "${BRIGHT_GREEN_COLOR}EXIT_CODE__SUCCESS${RESET_COLOR}\n"
	@echo "implemented exit code: 0"
	@echo ""

	@printf "test command: ${YELLOW_COLOR}./rush01 \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"${RESET_COLOR}\n"
	@echo "clues: 16"
	@printf "output: \n${YELLOW_COLOR}" ; ./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" ; printf "${RESET_COLOR}returned exit code: $$?\n" || true

test: test_sym_squares

test_sym_squares: $(TARGET)
	@echo "=== Running 4x4 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4"
	@echo "2 3 4 1"
	@echo "3 4 1 2"
	@echo "4 1 2 3"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 5x5 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4 5"
	@echo "2 3 4 5 1"
	@echo "3 4 5 1 2"
	@echo "4 5 1 2 3"
	@echo "5 1 2 3 4"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "5 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2" || true
	@printf "${RESET_COLOR}\n"
	@echo "=== Running 6x6 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6"
	@echo "2 3 4 5 6 1"
	@echo "3 4 5 6 1 2"
	@echo "4 5 6 1 2 3"
	@echo "5 6 1 2 3 4"
	@echo "6 1 2 3 4 5"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 7x7 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7"
	@echo "2 3 4 5 6 7 1"
	@echo "3 4 5 6 7 1 2"
	@echo "4 5 6 7 1 2 3"
	@echo "5 6 7 1 2 3 4"
	@echo "6 7 1 2 3 4 5"
	@echo "7 1 2 3 4 5 6"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "7 6 5 4 3 2 1 1 2 2 2 2 2 2 7 6 5 4 3 2 1 1 2 2 2 2 2 2" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 8x8 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7 8"
	@echo "2 3 4 5 6 7 8 1"
	@echo "3 4 5 6 7 8 1 2"
	@echo "4 5 6 7 8 1 2 3"
	@echo "5 6 7 8 1 2 3 4"
	@echo "6 7 8 1 2 3 4 5"
	@echo "7 8 1 2 3 4 5 6"
	@echo "8 1 2 3 4 5 6 7"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 9x9 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7 8 9"
	@echo "2 3 4 5 6 7 8 9 1"
	@echo "3 4 5 6 7 8 9 1 2"
	@echo "4 5 6 7 8 9 1 2 3"
	@echo "5 6 7 8 9 1 2 3 4"
	@echo "6 7 8 9 1 2 3 4 5"
	@echo "7 8 9 1 2 3 4 5 6"
	@echo "8 9 1 2 3 4 5 6 7"
	@echo "9 1 2 3 4 5 6 7 8"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 10x10 symmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "1 2 3 4 5 6 7 8 9 10"
	@echo "2 3 4 5 6 7 8 9 10 1"
	@echo "3 4 5 6 7 8 9 10 1 2"
	@echo "4 5 6 7 8 9 10 1 2 3"
	@echo "5 6 7 8 9 10 1 2 3 4"
	@echo "6 7 8 9 10 1 2 3 4 5"
	@echo "7 8 9 10 1 2 3 4 5 6"
	@echo "8 9 10 1 2 3 4 5 6 7"
	@echo "9 10 1 2 3 4 5 6 7 8"
	@echo "10 1 2 3 4 5 6 7 8 9"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "10 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 10" || true
	@printf "${RESET_COLOR}\n"

test_asym_squares: $(TARGET)
	@echo "=== Running 4x4 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "2 1 4 3"
	@echo "3 4 1 2"
	@echo "1 3 2 4"
	@echo "4 2 3 1"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "3 2 1 2 1 3 2 2 2 2 3 1 2 2 1 3" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 5x5 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "2 5 1 3 4"
	@echo "4 1 3 5 2"
	@echo "5 3 4 2 1"
	@echo "1 2 5 4 3"
	@echo "3 4 2 1 5"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "3 1 4 2 2 2 2 2 3 1 2 2 1 3 3 2 2 4 3 1" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 6x6 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "3 1 6 2 5 4"
	@echo "4 2 1 3 6 5"
	@echo "5 3 2 4 1 6"
	@echo "6 4 3 5 2 1"
	@echo "1 5 4 6 3 2"
	@echo "2 6 5 1 4 3"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "4 6 1 5 2 3 2 1 2 2 2 2 2 2 2 1 3 2 3 2 1 4 3 4" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 7x7 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "4 1 7 3 6 2 5"
	@echo "5 2 1 4 7 3 6"
	@echo "6 3 2 5 1 4 7"
	@echo "7 4 3 6 2 5 1"
	@echo "1 5 4 7 3 6 2"
	@echo "2 6 5 1 4 7 3"
	@echo "3 7 6 2 5 1 4"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "4 7 1 5 2 6 3 2 1 2 2 2 2 2 2 2 2 1 3 3 2 3 2 1 4 3 2 4" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 8x8 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "3 8 1 6 2 7 4 5"
	@echo "4 1 2 7 3 8 5 6"
	@echo "5 2 3 8 4 1 6 7"
	@echo "6 3 4 1 5 2 7 8"
	@echo "7 4 5 2 6 3 8 1"
	@echo "8 5 6 3 7 4 1 2"
	@echo "1 6 7 4 8 5 2 3"
	@echo "2 7 8 5 1 6 3 4"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "6 1 8 3 7 2 5 4 2 7 1 2 2 2 2 2 2 3 2 3 2 1 4 3 3 2 2 1 2 4 3 3" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 9x9 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "5 2 9 1 6 3 8 4 7"
	@echo "6 3 1 2 7 4 9 5 8"
	@echo "7 4 2 3 8 5 1 6 9"
	@echo "8 5 3 4 9 6 2 7 1"
	@echo "9 6 4 5 1 7 3 8 2"
	@echo "1 7 5 6 2 8 4 9 3"
	@echo "2 8 6 7 3 9 5 1 4"
	@echo "3 9 7 8 4 1 6 2 5"
	@echo "4 1 8 9 5 2 7 3 6"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "5 8 1 9 4 7 2 6 3 2 2 2 1 2 2 2 2 2 2 3 3 2 1 4 3 2 2 3 2 1 3 3 2 3 4 3" || true
	@printf "${RESET_COLOR}\n"

	@echo "=== Running 10x10 asymmetric test case ==="
	@printf "Expected output:\n${YELLOW_COLOR}"
	@echo "10  1  9  2  8  3  7  4  6  5"
	@echo " 9  2  8  3  7  4  6  5 10  1"
	@echo " 8  3  7  4  6  5 10  1  9  2"
	@echo " 7  4  6  5 10  1  9  2  8  3"
	@echo " 6  5 10  1  9  2  8  3  7  4"
	@echo " 5 10  1  9  2  8  3  7  4  6"
	@echo " 4  6  5 10  1  9  2  8  3  7"
	@echo " 3  7  4  6  5 10  1  9  2  8"
	@echo " 2  8  3  7  4  6  5 10  1  9"
	@echo " 1  9  2  8  3  7  4  6  5 10"
	@printf "${RESET_COLOR}Solver output:\n${GREEN_COLOR}"
	@./$(TARGET) "2 3 3 4 4 5 5 6 6 7 7 6 6 5 5 4 4 3 3 2 2 3 3 4 4 5 5 6 6 7 7 6 6 5 5 4 4 3 3 2" || true
	@printf "${RESET_COLOR}\n"
