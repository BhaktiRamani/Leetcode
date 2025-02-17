# This folder contains basic gdb / binary debugging steps :

1 - To checkout the binary, we can use hex editor
Options : VIM, Bless
Example : Bless main

2 - .strings (bin_file_name) 
lists out all the strinbgs in given binary file

3 - readelf --symbols (bin_file_name)
gives symbol table - gives functions, address, global variable, start

4 - objdump -t bin_file_name
gives dump with sections .bss .txt 

5 - objdump -s bin_file_name
gives actual hex dump, debug info

6 - objdump -d bin_file_name
gives assembly, of init , start and every func

7 - strip bin_file_name
remove debug info, cut it somehow, cut down symbol table as well so that other cant 
debug