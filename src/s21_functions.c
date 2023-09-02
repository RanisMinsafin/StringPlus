#include "s21_string.h"

#if defined(__APPLE__)
#define MAX_ERR 107
#define MIN_ERR -1
#define ERROR "Unknown error: "

const char *macros_error[] = {"Undefined error: 0",
                              "Operation not permitted",
                              "No such file or directory",
                              "No such process",
                              "Interrupted system call",
                              "Input/output error",
                              "Device not configured",
                              "Argument list too long",
                              "Exec format error",
                              "Bad file descriptor",
                              "No child processes",
                              "Resource deadlock avoided",
                              "Cannot allocate memory",
                              "Permission denied",
                              "Bad address",
                              "Block device required",
                              "Resource busy",
                              "File exists",
                              "Cross-device link",
                              "Operation not supported by device",
                              "Not a directory",
                              "Is a directory",
                              "Invalid argument",
                              "Too many open files in system",
                              "Too many open files",
                              "Inappropriate ioctl for device",
                              "Text file busy",
                              "File too large",
                              "No space left on device",
                              "Illegal seek",
                              "Read-only file system",
                              "Too many links",
                              "Broken pipe",
                              "Numerical argument out of domain",
                              "Result too large",
                              "Resource temporarily unavailable",
                              "Operation now in progress",
                              "Operation already in progress",
                              "Socket operation on non-socket",
                              "Destination address required",
                              "Message too long",
                              "Protocol wrong type for socket",
                              "Protocol not available",
                              "Protocol not supported",
                              "Socket type not supported",
                              "Operation not supported",
                              "Protocol family not supported",
                              "Address family not supported by protocol family",
                              "Address already in use",
                              "Can't assign requested address",
                              "Network is down",
                              "Network is unreachable",
                              "Network dropped connection on reset",
                              "Software caused connection abort",
                              "Connection reset by peer",
                              "No buffer space available",
                              "Socket is already connected",
                              "Socket is not connected",
                              "Can't send after socket shutdown",
                              "Too many references: can't splice",
                              "Operation timed out",
                              "Connection refused",
                              "Too many levels of symbolic links",
                              "File name too long",
                              "Host is down",
                              "No route to host",
                              "Directory not empty",
                              "Too many processes",
                              "Too many users",
                              "Disc quota exceeded",
                              "Stale NFS file handle",
                              "Too many levels of remote in path",
                              "RPC struct is bad",
                              "RPC version wrong",
                              "RPC prog. not avail",
                              "Program version wrong",
                              "Bad procedure for program",
                              "No locks available",
                              "Function not implemented",
                              "Inappropriate file type or format",
                              "Authentication error",
                              "Need authenticator",
                              "Device power is off",
                              "Device error",
                              "Value too large to be stored in data type",
                              "Bad executable (or shared library)",
                              "Bad CPU type in executable",
                              "Shared library version mismatch",
                              "Malformed Mach-o file",
                              "Operation canceled",
                              "Identifier removed",
                              "No message of desired type",
                              "Illegal byte sequence",
                              "Attribute not found",
                              "Bad message",
                              "EMULTIHOP (Reserved)",
                              "No message available on STREAM",
                              "ENOLINK (Reserved)",
                              "No STREAM resources",
                              "Not a STREAM",
                              "Protocol error",
                              "STREAM ioctl timeout",
                              "Operation not supported on socket",
                              "Policy not found",
                              "State not recoverable",
                              "Previous owner died",
                              "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_ERR 134
#define MIN_ERR -1
#define ERROR "Unknown error "

static const char *macros_error[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

s21_size_t s21_strlen(const char *str) {
  s21_size_t counter = 0;
  while (*str++ != '\0') {
    counter++;
  }
  return counter;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  while (*str1 && s21_strchr(str2, *str1++)) {
    length++;
  }
  return length;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  while (*str1 && !s21_strchr(str2, *str1++)) {
    length++;
  }
  return length;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *tmp_dest = (char *)dest;
  const char *tmp_src = (char *)src;
  while (n--) {
    *tmp_dest++ = *tmp_src++;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *tmp_dest = (char *)dest;
  const char *tmp_src = (char *)src;
  if (dest < src) {
    while (n--) {
      *tmp_dest++ = *tmp_src++;
    }
  } else {
    while (n--) {
      tmp_dest[n] = tmp_src[n];
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *tmp = str;
  while (n--) {
    *tmp++ = (char)c;
  }
  return str;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  char *tmp_dest = (char *)dest;
  const char *tmp_src = (char *)src;
  while (tmp_src[i] != '\0') {
    tmp_dest[i] = tmp_src[i];
    i++;
  }
  tmp_dest[i] = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *tmp_dest = dest;
  while (*src && n) {
    *dest++ = *src++;
    n--;
  }
  while (n--) {
    *dest++ = '\0';
  }
  return tmp_dest;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const char *tmp_str1 = (char *)str1;
  const char *tmp_str2 = (char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (tmp_str1[i] != tmp_str2[i]) {
      result = tmp_str1[i] - tmp_str2[i];
      n = 0;
    }
  }
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  return s21_memcmp(str1, str2,
                    s21_strlen(str1) > s21_strlen(str2) ? s21_strlen(str1)
                                                        : s21_strlen(str2));
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  const char *tmp_str1 = (char *)str1;
  const char *tmp_str2 = (char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (tmp_str1[i] != tmp_str2[i] || tmp_str1[i] == '\0') {
      result = tmp_str1[i] - tmp_str2[i];
      n = 0;
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  int flag = 1;
  static char *p = s21_NULL;
  if (delim == s21_NULL) {
    flag = 0;
  } else {
    if (str)
      p = str;
    else if (!p)
      flag = 0;
    if (flag == 1) {
      str = p + s21_strspn(p, delim);
      p = str + s21_strcspn(str, delim);
      if (p == str) {
        p = 0;
        flag = 0;
      }
      if (flag == 1) {
        p = *p ? *p = 0, p + 1 : 0;
      }
    }
  }
  if (!flag) {
    str = s21_NULL;
  }
  return str;
}

char *s21_strerror(int errnum) {
  char *output = s21_NULL;
  if (errnum >= MAX_ERR || errnum <= MIN_ERR) {
    static char output1[33] = ERROR;
    static char output2[33];
    int_in_string(errnum, output2);
    s21_strcat(output1, output2);
    output = output1;
  } else
    output = (char *)macros_error[errnum];
  return (char *)output;
}

void int_in_string(int n, char s[]) {
  s21_size_t i = 0;
  int sign = 0;
  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  s21_size_t i = 0, j = 0;
  char c = '\0';
  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = 0, j = 0;
  for (i = 0; dest[i] != '\0'; i++) {
  }
  for (j = 0; src[j] != '\0'; j++) {
    dest[i + j] = src[j];
  }
  dest[i + j] = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, j = 0;
  for (i = 0; dest[i] != '\0'; i++) {
  }
  for (j = 0; src[j] != '\0' && n != 0; j++) {
    dest[i + j] = src[j];
    n--;
  }
  dest[i + j] = '\0';
  return dest;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *tmp_str = (const char *)str;
  void *find = s21_NULL;
  unsigned char tmp;
  s21_size_t size = n;
  while (size--) {
    tmp = *(unsigned char *)tmp_str;
    if (tmp - (unsigned char)c == 0) {
      find = (void *)tmp_str;
      size = 0;
    }
    tmp_str++;
  }
  return find;
}

char *s21_strchr(const char *str, int c) {
  int i = 0;
  for (; str[i] && str[i] != c; i++)
    ;
  if (c == str[i]) {
    str = str + i;
  } else {
    str = s21_NULL;
  }
  return (char *)str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 1;
  char *find = s21_NULL;
  while (*str1 && flag != 0) {
    if (s21_strchr(str2, *str1)) {
      find = (char *)str1;
      flag = 0;
    } else {
      str1++;
    }
  }
  return find;
}

char *s21_strrchr(const char *s, int c) {
  const char *find = s21_NULL, *p = s21_NULL;
  c = (unsigned char)c;
  if (c == '\0') {
    find = s21_strchr(s, '\0');
  } else {
    while ((p = s21_strchr(s, c)) != s21_NULL) {
      find = p;
      s = p + 1;
    }
  }
  return (char *)find;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *tmp = s21_NULL;
  const char *tmpHaystackSecond = haystack;
  if (s21_strlen(needle) != 0) {
    const char *tmpNeedleFirst = needle;
    const char *tmpNeedleSecond = needle;
    const char *tmpHaystackFirst = haystack;
    while (*haystack != '\0') {
      tmpHaystackFirst = (const char *)haystack;
      if (*tmpNeedleFirst == *tmpHaystackFirst) {
        while (*tmpNeedleFirst == *tmpHaystackFirst) {
          tmpNeedleFirst++;
          tmpHaystackFirst++;
          if (*tmpNeedleFirst == '\0') {
            tmp = (char *)haystack;
            break;
          }
        }
      }
      tmpNeedleFirst = (const char *)tmpNeedleSecond;
      haystack++;
    }
  } else
    tmp = (char *)tmpHaystackSecond;
  return tmp;
}
