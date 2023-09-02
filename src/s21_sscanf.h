#include "s21_string.h"

typedef struct {
  int bufStep;
  int step;
  int minusFlag;
  int dotWidth;
  int error;
  int hLength;
  int lLength;
  int LLength;
  int unsignedOFlag;
  int unsignedUFlag;
  int flagP;
  int counter;
  int hexadecimalStep;
  int specifierCounter;
} specifierInfo;

// parser functions
void integerAndChar(va_list A, const char *buf, const char *format,
                    specifierInfo *info);
void floatAndHexadecimal(va_list A, const char *buf, const char *format,
                         specifierInfo *info);
// additions functions
void additions(const char *buf, const char *format, specifierInfo *info);
void star(specifierInfo *info, const char *buf);
void resetToZero(specifierInfo *info);
void plusAndMinusChecker(const char *buf, specifierInfo *info);
void widthParser(const char *format, specifierInfo *info);
void nCounter(va_list A, specifierInfo *info);
// char functions
void stringReader(va_list A, const char *buf, specifierInfo *info);
void symbolReader(va_list A, const char *buf, specifierInfo *info);
// integer functions
void integerProcessor(va_list A, const char *buf, specifierInfo *info);
void integerReader(va_list A, const char *buf, specifierInfo *info);
void integerReturner(va_list A, specifierInfo *info, long int *first);
void iSpecifier(va_list A, const char *buf, specifierInfo *info);
// float functions
void floatProcessor(va_list A, const char *buf, specifierInfo *info);
void floatReader(va_list A, const char *buf, specifierInfo *info);
void floatCountingFirst(const char *buf, specifierInfo *info,
                        long double *firstFloat, long double *secondFloat);
void floatCountingSecond(const char *buf, specifierInfo *info,
                         long double *firstFloat, long double *secondFloat,
                         int *counter);
void floatReturner(va_list A, specifierInfo *info, long double *firstFloat);
// hexadecimal functions
void hexadecimalProcessor(va_list A, const char *buf, specifierInfo *info);
void pointerReader(va_list A, const char *buf, specifierInfo *info);
void hexadecimalReader(const char *buf, specifierInfo *info,
                       unsigned long int *first);
void hexadecimalReaderWidth(const char *buf, specifierInfo *info,
                            unsigned long int *first);
void hexadecimalReturner(va_list A, specifierInfo *info,
                         unsigned long int *first);
void nullAndXChecker(const char *buf, specifierInfo *info, int *widthFlag);