## 🔧 **GDB Binary Debugging Guide**

This guide contains essential commands and steps for binary analysis and debugging using GDB and related tools.

---

## 🧩 **Binary Analysis Tools**

### 📝 **Hex Editor Analysis**
Use a hex editor to examine the binary file structure:

- **VIM** – Built-in hex editor available in most Unix systems.
- **Bless** – Graphical hex editor with advanced features.

**Example:**
```bash
bless main
```

---

### 🔡 **String Extraction**
Extract all strings from a binary:
```bash
strings <binary_file>
```

---

### 🏷️ **Symbol Table Analysis**
View the symbol table, including functions, addresses, and global variables:
```bash
readelf --symbols <binary_file>
```

---

### 🛠️ **Object File Analysis**

1. **View sections** (.bss, .text, etc.):
   ```bash
   objdump -t <binary_file>
   ```

2. **View complete hex dump with debug information:**
   ```bash
   objdump -s <binary_file>
   ```

3. **Disassemble the binary to view assembly code:**
   ```bash
   objdump -d <binary_file>
   ```
   This shows assembly code for initialization, start, and all functions.

---

### 🧹 **Binary Manipulation**

Remove debug information and reduce symbol table visibility:
```bash
strip <binary_file>
```
> ⚡ *Note: This makes debugging more difficult for others by removing symbol information.*

---

### 🧮 **Memory Segment Analysis**
View the size of all memory segments:
```bash
size <binary_file>
```

**Example output:**
```plaintext
   text    data     bss     dec     hex filename
   1509     604       4    2117     845 main
```

Where:
- `text`: Size of the code segment
- `data`: Size of initialized data segment
- `bss`: Size of uninitialized data segment
- `dec`: Total size in decimal
- `hex`: Total size in hexadecimal

---

## 🐞 **GDB Commands Guide**

### 🚀 **Compiling and Running with GDB**

To enable debugging with GDB, compile your code with the `-g` flag:
```bash
gcc -g file_name.c -o file_name
gdb ./file_name
```

---

### 🎛️ **GDB User Interface (UI) Mode**
GDB provides a built-in text-based UI that makes debugging more visual by splitting the screen into different sections (source code, assembly, registers, etc.).

- **Enable the GDB UI:**
  ```bash
  layout next
  ```
  This will display the next available layout. Repeatedly using `layout next` cycles through available layouts like source, assembly, and register views.

- **Switch between layouts:**
  ```bash
  # Simply press ENTER after running 'layout next' to cycle through the views.
  ```

---

### 🎯 **Breakpoints**
Breakpoints allow you to pause execution at a specific point in the code.

- **Set a breakpoint:**
  ```bash
  break x    # 'x' can be 'main', a function name, or a specific line number
  ```

- **Clear a breakpoint:**
  ```bash
  clear x
  ```

- **List all breakpoints:**
  ```bash
  info b
  ```

---

### 🏃 **Running and Stepping Through Code**

- **Run the program until the first breakpoint:**
  ```bash
  run   # or simply 'r'
  ```

- **Single-step execution (step over function calls):**
  ```bash
  next  # or 'n'
  ```

- **Single-step into functions:**
  ```bash
  step  # or 's'
  ```

---

### 👀 **Watching Variables**
Watchpoints track changes to variable values during execution.

- **Set a watchpoint on a variable:**
  ```bash
  watch variable_name
  ```

> ⚡ **Important:** Ensure a breakpoint is set in the function where the variable is defined so that it’s in scope when the watchpoint is set.

Whenever the variable's value changes, GDB will display the **old** and **new** values.

---

### ⏩ **Continuing Execution**
- **Continue running until the next breakpoint or watchpoint:**
  ```bash
  continue  # or 'c'
  ```

---

### 🔄 **Backtrace (Stack Trace)**
The `bt` command shows the call stack at any point during execution. This is particularly useful for debugging segmentation faults or understanding how a program reached a specific function.

- **View the call stack:**
  ```bash
  bt
  ```

**Example output:**
```plaintext
#0  my_func () at main.c:5
#1  main () at main.c:12
```
This output shows that `main()` called `my_func()`. The top frame (`#0`) is where the program currently is.

---

### 📦 **Inspecting Memory**
The `x` command allows you to examine memory at a specified address.

- **Syntax:**
  ```bash
  x/[N][format][size] address
  ```

- **Example:**
  ```bash
  x/128xb address
  ```
  This command displays **128 bytes** of memory at the given address in **hexadecimal format** (`b` for byte, `x` for hexadecimal).

💡 **Formats:**
- `x` – Hexadecimal  
- `d` – Decimal  
- `s` – String  
- `i` – Instruction  

**Example with a pointer:**
```bash
print &variable
x/16xb 0xaddress  # Replace '0xaddress' with the printed address
```
This will show the memory content around the variable, which can help in diagnosing memory corruption or pointer-related issues.

---

### 🐛 **Debugging Segmentation Faults**
You can use `print` to inspect variables and identify segmentation faults.

**Example:**
```c
char *ptr = addr;
addr = NULL;
```

In GDB:
```bash
print ptr   # This will show 'ptr' as NULL, indicating a potential segfault source
```

---



