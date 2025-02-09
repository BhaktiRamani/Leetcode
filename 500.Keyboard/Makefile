all:build

build:main.c
	@gcc main.c -o main
	@./main

git-all:
	add
	commit
	push


add:
	git add .

commit:
	git commit -m "$COMMIT_MSG"

push:
	git push origin main

clean:
	rm -f *.o

