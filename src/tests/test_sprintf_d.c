#include "../s21_sprintf.h"
#include "test.h"

START_TEST(stars) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+*d, %-*d, % *d, %0*d, %*d,", 10, num1, 10,
                         num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*d, %-*d, % *d, %0*d, %*d,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*d, %-.*d, % .*d, %.*d, %.*d,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*d, %-.*d, % .*d, %.*d, %.*d,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "a%.0d, a%.0d, a%.0d, a%.0d, a%.0d,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%.0d, a%.0d, a%.0d, a%.0d, a%.0d,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%+.0d, %-.0d, %d, %d, %d,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "b%+.0d, %-.0d, %d, %d, %d,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10d, %10d, %10d, %10d, %10d,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10d, %10d, %10d, %10d, %10d,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10d, %.10d, %.10d, %.10d, %.10d,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10d, %.10d, %.10d, %.10d, %.10d,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10d, %10.10d, %10.10d, %10.10d, %10.10d,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10d, %10.10d, %10.10d, %10.10d, %10.10d,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10d, %20.10d, %20.10d, %20.10d, %20.10d,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10d, %20.10d, %20.10d, %20.10d, %20.10d,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20d, %10.20d, %10.20d, %10.20d, %10.20d,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20d, %10.20d, %10.20d, %10.20d, %10.20d,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+d, %-d, % d, %d, %0d,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%+d, %-d, % d, %d, %0d,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+10d, %-10d, % 10d, %10d, %020d,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10d, %-10d, % 10d, %10d, %020d,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+.10d, %-.10d, % .10d, %.10d, %.10d,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+.10d, %-.10d, % .10d, %.10d, %.10d,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.10d, %-10.10d, % 10.10d, %10.10d, %10.10d,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.10d, %-10.10d, % 10.10d, %10.10d, %10.10d,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+20.10d, %-20.10d, % 20.10d, %20.10d, a%20.10d,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+20.10d, %-20.10d, % 20.10d, %20.10d, a%20.10d,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.20d, %-10.20d, % 10.20d, %10.20d, %10.20d,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.20d, %-10.20d, % 10.20d, %10.20d, %10.20d,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_d(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("decimal d");

  dec = tcase_create("\tdecimal\t");
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