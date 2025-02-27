TARGET=$(basename $(firstword $(MAKECMDGOALS)))
# Source and object files
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: clean build

create: 
	@if [ ! -f $(TARGET).c ]; then \
		echo "// This is a placeholder C file for $(TARGET)" > $(TARGET).c; \
		echo "int main() { return 0; }" >> $(TARGET).c; \
		echo "$(TARGET).c created."; \
	fi

build:$(TARGET).cpp
	@g++ $(TARGET).cpp -g -o $(TARGET)
	@./$(TARGET)

git-all:
	git add .
	git commit -m "$(m)"
	git push origin master

.PHONY : clean

clean:
	rm -f $(OBJ) $(TARGET)


