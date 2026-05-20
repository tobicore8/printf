This project has been created as part of the 42 curriculum by tkern.

# ft_printf

## Description

`ft_printf` is a partial reimplementation of the C standard library function `printf`. The goal is to understand how variadic functions work in C, how a format string is parsed character by character, and how different data types are converted into their string representations before being written to standard output.

The function handles a format string containing plain text and conversion specifiers (e.g. `%d`, `%s`). For each specifier, the corresponding argument is retrieved from the variable argument list using `va_arg`, converted to a string, and written to stdout using `write()`. The function returns the total number of characters written.

Supported specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.

## Algorithm and Data Structure

The core of `ft_printf` is a loop that iterates over the format string character by character:
- If the current character is not `%`, it is written directly to stdout.
- If the current character is `%`, the next character is passed to `ft_handle_format`, which dispatches to the correct conversion logic.

For integer-to-string conversion, a general base conversion function `ft_htoa` is used. It takes a number and a base string (e.g. `"0123456789abcdef"` for hexadecimal) and converts the number by repeatedly taking `n % base_length` to extract digits from right to left, then filling a malloc'd string from right to left. This single function handles `%u`, `%x`, `%X`, and `%p`, avoiding code duplication. For signed integers (`%d`, `%i`), the existing `ft_itoa` from libft is reused.

Pointer addresses (`%p`) are cast to `uintptr_t` before conversion — an unsigned integer type guaranteed to be large enough to hold a memory address on both 32-bit and 64-bit systems.

## Instructions

**Compile the library:**
```bash
make
```
This produces `libftprintf.a`.

**Link it in your project:**
```bash
cc main.c libftprintf.a -o my_program
```

**Include the header:**
```c
#include "ft_printf.h"
```

**Clean:**
```bash
make clean    # removes object files
make fclean   # removes object files and library
make re       # full rebuild
```

## Usage Example

```c
ft_printf("Hello, %s!\n", "world");
ft_printf("Dec: %d | Hex: %x | Ptr: %p\n", 255, 255, &some_var);
ft_printf("Unsigned: %u\n", 4294967295u);
```

## Resources

- `man 3 printf` — official documentation for the printf family
- `man 3 stdarg` — documentation for variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- `man 2 write` — documentation for the write syscall
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)

**AI usage:** Claude was used throughout this project as a learning tool. It helped clarify concepts such as variadic functions, file descriptors, base conversion algorithms, header guards, and the 42 Norm. Claude was used to explain *why* things work, answer questions during implementation, and review code for bugs — not to generate the code directly.