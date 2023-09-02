#ifndef SRC_S21_SPRINF_H_
#define SRC_S21_SPRINF_H_

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#include "s21_string.h"

typedef struct {
  bool plus_flag;
  bool minus_flag;
  bool space_flag;
  bool sharp_flag;
  bool zero_flag;
  bool h_flag;
  bool double_h_flag;
  bool l_flag;
  bool double_l_flag;
  bool L_flag;
  bool width_flag;
  bool accuracy_flag;
  bool double_flag;
  bool conflict_flag;
  bool wrong_spec;
  int width;
  int accuracy;
  char spec;
  int buf_s;
} Flags;

int ChooseWay(Flags *flags, char *buf, va_list ap);
int ParseFlags(Flags *flags, const char *str);
int ParseLenFlags(Flags *flags, const char *str);
int ParseSpecifier(Flags *flags, const char *str, va_list ap);
int CheckWidAcc(Flags *flags, const char *str, va_list ap);
int GetSpecifier(Flags *flags, const char *str);
int CharToDigit(char c);
int StrToNum(char *str);
int IntToStr(char *buf, int num);
int AddSymToStr(char *buf, char sym);
char DigitToChar(int num);

int longAddFirstSym(Flags *flags, char *str, long num);
char longDigitToChar(long num);
int longParseNum(Flags *flags, char *str, long num);
int longIntToStr(char *str, long num);
int longCheckNumLen(long num);
void longDefineWidAcc(Flags *flags, long num);
int longIntToStr(char *str, long num);
int unsignedLongParseNum(Flags *flags, char *str, unsigned long num);
int unsignedLongCheckNumLen(unsigned long num);
int unsignedLongIntToStr(char *str, unsigned long num);
void unsignedLongDefineWidAcc(Flags *flags, unsigned long num);
int longDoubleParseNum(Flags *flags, char *str, long double num);
int integerPartToStr(Flags *flags, char *str, long double num);
int fractionalPartToStr(Flags *flags, char *str, long double num);
int doubleAddFirstSym(Flags *flags, char *str, long double num);
void doubleDefineWidAcc(Flags *flags);

int ParseChar(Flags *flags, char *str, char symbvol);
int ParseString(Flags *flags, char *str, char *newstr);

void revstr(char *src);
int StrBlockMinus(Flags *flags, char *str, char *src, int step, int col_width,
                  int col_accuracy, int len);
int StrBlockNoMinus(Flags *flags, char *str, char *src, int step, int col_width,
                    int col_accuracy, int len);
int Result816(char *str, char *src, int col_accuracy, int col_width, int len,
              int step, int flag);
void IntToStroxX(Flags *flags, char *src, long int num);
void unsigned_IntToStroxX(Flags *flags, char *src, long unsigned int num);
int Spec_x(Flags *flags, char *buf, int step, va_list ap);
int Spec_o(Flags *flags, char *buf, int step, va_list ap);
int Spec_P(Flags *flags, char *buf, int step, va_list ap);
int AddSymToStr(char *buf, char sym);

int Parse_e_E(Flags *flags, char *str, long double num);
int Parse_e_E_end(Flags *flags, char *str, int count_minus, int count_plus);
int Parse_double_end(Flags *flags, char *str, char *pstart);

int Parse_g_G(Flags *flags, char *str, long double num);
int G_longDoubleParseNum(Flags *flags, char *str, long double num);
int G_Parse_e_E(Flags *flags, char *str, long double num);
void G_doubleDefineWidAcc(Flags *flags);
int G_fractionalPartToStr(Flags *flags, char *str, long double num);
int IntToStr(char *buf, int num);
#endif  // SRC_S21_SPRINF_H_
