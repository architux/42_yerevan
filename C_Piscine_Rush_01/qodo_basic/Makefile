CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = rush01

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

test: $(TARGET)
# 	@echo "=== Running 4x4 ==="
# 	@./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" || true
# 	@echo ""

# 	@echo "=== Running 5x5 ==="
# 	@./$(TARGET) "5 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2" || true
# 	@echo ""

# 	@echo "=== Running 6x6 ==="
# 	@./$(TARGET) "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2" || true
# 	@echo ""

# 	@echo "=== Running 7x7 ==="
# 	@./$(TARGET) "7 6 5 4 3 2 1 1 2 2 2 2 2 2 7 6 5 4 3 2 1 1 2 2 2 2 2 2" || true
# 	@echo ""

# 	@echo "=== Running 8x8 ==="
# 	@./$(TARGET) "8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2" || true
# 	@echo ""

# 	@echo "=== Running 9x9 ==="
# 	@./$(TARGET) "9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2" || true
# 	@echo ""

test: $(TARGET)
	@echo "=== Running 4x4 ==="
	@echo "Expected solution:"
	@echo "1 2 3 4"; echo "2 3 4 1"; echo "3 4 1 2"; echo "4 1 2 3"
	@echo "Solver output:"
	@./$(TARGET) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" || true
	@echo ""

	@echo "=== Running 5x5 ==="
	@echo "Expected solution:"
	@echo "1 2 3 4 5"; echo "2 3 4 5 1"; echo "3 4 5 1 2"; echo "4 5 1 2 3"; echo "5 1 2 3 4"
	@echo "Solver output:"
	@./$(TARGET) "5 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2" || true
	@echo ""

	@echo "=== Running 6x6 ==="
	@echo "Expected solution:"
	@echo "1 2 3 4 5 6"; echo "2 3 4 5 6 1"; echo "3 4 5 6 1 2"; echo "4 5 6 1 2 3"; echo "5 6 1 2 3 4"; echo "6 1 2 3 4 5"
	@echo "Solver output:"
	@./$(TARGET) "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2" || true
	@echo ""

	@echo "=== Running 7x7 ==="
	@echo "Expected solution:"
	@echo "1 2 3 4 5 6 7"; echo "2 3 4 5 6 7 1"; echo "3 4 5 6 7 1 2"; echo "4 5 6 7 1 2 3"; echo "5 6 7 1 2 3 4"; echo "6 7 1 2 3 4 5"; echo "7 1 2 3 4 5 6"
	@echo "Solver output:"
	@./$(TARGET) "7 6 5 4 3 2 1 1 2 2 2 2 2 2 7 6 5 4 3 2 1 1 2 2 2 2 2 2" || true
	@echo ""

	@echo "=== Running 8x8 ==="
	@echo "Expected solution:"
	@echo "1 2 3 4 5 6 7 8"; echo "2 3 4 5 6 7 8 1"; echo "3 4 5 6 7 8 1 2"; echo "4 5 6 7 8 1 2 3"; echo "5 6 7 8 1 2 3 4"; echo "6 7 8 1 2 3 4 5"; echo "7 8 1 2 3 4 5 6"; echo "8 1 2 3 4 5 6 7"
	@echo "Solver output:"
	@./$(TARGET) "8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2" || true
	@echo ""

	@echo "=== Running 9x9 ==="
	@echo "Expected solution:"
	@echo "1 2 3 4 5 6 7 8 9"; echo "2 3 4 5 6 7 8 9 1"; echo "3 4 5 6 7 8 9 1 2"; echo "4 5 6 7 8 9 1 2 3"; echo "5 6 7 8 9 1 2 3 4"; echo "6 7 8 9 1 2 3 4 5"; echo "7 8 9 1 2 3 4 5 6"; echo "8 9 1 2 3 4 5 6 7"; echo "9 1 2 3 4 5 6 7 8"
	@echo "Solver output:"
	@./$(TARGET) "9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2" || true
	@echo ""
