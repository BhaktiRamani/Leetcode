.PHONY: all clean git-all
create:
	@read -p "Enter directory name: " dir_name; \
	mkdir -p $$dir_name \
	&& touch $$dir_name/$${main}.c
	cd $$dir_name

git-all:
	git add .
	git commit -m "$(m)"
	git push origin master

clean:
	@read -p "Enter directory name: " dir_name; \
	rm -rf $$dir_name

