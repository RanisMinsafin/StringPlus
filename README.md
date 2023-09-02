# string+

An extended implementation of the string.h library in C with additional features, including sprintf, sscanf, and special string processing functions.

## Table of Contents

1. [Introduction](#introduction)
2. [Information](#information)
    - [string.h Types](#stringh-types)
    - [string.h Macro](#stringh-macro)
    - [string.h Functions](#stringh-functions)
    - [sprintf and sscanf](#sprintf-and-sscanf)
    - [sprintf And sscanf Specifiers](#sprintf-and-sscanf-specifiers)
    - [sprintf Flags](#sprintf-flags)
    - [sprintf And sscanf Width Description](#sprintf-and-sscanf-width-description)
    - [sprintf Precision Description](#sprintf-precision-description)
    - [sprintf And sscanf Length Description](#sprintf-and-sscanf-length-description)
    - [Special string processing functions (from the String class in C#)](#special-string-processing-functions-from-the-string-class-in-c)
3. [Part 1: Implementation of the string.h library functions](#part-1-implementation-of-the-stringh-library-functions)
4. [Part 2: Partial implementation of the sprintf function](#part-2-partial-implementation-of-the-sprintf-function)
5. [Part 3: Bonus - Implementation of some format modifiers of the sprintf function](#part-3-bonus-implementation-of-some-format-modifiers-of-the-sprintf-function)
6. [Part 4: Bonus - Implementation of the sscanf function](#part-4-bonus-implementation-of-the-sscanf-function)
7. [Part 5: Bonus - Implementation of special string processing functions](#part-5-bonus-implementation-of-special-string-processing-functions)

## Introduction

In this project, an extended implementation of the string.h library is provided in C, featuring additional functionality, including sprintf, sscanf, and special string processing functions. This project enhances the standard string handling capabilities and consolidates structured programming principles.

## Information

The C programming language offers a range of functions for string manipulation in its standard library. These functions enable various operations like copying, concatenation, tokenization, and searching. The standard library treats strings as null-terminated, and it represents a string of 'n' characters as an array of 'n + 1' elements, with the last one being the "NULL" character. The language itself only converts quoted string constants into null-terminated strings.

### string.h Types

| No. | Variable | Description |
| --- | --- | --- |
| 1 | size_t | This is an unsigned integral type, typically the result of the `sizeof` keyword.

### string.h Macro

| No. | Macro | Description |
| --- | --- | --- |
| 1 | NULL | This macro represents the value of a null pointer constant.

### string.h Functions

| No. | Function | Description |
| --- | --- | --- |
| 1 | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character `c` (an unsigned char) in the first `n` bytes of the string pointed to by `str`. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first `n` bytes of `str1` and `str2`. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Copies `n` characters from `src` to `dest`. |
| 4 | void *memmove(void *dest, const void *src, size_t n) | Similar to `memcpy`, but handles overlapping memory regions. |
| 5 | void *memset(void *str, int c, size_t n) | Copies the character `c` (an unsigned char) to the first `n` characters of the string pointed to by `str`. |
| 6 | char *strcat(char *dest, const char *src) | Appends the string pointed to by `src` to the end of the string pointed to by `dest`. |
| 7 | char *strncat(char *dest, const char *src, size_t n) | Appends the first `n` characters of the string pointed to by `src` to the end of the string pointed to by `dest`. |
| 8 | char *strchr(const char *str, int c) | Searches for the first occurrence of the character `c` (an unsigned char) in the string pointed to by `str`. |
| 9 | int strcmp(const char *str1, const char *str2) | Compares the string pointed to by `str1` to the string pointed to by `str2`. |
| 10 | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first `n` bytes of `str1` and `str2`. |
| 11 | char *strcpy(char *dest, const char *src) | Copies the string pointed to by `src` to `dest`. |
| 12 | char *strncpy(char *dest, const char *src, size_t n) | Copies up to `n` characters from the string pointed to by `src` to `dest`. |
| 13 | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of `str1` consisting entirely of characters not in `str2`. |
| 14 | char *strerror(int errnum) | Searches an internal array for the error number `errnum` and returns a pointer to an error message string. |
| 15 | size_t strlen(const char *str) | Computes the length of the string `str` up to but not including the terminating null character. |
| 16 | char *strpbrk(const char *str1, const char *str2) | Finds the first character in `str1` that matches any character specified in `str2`. |
| 17 | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character `c` (an unsigned char) in the string pointed to by `str`. |
| 18 | size_t strspn(const char *str1, const char *str2) | Calculates the length of the initial segment of `str1` consisting entirely of characters in `str2`. |
| 19 | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string `needle` (excluding the terminating null character) within the string `haystack`. |
| 20 | char *strtok(char *str, const char *delim) | Breaks the string `str` into a series of tokens separated by `delim`. |

### sprintf and sscanf

- `int sscanf(const char *str, const char *format, ...)` reads formatted input from a string.
- `int sprintf(char *str, const char *format, ...)` sends formatted output to a string pointed to by `str`.

### sprintf And sscanf Specifiers

| No. | Specifier | sprintf Output | sscanf Output |
| --- | --- | --- | --- |
| 1 | c | Character | Character |
| 2 | d | Signed decimal integer | Signed decimal integer |
| 3 | i | Signed decimal integer | Signed integer (may be decimal, octal, or hexadecimal) |
| 4 | e | Scientific notation (mantissa/exponent) using 'e' character (the output of the numbers must match up to e-6) | Decimal floating point or scientific notation (mantissa/exponent) |
| 5 | E | Scientific notation (mantissa/exponent) using 'E' character | Decimal floating point or scientific notation (mantissa/exponent) |
| 6 | f | Decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 7 | g | Uses the shortest representation of decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 8 | G | Uses the shortest representation of decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 9 | o | Unsigned octal | Unsigned octal |
| 10 | s | String of characters | String of characters |
| 11 | u | Unsigned decimal integer | Unsigned decimal integer |
| 12 | x | Unsigned hexadecimal integer | Unsigned hexadecimal integer (any letters) |
| 13 | X | Unsigned hexadecimal integer (capital letters) | Unsigned hexadecimal integer (any letters) |
| 14 | p | Pointer address | Pointer address |
| 15 | n | Number of characters printed until %n occurs | Number of characters scanned until %n occurs |
| 16 | % | Character % | Character % |

### sprintf Flags

| No. | Flags | Description |
| --- | --- | --- |
| 1 | - | Left-justify within the given field width; right justification is the default (see width sub-specifier). |
| 2 | + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| 3 | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4 | # | Used with o, x, or X specifiers, the value is preceded with 0, 0x, or 0X, respectively, for values different than zero. Used with e, E, and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G, the result is the same as with e or E, but trailing zeros are not removed. |
| 5 | 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |

### sprintf And sscanf Width Description

| No. | Width | Description |
| --- | --- | --- |
| 1 | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| 2 | * | In sprintf, the * sign means that the width is not specified in the format string but as an additional integer value argument preceding the argument that has to be formatted. In sscanf, the * sign placed after % and before the format specifier reads data of the specified type but suppresses their assignment. |

### sprintf Precision Description

| No. | .precision | Description |
| --- | --- | --- |
| 1 | .number | For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E, and f specifiers − this is the number of digits to be printed after the decimal point. For g and G specifiers − this is the maximum number of significant digits to be printed. For s − this is the maximum number of characters to be printed. By default, all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified for specifiers e, E, f, g, and G, the default one is 6. When no precision is specified for all other kinds of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| 2 | .* | The precision is not specified in the format string but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf And sscanf Length Description

| No. | Length | Description |
| --- | --- | --- |
| 1 | h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x, and X). |
| 2 | l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x, and X) and as a wide character or wide character string for specifiers c and s. |
| 3 | L | The argument is interpreted as a long double (only applies to floating point specifiers − e, E, f, g, and G). |

### Special string processing functions (from the String class in C#)

| No. | Function | Description |
| --- | --- | --- |
| 1 | void *to_upper(const char *str) | Returns a copy of the string (`str`) converted to uppercase. In case of any error, return NULL. |
| 2 | void *to_lower(const char *str) | Returns a copy of the string (`str`) converted to lowercase. In case of any error, return NULL. |
| 3 | void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (`str`) is inserted at a specified index position (`start_index`) in the given string (`src`). In case of any error, return NULL. |
| 4 | void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (`trim_chars`) from the given string (`src`) are removed. In case of any error, return NULL. |

## Part 1. Implementation of the string.h library functions

The project includes the implementation of standard string.h library functions. Key details include:

- The library is developed in C language of C11 standard using the GCC compiler.
- The library's code, including headers, makefile, and the library itself, is located in the src folder on the develop branch.
- Legacy and obsolete language constructions and library functions are avoided, following the POSIX.1-2017 standard.
- The code follows the Google style guidelines.
- The library is built as a static library with the header file string.h.
- Structured programming principles are followed to minimize code duplication.
- Comprehensive unit tests using the Check library cover at least 80% of each function.
- A Makefile is provided for building the library and tests, including targets like all, clean, test, string.a, and gcov_report.
- The gcov_report target generates a gcov report in the form of an HTML page.

## Part 2. Partial implementation of the sprintf function

This part of the project involves the implementation of the sprintf function from the stdio.h library, with support for specifiers, flags, width, precision, and length description.

## Part 3. Bonus. Implementation of some format modifiers of the sprintf function

This bonus assignment enhances the sprintf function by adding support for additional format modifiers, including specifiers, flags, width, precision, and length description.

## Part 4. Bonus. Implementation of the sscanf function

This bonus assignment involves implementing the sscanf function from the stdio.h library, with full formatting support, including flags, widths, precision, modifiers, and conversion types.

## Part 5. Bonus. Implementation of special string processing functions

This bonus assignment adds special string processing functions inspired by the String class in C#. These functions are integrated into the string.h library and follow the same coding standards and testing requirements.