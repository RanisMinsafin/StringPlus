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
  len_original = sprintf(original, "a%+*LG, %-*LG, % *LG, %0*LG, %#*LG,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "a%+*LG, %-*LG, % *LG, %0*LG, %#*LG,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%+.*LG, %-.*LG, % .*LG, %0.*LG, %#.*LG,",
                         10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "b%+.*LG, %-.*LG, % .*LG, %0.*LG, %#.*LG,",
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
  len_original = sprintf(original, "%LG, %LG, %LG, %LG, %LG,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%LG, %LG, %LG, %LG, %LG,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%LG, %LG, %LG, %LG, %LG,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%LG, %LG, %LG, %LG, %LG,", num1, num2,
                            num3, num4, num5);
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
  len_original = sprintf(original, "%.0LG, %10.5LG, %LG, %.1LG, %LG,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.0LG, %10.5LG, %LG, %.1LG, %LG,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%+LG, %+15LG, %-10LG, %.10LG, %010LG,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%+LG, %+15LG, %-10LG, %.10LG, %010LG,",
                            num1, num2, num3, num4, num5);
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
  len_original = sprintf(original, "%10LG, %10LG, %10LG, %10LG, %10LG,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10LG, %10LG, %10LG, %10LG, %10LG,", num1,
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
  len_original = sprintf(original, "%.10LG, %.10LG, %.10LG, %.10LG, %.10LG,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10LG, %.10LG, %.10LG, %.10LG, %.10LG,",
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
      sprintf(original, "%10.10LG, %10.10LG, %10.10LG, %10.10LG, %10.10LG,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10LG, %10.10LG, %10.10LG, %10.10LG, %10.10LG,",
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
      sprintf(original, "%20.10LG, %20.10LG, %20.10LG, %20.10LG, %20.10LG,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10LG, %20.10LG, %20.10LG, %20.10LG, %20.10LG,",
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
      sprintf(original, "%10.20LG, %10.20LG, %10.20LG, %10.20LG, %10.20LG,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20LG, %10.20LG, %10.20LG, %10.20LG, %10.20LG,",
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
  len_original = sprintf(original, "%+LG, %-LG, % LG, %#LG, %0LG,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+LG, %-LG, % LG, %#LG, %0LG,", num1,
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
  len_original = sprintf(original, "%+10LG, %-10LG, % 10LG, %#10LG, %020LG,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10LG, %-10LG, % 10LG, %#10LG, %020LG,",
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
      sprintf(original, "%+.10LG, %-.10LG, % .10LG, %#.10LG, %0.10LG,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10LG, %-.10LG, % .10LG, %#.10LG, %0.10LG,", num1,
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
      original, "%+10.10LG, %-10.10LG, % 10.10LG, %#10.10LG, %010.10LG,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10LG, %-10.10LG, % 10.10LG, %#10.10LG, %010.10LG,", num1,
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
      original, "%+20.10LG, %-20.10LG, % 20.10LG, %#20.10LG, a%020.10LG,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10LG, %-20.10LG, % 20.10LG, %#20.10LG, a%020.10LG,", num1,
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
      original, "%+10.20LG, %-10.20LG, % 10.20LG, %#10.20LG, %010.20LG,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20LG, %-10.20LG, % 10.20LG, %#10.20LG, %010.20LG,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_LG(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("double LG");

  dec = tcase_create("\tdouble_LG\t");
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
  tcase_add_test(dec, fraction);
  suite_add_tcase(s, dec);

  return s;
}