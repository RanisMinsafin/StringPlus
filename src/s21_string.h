#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

// calculation functions
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
// copy functions
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
// comparison functions
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
// supporting functions
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);
void int_in_string(int n, char s[]);
void reverse(char s[]);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
// search functions
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *s, int c);
char *s21_strstr(const char *haystack, const char *needle);
// additional functions
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
// s21_sscanf
int s21_sscanf(const char *buf, const char *format, ...);
// s21_sprintf
int s21_sprintf(char *buf, const char *str, ...);