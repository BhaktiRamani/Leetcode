TARGET=$(basename $(firstword $(MAKECMDGOALS)))

# Source and object files for C and C++
SRC_C = $(wildcard *.c)
SRC_CPP = $(wildcard *.cpp)
OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)
OBJ = $(OBJ_C) $(OBJ_CPP)

# Detect file extension for compilation
EXT := $(shell if [ -f $(TARGET).cpp ]; then echo "cpp"; else echo "c"; fi)

all: clean build

create:
	@if [ ! -f $(TARGET).c ] && [ ! -f $(TARGET).cpp ]; then \
		echo "// This is a placeholder $(EXT) file for $(TARGET)" > $(TARGET).$(EXT); \
		echo "int main() { return 0; }" >> $(TARGET).$(EXT); \
		echo "$(TARGET).$(EXT) created."; \
	fi

build: $(TARGET).$(EXT)
	@if [ "$(EXT)" = "cpp" ]; then \
		g++ $(TARGET).cpp -g -o $(TARGET); \
	else \
		gcc $(TARGET).c -g -o $(TARGET); \
	fi
	@./$(TARGET)

git-all:
	git add .
	git commit -m "$(m)"
	git push origin master

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)
