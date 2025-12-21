*This project has been created as part of the 42 curriculum by wtavares.*

# get_next_line

## Description

**get_next_line** is a 42 project aimed at implementing a function capable of **reading a file line by line**, from a *file descriptor (fd)*.  
The main challenge is handling partial reads and correctly managing memory, ensuring that each function call returns **exactly one line**, even when the *buffer* used is smaller than the line size.

### 🎯 Objectives
- Read from any *file descriptor* until `\n` or the end of the file is found.  
- Return each line separately, including the `\n` character when present.  
- Keep unread content in a `static` variable to be used in the next call.  
- Work correctly with any `BUFFER_SIZE` value.  

This project reinforces the use of file reading, pointers, and dynamic allocation in C, preparing for larger works that require safe memory manipulation.

---

## Instructions

### Mandatory Compilation (according to the subject)

According to the *official subject*, **mandatory compilation** must be done **only with the project files**, without including a `main.c` (https://github.com/Welsete/get_next_line).

Example:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can change the `BUFFER_SIZE` value to test different sizes:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c
```

---

### Optional Compilation (for personal testing)

If you wish to test the project locally, you can add a `main.c` (https://github.com/Welsete/get_next_line) and compile with:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Then run:
```bash
./gnl tests/test1.txt
```

This method is **optional** and serves only to facilitate personal testing.  
During the 42 evaluation, **do not use `main.c` nor generate executables** - only the mandatory files must be compiled.

---

### Makefile (optional use)

A **bonus Makefile** was included only to **facilitate automatic testing**.  
It **is not part of the mandatory evaluation**, but helps demonstrate functionality with different *buffers* and test files.

Usage example:
```bash
make b42 empty      # BUFFER_SIZE = 42, file tests/empty.txt
make b1 small       # BUFFER_SIZE = 1, file tests/small.txt
make b1000 large    # BUFFER_SIZE = 1000, file tests/large.txt
make b23921         # BUFFER_SIZE = 23921, file tests/test1.txt
```

Additional commands available:
```bash
make            # Compiles the get_next_line.a library
make test       # Compiles the test program with main.c
make run        # Compiles and runs the test automatically
make clean      # Removes object files (.o)
make fclean     # Removes objects and binaries
make re         # Runs fclean and recompiles from scratch
```

⚠️ **Important:**  
During the evaluation, the evaluator must compile **manually**, as indicated in the subject.  
The Makefile serves only as a support tool for demonstration and self-evaluation.

---

## Test Structure

Suggested test files (not mandatory by the subject):

```
tests/
├── test1.txt
├── empty.txt
├── small.txt
├── large.txt
└── no_newline.txt
```

These files allow testing:
- Empty file (`empty.txt`)  
- File with multiple lines (`test1.txt`)  
- Short lines (`small.txt`)  
- Long lines (`large.txt`)  
- File without a final newline (`no_newline.txt`)  

---

## Algorithm Explanation

The `get_next_line` logic is divided into four main parts:

1. **`read_and_stash()`** - reads from the *file descriptor* and accumulates content in the *stash* until a `\n` or the end of the file is found.  
2. **`extract_line()`** - separates the next complete line to be returned.  
3. **`create_line()`** - dynamically allocates the line and copies the correct content.  
4. **`update_stash()`** - keeps what remained after the `\n` for the next call.  

This structure ensures:
- Compatibility with any `BUFFER_SIZE`;  
- Continuous and safe reading;  
- No memory leaks;  
- Predictable and stable behavior in any scenario.

---

## Resources

### Official References
- [C Library Functions - read(), malloc(), free(), static variable] - DevDocs (https://devdocs.io/)
- [Official get_next_line Subject (42)] - Intra 42SP
- [XaveCoding - Course: Mastering Data Structures 1] - Professor Samuka (https://www.youtube.com/@xavecoding)
- [Static variable] - StackOverflow (https://pt.stackoverflow.com/questions/164808/vari%C3%A1vel-static-e-define )

---

## AI Usage

AI Tools (**ChatGPT / ScholarGPT**) were used **only for:**
- Structural review and memory flow explanation;  
- Assistance in creating test files and the auxiliary Makefile;  
- Standardization and clarity of this README.  

All code and logic were written and manually tested by **wtavares**