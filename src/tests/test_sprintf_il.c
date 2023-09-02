#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+*li, %-*li, % *li, %0*li, %*li,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*li, %-*li, % *li, %0*li, %*li,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*li, %-.*li, % .*li, %.*li, %.*li,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*li, %-.*li, % .*li, %.*li, %.*li,",
                            10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%li, %li, %li, %li, %li,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%li, %li, %li, %li, %li,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%li, %li, %li, %li, %li,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%li, %li, %li, %li, %li,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10li, %10li, %10li, %10li, %10li,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10li, %10li, %10li, %10li, %10li,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10li, %.10li, %.10li, %.10li, %.10li,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10li, %.10li, %.10li, %.10li, %.10li,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10li, %10.10li, %10.10li, %10.10li, %10.10li,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10li, %10.10li, %10.10li, %10.10li, %10.10li,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10li, %20.10li, %20.10li, %20.10li, %20.10li,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10li, %20.10li, %20.10li, %20.10li, %20.10li,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20li, %10.20li, %10.20li, %10.20li, %10.20li,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20li, %10.20li, %10.20li, %10.20li, %10.20li,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+li, %-li, % li, %li, %0li,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+li, %-li, % li, %li, %0li,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+10li, %-10li, % 10li, %10li, %020li,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10li, %-10li, % 10li, %10li, %020li,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+.10li, %-.10li, % .10li, %.10li, %.10li,",
                         num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10li, %-.10li, % .10li, %.10li, %.10li,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.10li, %-10.10li, % 10.10li, %10.10li, %10.10li,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10li, %-10.10li, % 10.10li, %10.10li, %10.10li,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+20.10li, %-20.10li, % 20.10li, %20.10li, a%20.10li,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10li, %-20.10li, % 20.10li, %20.10li, a%20.10li,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  long num1 = N1;
  long num2 = N2;
  long num3 = N3;
  long num4 = N8;
  long num5 = N9;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.20li, %-10.20li, % 10.20li, %10.20li, %10.20li,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20li, %-10.20li, % 10.20li, %10.20li, %10.20li,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_li(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("decimal li");

  dec = tcase_create("\tdecimal_li\t");
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
  suite_add_tcase(s, dec);

  return s;
}