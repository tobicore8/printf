*This project has been created as part of the 42 curriculum by tkern.*

---

## Description

**Libft** is a custom C library built from scratch as part of the 42 curriculum. The goal of this project is to deepen the understanding of how standard C library functions work by reimplementing them — and to build additional utility functions that will serve as a personal toolkit for all future 42 projects.

The library covers three main areas:

- **Part 1 – Libc functions:** Reimplementations of standard C library functions (e.g. `ft_strlen`, `ft_memcpy`, `ft_atoi`), strictly following their original `man` page behavior.
- **Part 2 – Additional functions:** Utility functions not found in the standard libc, or reimplemented in a different form (e.g. `ft_substr`, `ft_split`, `ft_itoa`).
- **Part 3 – Linked list functions:** A set of functions for creating and manipulating singly linked lists using the `t_list` structure.

---

## Instructions

### Compilation

Clone the repository and compile the library with:

```bash
make
```

This produces the static library file `libft.a` at the root of the repository.

### Available Makefile rules

| Rule | Effect |
|------|--------|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `all` |

### Using the library in your project

Include the header and link against the library at compile time:

```bash
paco 
```

---

## Library Description

### Part 1 – Libc functions

Reimplementations of standard C library functions. They behave identically to their originals as described in the man pages. For the character classification functions, the return value is `1` if the character matches and `0` if it does not.

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic |
| `ft_isdigit` | Checks if a character is a digit |
| `ft_isalnum` | Checks if a character is alphanumeric |
| `ft_isascii` | Checks if a character is a valid ASCII value |
| `ft_isprint` | Checks if a character is printable |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Sets a block of memory to zero |
| `ft_memcpy` | Copies memory from source to destination |
| `ft_memmove` | Copies memory safely even with overlapping regions |
| `ft_strlcpy` | Copies a string with size-bounded truncation |
| `ft_strlcat` | Appends a string with size-bounded truncation |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares up to `n` characters of two strings |
| `ft_memchr` | Searches for a byte in a block of memory |
| `ft_memcmp` | Compares two blocks of memory |
| `ft_strnstr` | Finds a substring within a limited-length string |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates zero-initialized memory |
| `ft_strdup` | Duplicates a string with `malloc` |

---

### Part 2 – Additional functions

Functions that extend the standard library with commonly needed utilities.

| Function | Prototype | Description |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Returns a substring of `s` starting at `start` with max length `len` |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Concatenates two strings into a new string |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Trims characters from `set` at the beginning and end of `s1` |
| `ft_split` | `char **ft_split(char const *s, char c);` | Splits a string by a delimiter and returns a NULL-terminated array |
| `ft_itoa` | `char *ft_itoa(int n);` | Converts an integer to a string |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies function `f` to each character and returns the resulting string |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Applies function `f` to each character of `s` in place |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Writes a character to a file descriptor |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Writes a string to a file descriptor |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Writes an integer to a file descriptor |

---

### Part 3 – Linked list functions

Functions for creating and manipulating singly linked lists using the following structure, defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Prototype | Description |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Creates a new list node with the given content |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds a node at the beginning of the list |
| `ft_lstsize` | `int ft_lstsize(t_list *lst);` | Returns the number of nodes in the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds a node at the end of the list |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees a single node's content and the node itself |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Frees all nodes in the list and sets the pointer to NULL |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Applies function `f` to the content of each node |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Creates a new list by applying `f` to each node's content; frees with `del` on failure |

---

## Resources

### References

- [C Standard Library Reference – cppreference.com](https://en.cppreference.com/w/c)
- [Linux man pages](https://man7.org/linux/man-pages/)
- [42 Norm (available on the 42 intranet)](https://elearning.42.fr/)
- [Understanding linked lists – GeeksForGeeks](https://www.geeksforgeeks.org/linked-list-data-structure/)

### AI Usage

AI (Claude by Anthropic) was used in the following limited ways during this project:

- **Debugging:** Identifying logical errors in function implementations (e.g. uninitialized pointers, wrong condition checks). The understanding and fix were always verified and applied manually.
- **README structure:** Assistance with formatting and structuring this README file according to the subject requirements.

AI was not used to write or generate function implementations directly. All code was written, understood, and tested by the author.
