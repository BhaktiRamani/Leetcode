all:build

build:main.c
	@gcc main.c -o main
	@./main

git-all:
	git add .
	git commit -m "$(m)"
	git push origin master


clean:
	rm -f *.o

