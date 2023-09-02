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
  len_original = sprintf(original, "%+*ld, %-*ld, % *ld, %0*ld, %*ld,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*ld, %-*ld, % *ld, %0*ld, %*ld,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*ld, %-.*ld, % .*ld, %.*ld, %.*ld,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*ld, %-.*ld, % .*ld, %.*ld, %.*ld,",
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
  len_original = sprintf(original, "%.0ld, %.0ld, %.0ld, %.0ld, %.0ld,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.0ld, %.0ld, %.0ld, %.0ld, %.0ld,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%ld, %ld, %ld, %ld, %ld,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%ld, %ld, %ld, %ld, %ld,", num1, num2,
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
  len_original = sprintf(original, "%10ld, %10ld, %10ld, %10ld, %10ld,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10ld, %10ld, %10ld, %10ld, %10ld,", num1,
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
  len_original = sprintf(original, "%.10ld, %.10ld, %.10ld, %.10ld, %.10ld,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10ld, %.10ld, %.10ld, %.10ld, %.10ld,",
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
      sprintf(original, "%10.10ld, %10.10ld, %10.10ld, %10.10ld, %10.10ld,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10ld, %10.10ld, %10.10ld, %10.10ld, %10.10ld,",
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
      sprintf(original, "%20.10ld, %20.10ld, %20.10ld, %20.10ld, %20.10ld,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10ld, %20.10ld, %20.10ld, %20.10ld, %20.10ld,",
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
      sprintf(original, "%10.20ld, %10.20ld, %10.20ld, %10.20ld, %10.20ld,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20ld, %10.20ld, %10.20ld, %10.20ld, %10.20ld,",
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
  len_original = sprintf(original, "%+ld, %-ld, % ld, %ld, %0ld,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+ld, %-ld, % ld, %ld, %0ld,", num1, num2,
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
  len_original = sprintf(original, "%+10ld, %-10ld, % 10ld, %10ld, %020ld,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10ld, %-10ld, % 10ld, %10ld, %020ld,",
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
  len_original = sprintf(original, "%+.10ld, %-.10ld, % .10ld, %.10ld, %.10ld,",
                         num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10ld, %-.10ld, % .10ld, %.10ld, %.10ld,", num1,
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
      sprintf(original, "%+10.10ld, %-10.10ld, % 10.10ld, %10.10ld, %10.10ld,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10ld, %-10.10ld, % 10.10ld, %10.10ld, %10.10ld,", num1,
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
      sprintf(original, "%+20.10ld, %-20.10ld, % 20.10ld, %20.10ld, a%20.10ld,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10ld, %-20.10ld, % 20.10ld, %20.10ld, a%20.10ld,", num1,
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
      sprintf(original, "%+10.20ld, %-10.20ld, % 10.20ld, %10.20ld, %10.20ld,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20ld, %-10.20ld, % 10.20ld, %10.20ld, %10.20ld,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_ld(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("decimal ld");

  dec = tcase_create("\tdecimal_l\t");
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