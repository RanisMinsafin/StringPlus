#include "s21_sscanf.h"

void *s21_to_upper(const char *str) {
  char *tmp = s21_NULL;
  if (str) {
    s21_size_t length = s21_strlen(str);
    tmp = (char *)calloc(length, sizeof(char) + 1);
    if (tmp) {
      for (s21_size_t i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          tmp[i] = str[i] - ('a' - 'A');
        } else {
          tmp[i] = str[i];
        }
      }
    }
  }
  return tmp;
}

void *s21_to_lower(const char *str) {
  char *tmp = s21_NULL;
  if (str) {
    s21_size_t length = s21_strlen(str);
    tmp = (char *)calloc(length, sizeof(char) + 1);
    if (tmp) {
      for (s21_size_t i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          tmp[i] = str[i] + ('a' - 'A');
        } else {
          tmp[i] = str[i];
        }
      }
    }
  }
  return tmp;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *tmp = s21_NULL;
  if (str && s21_strlen(src) >= start_index) {
    s21_size_t length = s21_strlen(str) + s21_strlen(src);
    tmp = (char *)calloc(length + 2, sizeof(char));
    if (tmp != s21_NULL) {
      s21_size_t j = 0;
      for (s21_size_t i = 0; i < length; i++) {
        if (i == start_index) {
          for (s21_size_t k = 0; k < s21_strlen(str); k++) {
            tmp[j] = str[k];
            j++;
          }
        }
        tmp[j] = src[i];
        j++;
      }
    }
  }
  return tmp;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *tmp = s21_NULL;
  if (src) {
    s21_size_t srcLength = s21_strlen(src);
    s21_size_t trimLength = s21_strlen(trim_chars);
    for (s21_size_t i = 0; src && i != trimLength;) {
      if ((*src) == trim_chars[i]) {
        src++;
        srcLength--;
        i = 0;
        continue;
      }
      i++;
    }
    if (srcLength) {
      s21_size_t j = srcLength - 1;
      for (s21_size_t i = 0; src && i != trimLength;) {
        if (src[j] == trim_chars[i]) {
          j--;
          srcLength--;
          i = 0;
          continue;
        }
        i++;
      }
    }
    tmp = (char *)calloc((srcLength + 1), sizeof(char));
    if (tmp) {
      for (s21_size_t i = 0; i < srcLength + 1; i++) {
        if (i < srcLength) {
          tmp[i] = src[i];
        } else {
          tmp[i] = '\0';
        }
      }
    }
  } else {
    tmp = s21_trim(src, " \t\n");
  }
  return tmp;
}
