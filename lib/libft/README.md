# Libft Functions

## Functions from `<ctype.h>`

- **[`ft_isalpha`](ft_isalpha.c):** Checks for an alphabetic character.
- **[`ft_isdigit`](ft_isdigit.c):** Checks for a digit (0 through 9).
- **[`ft_isalnum`](ft_isalnum.c):** Checks for an alphanumeric character.
- **[`ft_isascii`](ft_isascii.c):** Checks whether `c` fits into the ASCII character set.
- **[`ft_isprint`](ft_isprint.c):** Checks for any printable character.
- **[`ft_toupper`](ft_toupper.c):** Converts a character to uppercase.
- **[`ft_tolower`](ft_tolower.c):** Converts a character to lowercase.

## Functions from `<string.h>`

- **[`ft_memset`](ft_memset.c):** Fills memory with a constant byte.
- **[`ft_strlen`](ft_strlen.c):** Calculates the length of a string.
- **[`ft_bzero`](ft_bzero.c):** Zeroes a byte string.
- **[`ft_memcpy`](ft_memcpy.c):** Copies a memory area.
- **[`ft_memmove`](ft_memmove.c):** Copies a memory area.
- **[`ft_strlcpy`](ft_strlcpy.c):** Copies a string to a specific size.
- **[`ft_strlcat`](ft_strlcat.c):** Concatenates a string to a specific size.
- **[`ft_strchr`](ft_strchr.c):** Locates a character in a string.
- **[`ft_strrchr`](ft_strrchr.c):** Locates a character in a string.
- **[`ft_strncmp`](ft_strncmp.c):** Compares two strings.
- **[`ft_memchr`](ft_memchr.c):** Scans memory for a character.
- **[`ft_memcmp`](ft_memcmp.c):** Compares memory areas.
- **[`ft_strnstr`](ft_strnstr.c):** Locates a substring in a string.
- **[`ft_strdup`](ft_strdup.c):** Creates a duplicate for the string passed as a parameter.

## Functions from `<stdlib.h>`

- **[`ft_atoi`](ft_atoi.c):** Converts a string to an integer.
- **[`ft_calloc`](ft_calloc.c):** Allocates memory and sets its bytes' values to 0.

## Non-standard functions

- **[`ft_substr`](ft_substr.c):** Returns a substring from a string.
- **[`ft_strjoin`](ft_strjoin.c):** Concatenates two strings.
- **[`ft_strtrim`](ft_strtrim.c):** Trims the beginning and end of a string with a specific set of characters.
- **[`ft_split`](ft_split.c):** Splits a string using a character as a parameter.
- **[`ft_itoa`](ft_itoa.c):** Converts a number into a string.
- **[`ft_strmapi`](ft_strmapi.c):** Applies a function to each character of a string.
- **[`ft_striteri`](ft_striteri.c):** Applies a function to each character of a string.
- **[`ft_putchar_fd`](ft_putchar_fd.c):** Outputs a character to a file descriptor.
- **[`ft_putstr_fd`](ft_putstr_fd.c):** Outputs a string to a file descriptor.
- **[`ft_putendl_fd`](ft_putendl_fd.c):** Outputs a string to a file descriptor, followed by a new line.
- **[`ft_putnbr_fd`](ft_putnbr_fd.c):** Outputs a number to a file descriptor.

## Linked list functions

- **[`ft_lstnew`](ft_lstnew.c):** Creates a new list element.
- **[`ft_lstadd_front`](ft_lstadd_front.c):** Adds an element at the beginning of a list.
- **[`ft_lstsize`](ft_lstsize.c):** Counts the number of elements in a list.
- **[`ft_lstlast`](ft_lstlast.c):** Returns the last element of the list.
- **[`ft_lstadd_back`](ft_lstadd_back.c):** Adds an element at the end of a list.
- **[`ft_lstclear`](ft_lstclear.c):** Deletes and frees a list.
- **[`ft_lstiter`](ft_lstiter.c):** Applies a function to each element of a list.
- **[`ft_lstmap`](ft_lstmap.c):** Applies a function to each element of a list.
