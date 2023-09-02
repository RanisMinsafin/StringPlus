#include "s21_sprintf.h"

#define MAX_ACCURACY 19

int s21_sprintf(char *buf, const char *str, ...) {
  va_list ap;
  va_start(ap, str);
  int buf_step = 0, str_step = 0;
  for (; str[str_step] != '\0';) {
    if (str[str_step] != '%') {
      buf[buf_step] = str[str_step];
      str_step++;
      buf_step++;
    } else {
      Flags flags = {0, 0, 0, 0, 0, 0,  0,  0,   0, 0,
                     0, 0, 0, 0, 0, -1, -1, '0', 0};
      str_step += ParseSpecifier(&flags, str + str_step, ap);
      flags.buf_s = buf_step;
      buf_step += ChooseWay(&flags, buf + buf_step, ap);
    }
  }
  va_end(ap);
  buf[buf_step] = '\0';
  return buf_step;
}

int ChooseWay(Flags *flags, char *buf, va_list ap) {
  int step = 0;
  if (flags->spec == 'd' || flags->spec == 'i') {
    long arg = va_arg(ap, long);
    if (flags->h_flag) arg = (short)arg;
    if (!flags->l_flag && !flags->h_flag) arg = (int)arg;
    if (!(flags->accuracy == 0 && arg == 0))
      step += longParseNum(flags, buf + step, arg);
  } else if (flags->spec == 'u') {
    unsigned long arg = va_arg(ap, unsigned long);
    if (flags->h_flag) arg = (unsigned short)arg;
    if (!flags->l_flag && !flags->h_flag) arg = (unsigned int)arg;
    if (!(flags->accuracy == 0 && arg == 0))
      step += unsignedLongParseNum(flags, buf + step, arg);
  } else if (flags->spec == 'f') {
    long double arg = 0;
    if (flags->L_flag) arg = va_arg(ap, long double);
    if (!flags->L_flag) arg = va_arg(ap, double);
    step += longDoubleParseNum(flags, buf + step, arg);
  } else if (flags->spec == 'c') {
    char arg = va_arg(ap, int);
    step += ParseChar(flags, buf + step, arg);
  } else if (flags->spec == 's') {
    char *arg = va_arg(ap, char *);
    step += ParseString(flags, buf + step, arg);
  } else if (flags->spec == 'x' || flags->spec == 'X') {
    step += Spec_x(flags, buf, step, ap);
  } else if (flags->spec == 'o') {
    step += Spec_o(flags, buf, step, ap);
  } else if (flags->spec == '%') {
    step += ParseChar(flags, buf + step, '%');
  } else if (flags->spec == 'n') {
    int *arg = va_arg(ap, int *);
    *arg = flags->buf_s;
  } else if (flags->spec == 'p') {
    step += Spec_P(flags, buf, step, ap);
  } else if (flags->spec == 'e' || flags->spec == 'E') {
    long double arg = 0;
    if (flags->L_flag) arg = va_arg(ap, long double);
    if (!flags->L_flag) arg = va_arg(ap, double);
    step += Parse_e_E(flags, buf + step, arg);
  } else if (flags->spec == 'g' || flags->spec == 'G') {
    long double arg = 0;
    if (flags->L_flag) arg = va_arg(ap, long double);
    if (!flags->L_flag) arg = va_arg(ap, double);
    step += Parse_g_G(flags, buf + step, arg);
  }
  return step;
}

int ParseSpecifier(Flags *flags, const char *str, va_list ap) {
  int step = 0;
  step++;
  step += ParseFlags(flags, str + step);
  step += CheckWidAcc(flags, str + step, ap);
  step += ParseLenFlags(flags, str + step);
  step += GetSpecifier(flags, str + step);
  return step;
}

int ParseFlags(Flags *flags, const char *str) {
  int step = 0;
  bool av_sym = 1;
  for (; av_sym; step++) {
    if ((str[step] == '+' && flags->plus_flag) ||
        (str[step] == '-' && flags->minus_flag) ||
        (str[step] == ' ' && flags->space_flag) ||
        (str[step] == '#' && flags->sharp_flag) ||
        (str[step] == '0' && flags->zero_flag)) {
      flags->double_flag = 1;
    } else if (str[step] == '+') {
      flags->plus_flag = 1;
    } else if (str[step] == '-') {
      flags->minus_flag = 1;
    } else if (str[step] == ' ') {
      flags->space_flag = 1;
    } else if (str[step] == '#') {
      flags->sharp_flag = 1;
    } else if (str[step] == '0') {
      flags->zero_flag = 1;
    } else {
      av_sym = 0;
    }
  }
  return --step;
}

int CheckWidAcc(Flags *flags, const char *str, va_list ap) {
  int step = 0;
  char width_buf[BUFSIZ] = {'\0'}, accuracy_buf[BUFSIZ] = {'\0'};
  bool av_sym = 1;
  for (int i = 0; av_sym; (step)++, i++) {
    if (str[step] >= 48 && str[step] <= 57) {
      flags->width_flag = 1;
      width_buf[i] = str[step];
    } else if (str[step] == '*') {
      flags->width_flag = 1;
      flags->width = va_arg(ap, int);
      step++;
      av_sym = 0;
    } else {
      av_sym = 0;
    }
  }
  if (str[step - 1] == '.') {
    av_sym = 1;
    for (int i = 0; av_sym; (step)++, i++) {
      if (str[step] >= 48 && str[step] <= 57) {
        flags->accuracy_flag = 1;
        accuracy_buf[i] = str[step];
      } else if (str[step] == '*') {
        flags->accuracy_flag = 1;
        flags->accuracy = va_arg(ap, int);
        step++;
        av_sym = 0;
      } else if (i == 0 && !(str[step] >= 48 && str[step] <= 57)) {
        flags->accuracy = 0;
        av_sym = 0;
      } else {
        av_sym = 0;
      }
    }
  }
  if (width_buf[0] != '\0') flags->width = StrToNum(width_buf);
  if (accuracy_buf[0] != '\0') flags->accuracy = StrToNum(accuracy_buf);
  return --step;
}

int StrToNum(char *str) {
  int num = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    num = num * 10 + CharToDigit(str[i]);
  }
  return num;
}

int CharToDigit(char c) { return c - '0'; }

int GetSpecifier(Flags *flags, const char *str) {
  if (str[0] == 'c')
    flags->spec = 'c';
  else if (str[0] == 'd')
    flags->spec = 'd';
  else if (str[0] == 'i')
    flags->spec = 'i';
  else if (str[0] == 'f')
    flags->spec = 'f';
  else if (str[0] == 's')
    flags->spec = 's';
  else if (str[0] == 'u')
    flags->spec = 'u';
  else if (str[0] == 'g')
    flags->spec = 'g';
  else if (str[0] == 'G')
    flags->spec = 'G';
  else if (str[0] == 'e')
    flags->spec = 'e';
  else if (str[0] == 'E')
    flags->spec = 'E';
  else if (str[0] == 'x')
    flags->spec = 'x';
  else if (str[0] == 'X')
    flags->spec = 'X';
  else if (str[0] == 'o')
    flags->spec = 'o';
  else if (str[0] == 'n')
    flags->spec = 'n';
  else if (str[0] == 'p')
    flags->spec = 'p';
  else if (str[0] == '%')
    flags->spec = '%';
  else {
    flags->spec = str[0];
    flags->wrong_spec = 1;
  }
  return 1;
}

int ParseLenFlags(Flags *flags, const char *str) {
  int step = 0;
  bool av_sym = 1;
  for (; av_sym; step++) {
    if ((str[step] == 'l' && flags->double_l_flag) ||
        (str[step] == 'h' && flags->double_h_flag) ||
        (str[step] == 'L' && flags->L_flag)) {
      flags->double_flag = 1;
    } else if (str[step] == 'l') {
      if (flags->l_flag) flags->double_l_flag = 1;
      flags->l_flag = 1;
    } else if (str[step] == 'h') {
      if (flags->h_flag) flags->double_h_flag = 1;
      flags->h_flag = 1;
    } else if (str[step] == 'L') {
      flags->L_flag = 1;
    } else {
      av_sym = 0;
    }
  }
  return --step;
}

int longParseNum(Flags *flags, char *str, long num) {
  int step = 0;
  char *p = str;
  bool flagWa = 0;
  step += longAddFirstSym(flags, str + step, num);

  longDefineWidAcc(flags, num);
  if (flags->width > flags->accuracy && flags->accuracy_flag) flagWa = 1;

  if (!flags->minus_flag) {
    char sym = ' ';
    if ((flags->zero_flag) && !flags->accuracy_flag) sym = '0';
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, sym);
    }
  }

  if ((step && !flags->zero_flag) || (step && flags->zero_flag && flagWa)) {
    char c = *p;
    *p = str[step - 1];
    str[step - 1] = c;
  }

  for (; flags->accuracy > 0; flags->accuracy--) {
    step += AddSymToStr(str + step, '0');
  }

  step += longIntToStr(str + step, num);

  if (flags->minus_flag) {
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, ' ');
    }
  }

  return step;
}

char longDigitToChar(long num) {
  if (num < 0) num *= -1;
  return num + '0';
}

int longCheckNumLen(long num) {
  int length = 1;
  if (num != 0)
    for (length--; num != 0; length++) num /= 10;
  return length;
}

int longIntToStr(char *str, long num) {
  int step = 0;
  char *pstart = str;

  do {
    str[step++] = DigitToChar(num % 10);
    num /= 10;
  } while (num != 0);

  for (char *pend = str + step - 1, *plast = pend; pstart < plast;) {
    char c = *pstart;
    *pstart++ = *plast;
    *plast-- = c;
  }

  str[step] = '\0';
  return step;
}

void longDefineWidAcc(Flags *flags, long num) {
  int standart = 0;
  if (flags->accuracy == -1 || flags->accuracy <= longCheckNumLen(num))
    flags->accuracy = standart;

  if (flags->accuracy > longCheckNumLen(num))
    flags->accuracy -= longCheckNumLen(num);

  flags->width -= (flags->accuracy + longCheckNumLen(num));
}

int longAddFirstSym(Flags *flags, char *str, long num) {
  int step = 0;
  if (num >= 0 && flags->plus_flag) {
    step += AddSymToStr(str, '+');
  } else if (num < 0) {
    step += AddSymToStr(str, '-');
    flags->plus_flag = 1;
  } else if (flags->space_flag && !flags->plus_flag) {
    step += AddSymToStr(str, ' ');
  }
  if (step) flags->width--;
  return step;
}

int AddSymToStr(char *buf, char sym) {
  buf[0] = sym;
  return 1;
}

char DigitToChar(int num) {
  if (num < 0) num *= -1;
  return num + '0';
}

int G_longDoubleParseNum(Flags *flags, char *str, long double num) {
  int step = 0;
  char *pstart = str;

  step += doubleAddFirstSym(flags, str + step, num);
  if (flags->zero_flag && step) pstart++;
  if (((num - (int)num)) == 0) flags->accuracy = 0;
  G_doubleDefineWidAcc(flags);
  step += integerPartToStr(flags, str + step, num);
  step += G_fractionalPartToStr(flags, str + step, num);
  step += Parse_double_end(flags, str + step, pstart);
  return step;
}

int G_fractionalPartToStr(Flags *flags, char *str, long double num) {
  int step = 0;
  long double rounder = 0.05;
  if (flags->accuracy != 0 || flags->sharp_flag) {
    str[step++] = '.';
  }
  if (num != 0) {
    for (int i = 0; i < flags->accuracy - 1; i++) rounder /= 10;
    if (num < 0) rounder *= -1;
    num += rounder;
    while (flags->accuracy-- > 0) {
      num -= (long)num;
      num *= 10;
      str[step++] = longDigitToChar((long)(num));
    }
    if (!flags->sharp_flag) {
      int step_new = step - 1;
      while (str[step_new] == '0') {
        str[step_new--] = '\0';
        step--;
        flags->width++;
      }
    }
  }
  return step;
}

void G_doubleDefineWidAcc(Flags *flags) {
  if (flags->accuracy != 0) flags->width--;
  flags->width -= flags->accuracy;
}

int longDoubleParseNum(Flags *flags, char *str, long double num) {
  int step = 0;
  char *pstart = str;
  doubleDefineWidAcc(flags);
  step += doubleAddFirstSym(flags, str + step, num);
  if (flags->zero_flag && step) pstart++;
  step += integerPartToStr(flags, str + step, num);
  step += fractionalPartToStr(flags, str + step, num);
  step += Parse_double_end(flags, str + step, pstart);
  return step;
}

int doubleAddFirstSym(Flags *flags, char *str, long double num) {
  int step = 0;
  if (num >= 0 && flags->plus_flag) {
    step += AddSymToStr(str, '+');
    flags->width--;
  } else if (num < 0) {
    step += AddSymToStr(str, '-');
    flags->width--;
    flags->plus_flag = 1;
  } else if (flags->space_flag && !flags->plus_flag) {
    step += AddSymToStr(str, ' ');
    flags->width--;
  }
  return step;
}

int fractionalPartToStr(Flags *flags, char *str, long double num) {
  int step = 0;
  long double rounder = 0.05;
  int acc = flags->accuracy;

  if (acc > MAX_ACCURACY) acc = MAX_ACCURACY;
  if (acc != 0 || flags->sharp_flag) {
    str[step++] = '.';
  }

  for (int i = 0; i < acc; i++) rounder /= 10;
  if (flags->accuracy < 15) rounder *= 10;
  if (num < 0) rounder *= -1;
  num += rounder;

  while (flags->accuracy-- > 0) {
    num -= (long)num;
    num *= 10;
    str[step++] = longDigitToChar((long)(num));
  }

  return step;
}

int integerPartToStr(Flags *flags, char *str, long double num) {
  int step = 0;
  int counter = 0;

  int first_fraction = (int)((num - (int)num) * 10);

  if (flags->accuracy == 0 && (first_fraction >= 5 || first_fraction <= -5)) {
    if (num >= 0)
      num++;
    else
      num--;
  }
  if (num < 1 && num > -1) {
    str[step++] = '0';
    flags->width--;
  }
  while (num >= 1 || num <= -1) {
    num /= 10;
    counter++;
    flags->width--;
  }
  while (counter-- > 0) {
    num *= 10;
    str[step++] = longDigitToChar((long)(num));
    num -= (long)num;
  }
  return step;
}

void doubleDefineWidAcc(Flags *flags) {
  if (flags->accuracy == -1) flags->accuracy = 6;
  if (flags->accuracy != 0) flags->width--;
  flags->width -= flags->accuracy;
}

int Parse_g_G(Flags *flags, char *str, long double num) {
  int step = 0;
  int exp = 0;
  long double num_neww = num;
  if (num < 0) num_neww *= -1;
  if (num_neww >= 10) {
    while (num_neww >= 10) {
      num_neww = num_neww / 10.0;
      exp++;
    }
  } else {
    if (num_neww < 1 && num_neww != 0) {
      while (num_neww < 1) {
        num_neww = num_neww * 10;
        exp--;
      }
    }
  }

  int flag = 0;
  if (flags->accuracy == -1) {
    flags->accuracy = 6;
  } else if (flags->accuracy == 0) {
    flags->accuracy = 1;
    flag = 1;
  }

  if (flags->accuracy > exp && exp >= -4) {
    flags->accuracy -= (exp + 1);
    step += G_longDoubleParseNum(flags, str + step, num);
  } else {
    if (flag == 1 || flags->accuracy == 1) {
      flags->accuracy = 0;
    }
    step += G_Parse_e_E(flags, str + step, num);
  }
  return step;
}
int long_Parse_o_x_X(Flags *flags, char *str, long int num) {
  char src[500] = {"\0"};
  IntToStroxX(flags, src, num);
  revstr(src);
  int len = s21_strlen(src);
  int step = 0;
  int standart = 0;
  int col_accuracy, col_width = 0;
  if (flags->accuracy == -1 || flags->accuracy <= len)
    flags->accuracy = standart;
  if (flags->accuracy == 0) {
    col_width = flags->width - len;
  } else {
    col_width = flags->width - flags->accuracy;
  }
  col_accuracy = flags->accuracy - len;
  if (flags->minus_flag) {
    step = StrBlockMinus(flags, str, src, step, col_width, col_accuracy, len);
  } else {
    step = StrBlockNoMinus(flags, str, src, step, col_width, col_accuracy, len);
  }
  return step;
}

void IntToStroxX(Flags *flags, char *src, long int num) {
  int num1 = 0;
  int num_x = 87;
  int res = 0;
  int del = 16;
  char c = '\0';
  if (flags->spec == 'X') num_x = 55;
  if (flags->spec == 'o') del = 8;

  if (num == 0) {
    src[0] = '0';
  } else {
    for (int i = 0; num > 0; i++) {
      num1 = num;
      num = num / del;
      res = num1 - (num * del);
      if (res > 9 && res < 16) {
        c = num_x + res;
      } else {
        c = 48 + res;
      }
      src[i] = c;
    }
  }
}

int unsigned_long_Parse_o_x_X(Flags *flags, char *str, long unsigned int num) {
  char src[500] = {"\0"};
  unsigned_IntToStroxX(flags, src, num);
  revstr(src);
  int len = s21_strlen(src);
  int step = 0;
  int standart = 0;
  int col_accuracy, col_width = 0;
  if (flags->accuracy == -1 || flags->accuracy <= len)
    flags->accuracy = standart;
  if (flags->accuracy == 0) {
    col_width = flags->width - len;
  } else {
    col_width = flags->width - flags->accuracy;
  }
  col_accuracy = flags->accuracy - len;
  if (flags->minus_flag) {
    step = StrBlockMinus(flags, str, src, step, col_width, col_accuracy, len);
  } else {
    step = StrBlockNoMinus(flags, str, src, step, col_width, col_accuracy, len);
  }
  return step;
}

void unsigned_IntToStroxX(Flags *flags, char *src, long unsigned int num) {
  long unsigned int num1 = 0;
  int num_x = 87;
  int res = 0;
  int del = 16;
  char c = '\0';
  if (flags->spec == 'X') {
    num_x = 55;
  }
  if (flags->spec == 'o') {
    del = 8;
  }
  if (num == 0) {
    src[0] = '0';
  } else {
    for (int i = 0; num > 0; i++) {
      num1 = num;
      num = num / del;
      res = num1 - (num * del);
      if (res > 9 && res < 16) {
        c = num_x + res;
      } else {
        c = 48 + res;
      }
      src[i] = c;
    }
  }
}

void revstr(char *src) {
  int i = 0, len = 0, temp = 0;
  len = s21_strlen(src);
  for (i = 0; i < len / 2; i++) {
    temp = src[i];
    src[i] = src[len - i - 1];
    src[len - i - 1] = temp;
  }
}

int StrBlockMinus(Flags *flags, char *str, char *src, int step, int col_width,
                  int col_accuracy, int len) {
  int flag = 0;
  if ((flags->sharp_flag && src[0] != '0') || flags->spec == 'p') {
    if (flags->spec == 'o') {
      step += AddSymToStr(str + step, '0');
      if (flags->width && !flags->accuracy) {
        col_width -= 1;
      }
      col_accuracy -= 1;
    }
    if (flags->spec == 'x' || flags->spec == 'p') {
      step += AddSymToStr(str + step, '0');
      step += AddSymToStr(str + step, 'x');
      col_width -= 2;
    }
    if (flags->spec == 'X') {
      step += AddSymToStr(str + step, '0');
      step += AddSymToStr(str + step, 'X');
      col_width -= 2;
    }
  }
  step = Result816(str, src, col_accuracy, col_width, len, step, flag);
  return step;
}
int StrBlockNoMinus(Flags *flags, char *str, char *src, int step, int col_width,
                    int col_accuracy, int len) {
  int flag = 1;
  char widht_sym = ' ';
  if (flags->sharp_flag) {
    if (flags->spec == 'o') {
      if (flags->width && !flags->accuracy) {
        col_width -= 1;
      }
      col_accuracy -= 1;
    } else {
      col_width -= 2;
    }
  }
  if (!flags->sharp_flag && flags->spec == 'p') {
    col_width -= 2;
  }
  for (; col_width > 0; col_width--) {
    step += AddSymToStr(str + step, widht_sym);
  }
  if ((flags->sharp_flag && src[0] != '0') || flags->spec == 'p') {
    if (flags->spec == 'o') {
      step += AddSymToStr(str + step, '0');
    }
    if (flags->spec == 'x' || (flags->spec == 'p' && !flags->zero_flag) ||
        (flags->spec == 'p' && flags->zero_flag && flags->accuracy_flag)) {
      step += AddSymToStr(str + step, '0');
      step += AddSymToStr(str + step, 'x');
    }
    if (flags->spec == 'X') {
      step += AddSymToStr(str + step, '0');
      step += AddSymToStr(str + step, 'X');
    }
  }
  step = Result816(str, src, col_accuracy, col_width, len, step, flag);
  return step;
}

int Result816(char *str, char *src, int col_accuracy, int col_width, int len,
              int step, int flag) {
  if (flag == 0) {
    for (; col_accuracy > 0; col_accuracy--) {
      step += AddSymToStr(str + step, '0');
    }
    for (int i = 0; i < len; i++) {
      step += AddSymToStr(str + step, src[i]);
    }
    for (; col_width > 0; col_width--) {
      step += AddSymToStr(str + step, ' ');
    }
  } else {
    for (; col_accuracy > 0; col_accuracy--) {
      step += AddSymToStr(str + step, '0');
    }
    for (int i = 0; i < len; i++) {
      step += AddSymToStr(str + step, src[i]);
    }
  }
  return step;
}

int Spec_x(Flags *flags, char *buf, int step, va_list ap) {
  long int max_sum = 4294967296;
  if (flags->h_flag) {
    max_sum = 65536;
  }
  if (flags->l_flag) {
    unsigned long int arg = va_arg(ap, long unsigned int);
    if (!(flags->accuracy == 0 && arg == 0)) {
      step += unsigned_long_Parse_o_x_X(flags, buf + step, arg);
    }
  } else {
    long int arg = va_arg(ap, long int);
    if (!(flags->accuracy == 0 && arg == 0)) {
      if (arg < 0) {
        while (arg < 0) {
          arg += max_sum;
        }
        step += long_Parse_o_x_X(flags, buf + step, arg);
      } else {
        while (arg > max_sum) {
          arg -= max_sum;
        }
        step += long_Parse_o_x_X(flags, buf + step, arg);
      }
    }
  }
  return step;
}

int Spec_o(Flags *flags, char *buf, int step, va_list ap) {
  long int max_sum = 4294967296;
  if (flags->h_flag) {
    max_sum = 65536;
  }
  if (flags->l_flag) {
    unsigned long int arg = va_arg(ap, long unsigned int);
    if (!(flags->accuracy == 0 && arg == 0)) {
      step += unsigned_long_Parse_o_x_X(flags, buf + step, arg);
    }
  } else {
    long int arg = va_arg(ap, long int);
    if (!(flags->accuracy == 0 && arg == 0)) {
      if (arg < 0) {
        while (arg < 0) {
          arg += max_sum;
        }
        step += long_Parse_o_x_X(flags, buf + step, arg);
      } else {
        while (arg > max_sum) {
          arg -= max_sum;
        }
        step += long_Parse_o_x_X(flags, buf + step, arg);
      }
    }
  }
  return step;
}

int Spec_P(Flags *flags, char *buf, int step, va_list ap) {
  long unsigned arg = (long unsigned)va_arg(ap, void *);
  step += unsigned_long_Parse_o_x_X(flags, buf + step, arg);
  return step;
}

int G_Parse_e_E(Flags *flags, char *str, long double num) {
  char *pstart = str;
  int acc = flags->accuracy;
  if (acc > 19) acc = 19;

  G_doubleDefineWidAcc(flags);
  if (flags->width_flag) flags->width -= 4;

  int minus = 0;
  if (num < 0) {
    num *= -1;
    minus = 1;
  }
  int step = 0;
  int count_plus = 0;
  if (num >= 10) {
    while (num >= 10) {
      num = num / 10.0;
      count_plus++;
    }
  } else {
    if (num < 1 && num != 0) {
      while (num < 1) {
        num = num * 10;
        count_plus--;
      }
    }
  }
  if (minus) num *= -1;
  int count_minus = count_plus * (-1);

  step += doubleAddFirstSym(flags, str + step, num);
  if (flags->zero_flag && step) pstart++;
  step += integerPartToStr(flags, str + step, num);
  step += G_fractionalPartToStr(flags, str + step, num);
  step += Parse_e_E_end(flags, str + step, count_minus, count_plus);
  step += Parse_double_end(flags, str + step, pstart);
  return step;
}

int Parse_e_E(Flags *flags, char *str, long double num) {
  int step = 0, count_minus = 0, count_plus = 0, len = 0;
  char *pstart = str;
  int flag = 0;

  doubleDefineWidAcc(flags);

  if (flags->width_flag) flags->width -= 4;
  if (num < 0) {
    num *= -1;
    flag = 1;
  }
  if (num >= 10) {
    while (num >= 10) {
      num = num / 10.0;
      len++;
    }
    count_plus = len;
  } else {
    if (num < 1 && num != 0) {
      while (num < 1) {
        num = num * 10;
        count_minus++;
      }
    }
  }
  if (flag == 1) {
    num *= -1;
  }
  step += doubleAddFirstSym(flags, str + step, num);
  if (flags->zero_flag && step) pstart++;
  step += integerPartToStr(flags, str + step, num);
  step += fractionalPartToStr(flags, str + step, num);
  step += Parse_e_E_end(flags, str + step, count_minus, count_plus);
  step += Parse_double_end(flags, str + step, pstart);
  return step;
}

int Parse_e_E_end(Flags *flags, char *str, int count_minus, int count_plus) {
  int step = 0;
  if (flags->spec == 'e' || flags->spec == 'g') {
    step += AddSymToStr(str + step, 'e');
  } else {
    step += AddSymToStr(str + step, 'E');
  }
  if (count_minus > 0) {
    step += AddSymToStr(str + step, '-');
    if (count_minus < 10) {
      step += AddSymToStr(str + step, '0');
      step += IntToStr(str + step, count_minus);
    } else {
      step += IntToStr(str + step, count_minus);
    }
  } else {
    step += AddSymToStr(str + step, '+');
    if (count_plus < 10) {
      step += AddSymToStr(str + step, '0');
      step += IntToStr(str + step, count_plus);
    } else {
      step += IntToStr(str + step, count_plus);
    }
  }
  return step;
}

int Parse_double_end(Flags *flags, char *str, char *pstart) {
  int step = 0;
  char *plastsym = str, *pend = NULL;
  char sym = ' ';
  if (flags->width > 0) {
    pend = str + step - 1;
  }

  int width = flags->width;
  if (flags->zero_flag && !flags->minus_flag) sym = '0';
  for (; width > 0; width--) {
    step += AddSymToStr(str + step, sym);
  }

  if (flags->width > 0 && !flags->minus_flag) {
    plastsym = str + step - 1;
    while (pend >= pstart) {
      *plastsym-- = *pend;
      *pend-- = sym;
    }
  }
  return step;
}

int IntToStr(char *str, int num) {
  int step = 0;
  char *pstart = str;
  do {
    str[step++] = DigitToChar(num % 10);
    num /= 10;
  } while (num != 0);
  for (char *pend = str + step - 1, *plast = pend; pstart < plast;) {
    char c = *pstart;
    *pstart++ = *plast;
    *plast-- = c;
  }
  str[step] = '\0';
  return step;
}

int ParseChar(Flags *flags, char *str, char symbvol) {
  int step = 0;
  char sym = ' ';
  if (flags->minus_flag) {
    step += AddSymToStr(str + step, symbvol);
    flags->width--;
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, sym);
    }
  } else {
    flags->width--;
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, sym);
    }
    step += AddSymToStr(str + step, symbvol);
  }
  return step;
}
int ParseString(Flags *flags, char *str, char *newstr) {
  int step = 0;
  int len = s21_strlen(newstr);
  char sym = ' ';
  if (flags->accuracy != -1 && len > flags->accuracy) {
    len = flags->accuracy;
  }
  if (flags->minus_flag) {
    for (int i = 0; i < len; i++) {
      step += AddSymToStr(str + step, newstr[i]);
    }
    flags->width -= len;
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, sym);
    }
  } else {
    flags->width -= len;
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, sym);
    }
    for (int i = 0; i < len; i++) {
      step += AddSymToStr(str + step, newstr[i]);
    }
  }
  return step;
}

int unsignedLongParseNum(Flags *flags, char *str, unsigned long num) {
  int step = 0;
  char *p = str;

  unsignedLongDefineWidAcc(flags, num);

  if (!flags->minus_flag) {
    char sym = ' ';
    if (flags->zero_flag && !flags->accuracy_flag) sym = '0';
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, sym);
    }
  }

  if (!flags->zero_flag && step) {
    char c = *p;
    *p = str[step - 1];
    str[step - 1] = c;
  }

  for (; flags->accuracy > 0; flags->accuracy--) {
    step += AddSymToStr(str + step, '0');
  }

  step += unsignedLongIntToStr(str + step, num);

  if (flags->minus_flag) {
    for (; flags->width > 0; flags->width--) {
      step += AddSymToStr(str + step, ' ');
    }
  }

  return step;
}

int unsignedLongCheckNumLen(unsigned long num) {
  int length = 1;
  if (num != 0)
    for (length--; num != 0; length++) num /= 10;
  return length;
}

int unsignedLongIntToStr(char *str, unsigned long num) {
  int step = 0;
  char *pstart = str;

  do {
    str[step++] = DigitToChar(num % 10);
    num /= 10;
  } while (num != 0);

  for (char *pend = str + step - 1, *plast = pend; pstart < plast;) {
    char c = *pstart;
    *pstart++ = *plast;
    *plast-- = c;
  }

  str[step] = '\0';
  return step;
}

void unsignedLongDefineWidAcc(Flags *flags, unsigned long num) {
  int standart = 0;
  if (flags->accuracy == -1 || flags->accuracy <= unsignedLongCheckNumLen(num))
    flags->accuracy = standart;

  if (flags->accuracy > unsignedLongCheckNumLen(num))
    flags->accuracy -= unsignedLongCheckNumLen(num);

  flags->width -= (flags->accuracy + unsignedLongCheckNumLen(num));
}
