#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "a%+*LE, %-*LE, % *LE, %0*LE, %#*LE,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "a%+*LE, %-*LE, % *LE, %0*LE, %#*LE,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%+.*LE, %-.*LE, % .*LE, %0.*LE, %#.*LE,",
                         10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "b%+.*LE, %-.*LE, % .*LE, %0.*LE, %#.*LE,",
                            10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%LE, %LE, %LE, %LE, %LE,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%LE, %LE, %LE, %LE, %LE,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%LE, %LE, %LE, %LE, %LE,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%LE, %LE, %LE, %LE, %LE,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(minus_fn) {
  long double num1 = -N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = -N10;
  long double num5 = -N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%LE, %+LE, %.0LE, %.1LE, %10LE,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%LE, %+LE, %.0LE, %.1LE, %10LE,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%+LE, %.LE, %#.0LE, %10.14LE, %-10LE,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%+LE, %.LE, %#.0LE, %10.14LE, %-10LE,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST
START_TEST(fraction) {
  long double num1 = 0.4681;
  long double num2 = -0.4681;
  long double num3 = 0.0000041;
  long double num4 = -0.000041;
  long double num5 = 0.00000874;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+LE, %LE, %LE, %LE, %LE,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+LE, %LE, %LE, %LE, %LE,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%LE, %+LE, %LE, %LE, %LE,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%LE, %+LE, %LE, %LE, %LE,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10LE, %10LE, %10LE, %10LE, %10LE,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10LE, %10LE, %10LE, %10LE, %10LE,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10LE, %.10LE, %.10LE, %.10LE, %.10LE,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10LE, %.10LE, %.10LE, %.10LE, %.10LE,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10LE, %10.10LE, %10.10LE, %10.10LE, %10.10LE,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10LE, %10.10LE, %10.10LE, %10.10LE, %10.10LE,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10LE, %20.10LE, %20.10LE, %20.10LE, %20.10LE,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10LE, %20.10LE, %20.10LE, %20.10LE, %20.10LE,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20LE, %10.20LE, %10.20LE, %10.20LE, %10.20LE,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20LE, %10.20LE, %10.20LE, %10.20LE, %10.20LE,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+LE, %-LE, % LE, %#LE, %0LE,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+LE, %-LE, % LE, %#LE, %0LE,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+10LE, %-10LE, % 10LE, %#10LE, %020LE,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10LE, %-10LE, % 10LE, %#10LE, %020LE,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+.10LE, %-.10LE, % .10LE, %#.10LE, %0.10LE,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10LE, %-.10LE, % .10LE, %#.10LE, %0.10LE,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%+10.10LE, %-10.10LE, % 10.10LE, %#10.10LE, %010.10LE,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10LE, %-10.10LE, % 10.10LE, %#10.10LE, %010.10LE,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%+20.10LE, %-20.10LE, % 20.10LE, %#20.10LE, a%020.10LE,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10LE, %-20.10LE, % 20.10LE, %#20.10LE, a%020.10LE,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%+10.20LE, %-10.20LE, % 10.20LE, %#10.20LE, %010.20LE,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20LE, %-10.20LE, % 10.20LE, %#10.20LE, %010.20LE,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_LE(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("double EL");

  dec = tcase_create("\tdouble_EL\t");
  tcase_add_test(dec, stars);
  tcase_add_test(dec, no_flags);
  tcase_add_test(dec, wid);
  tcase_add_test(dec, acc);
  tcase_add_test(dec, wa);
  tcase_add_test(dec, Wa);
  tcase_add_test(dec, wA);
  tcase_add_test(dec, flags);
  tcase_add_test(dec, flags_wid);
  tcase_add_test(dec, flags_acc);
  tcase_add_test(dec, flags_wa);
  tcase_add_test(dec, flags_Wa);
  tcase_add_test(dec, flags_wA);
  tcase_add_test(dec, minus_fn);
  tcase_add_test(dec, fraction);
  suite_add_tcase(s, dec);

  return s;
}