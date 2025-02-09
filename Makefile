create:
	@read -p "Enter directory name: " dir_name; \
	mkdir -p $$dir_name \
	&& touch $$dir_name/$${dir_name}.c
	cd $$dir_name


clean:
	@read -p "Enter directory name: " dir_name; \
	rm -rf $$dir_name

