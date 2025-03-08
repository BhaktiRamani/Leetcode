TARGET?=$(basename $(firstword $(MAKECMDGOALS)))
# Source and object files
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: clean build

build:$(TARGET).cpp	
	@g++ $(TARGET).cpp -g -o $(TARGET)
	@./$(TARGET)

git-all:
	git add .
	git commit -m "$(msg)"
	git push origin master

.PHONY : clean

clean:
	rm -f $(OBJ) $(wildcard $(TARGET))


