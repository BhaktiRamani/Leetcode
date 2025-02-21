# GDB Binary Debugging Guide

This guide contains essential commands and steps for binary analysis and debugging using GDB and related tools.

## Binary Analysis Tools

### Hex Editor Analysis
Use a hex editor to examine the binary file structure:
- VIM - Built-in hex editor available in most Unix systems
- Bless - Graphical hex editor with advanced features

Example:
```bash
bless main
```

### String Extraction
Extract all strings from a binary:
```bash
strings <binary_file>
```

### Symbol Table Analysis
View the symbol table including functions, addresses, and global variables:
```bash
readelf --symbols <binary_file>
```

### Object File Analysis
Several ways to analyze object files:

1. View sections (.bss, .text, etc.):
```bash
objdump -t <binary_file>
```

2. View complete hex dump with debug information:
```bash
objdump -s <binary_file>
```

3. Disassemble the binary to view assembly code:
```bash
objdump -d <binary_file>
```
This shows assembly code for initialization, start, and all functions.

### Binary Manipulation

Remove debug information and reduce symbol table visibility:
```bash
strip <binary_file>
```
Note: This makes debugging more difficult for others by removing symbol information.

### Memory Segment Analysis
View the size of all memory segments:
```bash
size <binary_file>
```

Example output:
```
   text    data     bss     dec     hex filename
   1509     604       4    2117     845 main
```

Where:
- text: Size of the code segment
- data: Size of initialized data segment
- bss: Size of uninitialized data segment
- dec: Total size in decimal
- hex: Total size in hexadecimal

