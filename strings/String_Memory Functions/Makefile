all: clean build

TARGET = $1
build:$$TARGET.c
	@gcc $$TARGET.c -g -o main
	@./$$TARGET

git-all:
	git add .
	git commit -m "$(m)"
	git push origin master


clean:
	rm -f *.o

