#include "s21_sscanf.h"

int s21_sscanf(const char *buf, const char *format, ...) {
  va_list A;
  specifierInfo info = {0};
  va_start(A, format);
  while (format[info.step] != '\0') {
    if (buf[info.bufStep] == ' ' && format[info.step + 1] != 'c' &&
        format[info.step + 1] != 'n') {
      info.bufStep++;
      continue;
    }
    if (format[info.step] == ' ') {
      info.step++;
      continue;
    }
    if (format[info.step] == '%') {
      info.step++;
      if (format[info.step] == ' ' || format[info.step] == '0') break;
      additions(buf, format, &info);
      integerAndChar(A, buf, format, &info);
      floatAndHexadecimal(A, buf, format, &info);
    }
  }
  va_end(A);
  return info.specifierCounter;
}

void additions(const char *buf, const char *format, specifierInfo *info) {
  if (format[info->step] == '*') {
    star(info, buf);
  }
  if (format[info->step] >= '1' && format[info->step] <= '9') {  // %numbers
    widthParser(format, info);
  }
  if (format[info->step] == 'h') {
    info->hLength = 1;
    info->step++;
  }
  if (format[info->step] == 'l') {
    if (format[info->step + 1] == 'l') info->step++;
    info->lLength = 1;
    info->step++;
  }
  if (format[info->step] == 'L') {
    info->LLength = 1;
    info->step++;
  }
}

void integerAndChar(va_list A, const char *buf, const char *format,
                    specifierInfo *info) {
  if (format[info->step] == 'c') {  // symbol
    symbolReader(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 's') {  // string
    stringReader(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'd') {  // integer and unsigned integer
    integerProcessor(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'i') {  // 8x 10x 16x integer
    iSpecifier(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'o') {  // 8x signed integer
    info->unsignedOFlag = 1;
    integerProcessor(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'u') {  // unsigned integer
    info->unsignedUFlag = 1;
    integerProcessor(A, buf, info);
    info->step++;
  }
}

void floatAndHexadecimal(va_list A, const char *buf, const char *format,
                         specifierInfo *info) {
  if (format[info->step] == 'e' || format[info->step] == 'E' ||
      format[info->step] == 'g' || format[info->step] == 'G' ||
      format[info->step] == 'f') {  // float variations
    floatProcessor(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'x' ||
      format[info->step] == 'X') {  // 16x unsigned integer
    hexadecimalProcessor(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'p') {  // pointer
    info->flagP = 1;
    pointerReader(A, buf, info);
    info->step++;
  }
  if (format[info->step] == 'n') {  // specifier counter
    nCounter(A, info);
    info->step++;
  }
}

void widthParser(const char *format, specifierInfo *info) {
  if (format[info->step] >= '1' && format[info->step] <= '9') {  // width
    int first = 0, second = 0;
    first = format[info->step] - '0';
    while (format[info->step + 1] >= '0' && format[info->step + 1] <= '9') {
      first *= 10;
      second = format[info->step + 1] - '0';
      first += second;
      info->step++;
    }
    info->dotWidth = first;
    info->step++;
  }
}

void star(specifierInfo *info, const char *buf) {
  while (buf[info->bufStep] != ' ') {
    info->bufStep++;
  }
  info->step += 2;
}

void resetToZero(specifierInfo *info) {
  info->minusFlag = 0;
  info->dotWidth = 0;
  info->hLength = 0;
  info->lLength = 0;
  info->LLength = 0;
  info->counter = 0;
  info->unsignedOFlag = 0;
  info->unsignedUFlag = 0;
}

void plusAndMinusChecker(const char *buf, specifierInfo *info) {
  if (buf[info->bufStep] == '-' && buf[info->bufStep + 1] >= '0' &&
      buf[info->bufStep + 1] <= '9') {
    info->minusFlag = 1;
    info->bufStep++;
    if (info->dotWidth > 0) info->dotWidth--;
  }
  if (buf[info->bufStep] == '+' && buf[info->bufStep + 1] >= '0' &&
      buf[info->bufStep + 1] <= '9')
    info->bufStep++;
}

void nCounter(va_list A, specifierInfo *info) {
  int *counter = va_arg(A, int *);
  if (info->flagP)
    *counter = info->bufStep - 1;
  else
    *counter = info->bufStep;
}

void symbolReader(va_list A, const char *buf, specifierInfo *info) {
  s21_size_t q = 0;
  char *symbol = va_arg(A, char *);
  if (info->dotWidth == 0) {
    symbol[q] = buf[info->bufStep];
    info->bufStep++;
    info->specifierCounter++;
  } else {
    while (buf[info->bufStep] != '\0' && info->dotWidth--) {
      symbol[q] = buf[info->bufStep];
      q++;
      info->bufStep++;
    }
    info->specifierCounter++;
  }
}

void stringReader(va_list A, const char *buf, specifierInfo *info) {
  s21_size_t q = 0;
  char *string = va_arg(A, char *);
  if (info->dotWidth == 0) {
    while (buf[info->bufStep] != ' ' && buf[info->bufStep] != '\0') {
      string[q] = buf[info->bufStep];
      q++;
      info->bufStep++;
    }
  } else {
    while (buf[info->bufStep] != ' ' && buf[info->bufStep] != '\0' &&
           info->dotWidth--) {
      string[q] = buf[info->bufStep];
      q++;
      info->bufStep++;
    }
  }
  resetToZero(info);
  info->specifierCounter++;
}

void integerProcessor(va_list A, const char *buf, specifierInfo *info) {
  plusAndMinusChecker(buf, info);
  if (buf[info->bufStep] >= '0' && buf[info->bufStep] <= '9') {
    integerReader(A, buf, info);
  } else if (buf[info->bufStep] == ' ') {
    info->specifierCounter--;
  }
  resetToZero(info);
}

void integerReader(va_list A, const char *buf, specifierInfo *info) {
  long int first = 0, second = 0;
  first = buf[info->bufStep] - '0';
  if (info->unsignedOFlag == 1 && first == 8) info->specifierCounter--;
  if (info->dotWidth == 0) {
    while (buf[info->bufStep + 1] >= '0' && buf[info->bufStep + 1] <= '9') {
      if (info->unsignedOFlag == 1)
        first *= 8;
      else
        first *= 10;
      second = buf[info->bufStep + 1] - '0';
      first += second;
      info->bufStep++;
    }
  } else {
    while (buf[info->bufStep + 1] >= '0' && buf[info->bufStep + 1] <= '9' &&
           info->dotWidth != 1) {
      if (info->unsignedOFlag == 1)
        first *= 8;
      else
        first *= 10;
      second = buf[info->bufStep + 1] - '0';
      first += second;
      info->bufStep++;
      info->dotWidth--;
    }
  }
  integerReturner(A, info, &first);
  info->bufStep++;
  info->specifierCounter++;
}

void integerReturner(va_list A, specifierInfo *info, long int *first) {
  if (info->hLength == 1) {
    short int *numberShort = va_arg(A, short int *);
    if (info->minusFlag) {
      *numberShort = -(*first);
    } else
      *numberShort = *first;
  } else if (info->lLength == 1) {
    long int *numberLong = va_arg(A, long int *);
    if (info->minusFlag) {
      *numberLong = -(*first);
    } else
      *numberLong = *first;
  } else if (info->unsignedOFlag == 1 || info->unsignedUFlag == 1) {
    unsigned int *numberUnsigned = va_arg(A, unsigned int *);
    if (info->minusFlag) {
      *numberUnsigned = -(*first);
    } else
      *numberUnsigned = *first;
  } else {
    int *number = va_arg(A, int *);
    if (info->minusFlag) {
      *number = -(*first);
    } else
      *number = *first;
  }
}

void iSpecifier(va_list A, const char *buf, specifierInfo *info) {
  if (buf[info->bufStep] == '0') {
    if (buf[info->bufStep + 1] == 'x' || buf[info->bufStep + 1] == 'X') {
      hexadecimalProcessor(A, buf, info);
    } else {
      info->unsignedOFlag = 1;
      integerProcessor(A, buf, info);
    }
  } else
    integerProcessor(A, buf, info);
}

void floatProcessor(va_list A, const char *buf, specifierInfo *info) {
  plusAndMinusChecker(buf, info);
  if (buf[info->bufStep] >= '0' && buf[info->bufStep] <= '9') {
    floatReader(A, buf, info);
  }
  resetToZero(info);
}

void floatReader(va_list A, const char *buf, specifierInfo *info) {
  int counter = 1;
  long double firstFloat = 0.0, secondFloat = 0.0;
  firstFloat = buf[info->bufStep] - '0';
  if (info->dotWidth == 0) {
    for (; buf[info->bufStep + 1] >= '0' && buf[info->bufStep + 1] <= '9';
         info->bufStep++) {
      floatCountingFirst(buf, info, &firstFloat, &secondFloat);
    }
    if (buf[info->bufStep + 1] >= '.') {
      info->bufStep += 2;
      for (; buf[info->bufStep] >= '0' && buf[info->bufStep] <= '9';
           info->bufStep++) {
        floatCountingSecond(buf, info, &firstFloat, &secondFloat, &counter);
      }
    }
  } else {
    for (; buf[info->bufStep + 1] >= '0' && buf[info->bufStep + 1] <= '9' &&
           info->dotWidth > 1;
         info->bufStep++) {
      info->dotWidth--;
      floatCountingFirst(buf, info, &firstFloat, &secondFloat);
    }
    if (!(buf[info->bufStep + 2] >= '0' && buf[info->bufStep + 2] <= '9'))
      info->dotWidth = 0;
    if (buf[info->bufStep + 1] >= '.' && info->dotWidth > 1) {
      info->dotWidth--;
      for (; buf[info->bufStep] >= '0' && buf[info->bufStep] <= '9' &&
             info->dotWidth--;
           info->bufStep++) {
        floatCountingSecond(buf, info, &firstFloat, &secondFloat, &counter);
      }
    }
  }
  floatReturner(A, info, &firstFloat);
  info->bufStep++;
  info->specifierCounter++;
}

void floatCountingFirst(const char *buf, specifierInfo *info,
                        long double *firstFloat, long double *secondFloat) {
  *firstFloat *= 10;
  *secondFloat = buf[info->bufStep + 1] - '0';
  *firstFloat += *secondFloat;
}

void floatCountingSecond(const char *buf, specifierInfo *info,
                         long double *firstFloat, long double *secondFloat,
                         int *counter) {
  *secondFloat = (buf[info->bufStep] - '0') / (pow(10, *counter));
  *firstFloat += *secondFloat;
  (*counter)++;
}

void floatReturner(va_list A, specifierInfo *info, long double *firstFloat) {
  if (info->LLength == 1) {
    long double *numberLong = va_arg(A, long double *);
    if (info->minusFlag == 1) {
      *numberLong = -(*firstFloat);
    } else
      *numberLong = *firstFloat;
  } else {
    float *number = va_arg(A, float *);
    if (info->minusFlag) {
      *number = -(*firstFloat);
    } else
      *number = *firstFloat;
  }
}

void hexadecimalProcessor(va_list A, const char *buf, specifierInfo *info) {
  int widthFlag = 0;
  info->hexadecimalStep = -1;
  unsigned long int first = 0;
  plusAndMinusChecker(buf, info);
  nullAndXChecker(buf, info, &widthFlag);
  const char *s = &buf[info->bufStep];
  for (; *s != ' ' && *s != '\0'; info->hexadecimalStep++) s++;
  if (info->dotWidth == 0) {
    hexadecimalReader(buf, info, &first);
  } else {
    for (; *s != ' ' && *s != '\0'; info->hexadecimalStep++) s++;
    if (info->hexadecimalStep >= info->dotWidth)
      info->hexadecimalStep = info->dotWidth - 1;
    hexadecimalReaderWidth(buf, info, &first);
  }
  hexadecimalReturner(A, info, &first);
  info->bufStep++;
  resetToZero(info);
  info->specifierCounter++;
}

void hexadecimalReader(const char *buf, specifierInfo *info,
                       unsigned long int *first) {
  unsigned long int second = 0;
  while (buf[info->bufStep] != ' ' && buf[info->bufStep] != '\0') {
    if (buf[info->bufStep] >= '0' && buf[info->bufStep] <= '9') {
      second = (buf[info->bufStep] - '0') * pow(16, info->hexadecimalStep);
      *first += second;
    } else if (buf[info->bufStep] >= 'A' && buf[info->bufStep] <= 'Z') {
      second =
          ((buf[info->bufStep] - 65) + 10) * pow(16, info->hexadecimalStep);
      *first += second;
    } else if (buf[info->bufStep] >= 'a' && buf[info->bufStep] <= 'z') {
      second =
          ((buf[info->bufStep] - 97) + 10) * pow(16, info->hexadecimalStep);
      *first += second;
    } else {
      break;
    }
    info->hexadecimalStep--;
    info->bufStep++;
  }
}

void hexadecimalReaderWidth(const char *buf, specifierInfo *info,
                            unsigned long int *first) {
  unsigned long int second = 0;
  while (buf[info->bufStep] != ' ' && buf[info->bufStep] != '\0' &&
         info->dotWidth >= 1) {
    if (buf[info->bufStep] >= '0' && buf[info->bufStep] <= '9') {
      second = (buf[info->bufStep] - '0') * pow(16, info->hexadecimalStep);
      *first += second;
      if (info->dotWidth != 0) info->dotWidth--;
    } else if (buf[info->bufStep] >= 'A' && buf[info->bufStep] <= 'Z') {
      second =
          ((buf[info->bufStep] - 65) + 10) * pow(16, info->hexadecimalStep);
      *first += second;
      if (info->dotWidth != 0) info->dotWidth--;
    } else if (buf[info->bufStep] >= 'a' && buf[info->bufStep] <= 'z') {
      second =
          ((buf[info->bufStep] - 97) + 10) * pow(16, info->hexadecimalStep);
      *first += second;
      if (info->dotWidth != 0) info->dotWidth--;
    } else {
      break;
    }
    info->hexadecimalStep--;
    info->bufStep++;
  }
}

void hexadecimalReturner(va_list A, specifierInfo *info,
                         unsigned long int *first) {
  if (info->hLength == 1) {
    unsigned short int *numberShort = va_arg(A, unsigned short int *);
    if (info->minusFlag) {
      *numberShort = -(*first);
    } else
      *numberShort = *first;
  } else if (info->lLength == 1) {
    unsigned long int *numberLong = va_arg(A, unsigned long int *);
    if (info->minusFlag) {
      *numberLong = -(*first);
    } else
      *numberLong = *first;
  } else {
    unsigned int *number = va_arg(A, unsigned int *);
    if (info->minusFlag) {
      *number = -(*first);
    } else
      *number = *first;
  }
}

void pointerReader(va_list A, const char *buf, specifierInfo *info) {
  int widthFlag = 0;
  info->hexadecimalStep = -1;
  unsigned long int first = 0;
  plusAndMinusChecker(buf, info);
  nullAndXChecker(buf, info, &widthFlag);
  const char *s = &buf[info->bufStep];
  for (; *s != ' ' && *s != '\0'; info->hexadecimalStep++) s++;
  if (info->dotWidth == 0 && widthFlag == 0) {
    hexadecimalReader(buf, info, &first);
  } else {
    for (; *s != ' ' && *s != '\0'; info->hexadecimalStep++) s++;
    if (info->hexadecimalStep >= info->dotWidth)
      info->hexadecimalStep = info->dotWidth - 1;
    hexadecimalReaderWidth(buf, info, &first);
  }
  void **number = va_arg(A, void **);
  *number = (void *)(0x0 + first);
  info->bufStep++;
  resetToZero(info);
  info->specifierCounter++;
}

void nullAndXChecker(const char *buf, specifierInfo *info, int *widthFlag) {
  if (buf[info->bufStep] == '0' &&
      (buf[info->bufStep + 1] == 'x' || buf[info->bufStep + 1] == 'X')) {
    info->bufStep += 2;
    if (info->dotWidth != 0) {
      info->dotWidth -= 2;
      if (info->dotWidth == 0) *widthFlag = 1;
    }
  }
}
