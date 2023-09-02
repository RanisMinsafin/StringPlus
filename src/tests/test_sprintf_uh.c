#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%*hu, %-*hu, %*hu, %*hu, %*hu,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%*hu, %-*hu, %*hu, %*hu, %*hu,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%.*hu, %-.*hu, %.*hu, %.*hu, %.*hu,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%.*hu, %-.*hu, %.*hu, %.*hu, %.*hu,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.0hu, %.0hu, %.0hu, %.0hu, %.0hu,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.0hu, %.0hu, %.0hu, %.0hu, %.0hu,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%hu, %hu, %hu, %hu, %hu,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%hu, %hu, %hu, %hu, %hu,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10hu, %10hu, %10hu, %10hu, %10hu,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10hu, %10hu, %10hu, %10hu, %10hu,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10hu, %.10hu, %.10hu, %.10hu, %.10hu,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10hu, %.10hu, %.10hu, %.10hu, %.10hu,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10hu, %10.10hu, %10.10hu, %10.10hu, %10.10hu,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10hu, %10.10hu, %10.10hu, %10.10hu, %10.10hu,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10hu, %20.10hu, %20.10hu, %20.10hu, %20.10hu,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10hu, %20.10hu, %20.10hu, %20.10hu, %20.10hu,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20hu, %10.20hu, %10.20hu, %10.20hu, %10.20hu,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20hu, %10.20hu, %10.20hu, %10.20hu, %10.20hu,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%hu, %-hu, %hu, %hu, %hu,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%hu, %-hu, %hu, %hu, %hu,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10hu, %-10hu, %10hu, %10hu, %20hu,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10hu, %-10hu, %10hu, %10hu, %20hu,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10hu, %-.10hu, %.10hu, %.10hu, %.10hu,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10hu, %-.10hu, %.10hu, %.10hu, %.10hu,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10hu, %-10.10hu, %10.10hu, %10.10hu, %10.10hu,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10hu, %-10.10hu, %10.10hu, %10.10hu, %10.10hu,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10hu, %-20.10hu, %20.10hu, %20.10hu, a%20.10hu,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%20.10hu, %-20.10hu, %20.10hu, %20.10hu, a%20.10hu,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  short unsigned num1 = N1;
  short unsigned num2 = N2;
  short unsigned num3 = N33;
  short unsigned num4 = N14;
  short unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20hu, %-10.20hu, %10.20hu, %10.20hu, %10.20hu,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20hu, %-10.20hu, %10.20hu, %10.20hu, %10.20hu,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_hu(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("unsidned h");

  dec = tcase_create("\tunsigned_h\t");
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