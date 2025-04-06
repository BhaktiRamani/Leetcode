# 2. File Modes
# File modes specify the operations that can be performed on the file. Common modes are:

# Mode	Description
# 'r'	Read (default). Opens a file for reading.
# 'w'	Write. Opens a file for writing (creates new file or truncates an existing file).
# 'a'	Append. Opens a file for writing (creates new file if not existing, appends to the end).
# 'x'	Exclusive creation. Fails if the file already exists.
# 'b'	Binary mode. Reads/writes in binary format.
# 't'	Text mode (default). Reads/writes in text format.
# 'r+'	Read and write. Opens the file for both reading and writing.
# 'w+'	Write and read. Opens the file for both writing and reading.


#with open("File name", "mode") as file_name_for_usage

with open("example.txt", "a") as file:
    file.write(" Hello World")
    file.write(" Hello World second line")
    
with open("example.txt", "r") as file:
    print(file.read())
  

    
