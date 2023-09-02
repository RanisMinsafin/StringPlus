#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+*hi, %-*hi, % *hi, %0*hi, %*hi,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*hi, %-*hi, % *hi, %0*hi, %*hi,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*hi, %-.*hi, % .*hi, %.*hi, %.*hi,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*hi, %-.*hi, % .*hi, %.*hi, %.*hi,",
                            10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%hi, %hi, %hi, %hi, %hi,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%hi, %hi, %hi, %hi, %hi,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%hi, %hi, %hi, %hi, %hi,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%hi, %hi, %hi, %hi, %hi,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10hi, %10hi, %10hi, %10hi, %10hi,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10hi, %10hi, %10hi, %10hi, %10hi,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10hi, %.10hi, %.10hi, %.10hi, %.10hi,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10hi, %.10hi, %.10hi, %.10hi, %.10hi,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10hi, %10.10hi, %10.10hi, %10.10hi, %10.10hi,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10hi, %10.10hi, %10.10hi, %10.10hi, %10.10hi,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10hi, %20.10hi, %20.10hi, %20.10hi, %20.10hi,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10hi, %20.10hi, %20.10hi, %20.10hi, %20.10hi,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20hi, %10.20hi, %10.20hi, %10.20hi, %10.20hi,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20hi, %10.20hi, %10.20hi, %10.20hi, %10.20hi,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+hi, %-hi, % hi, %hi, %0hi,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+hi, %-hi, % hi, %hi, %0hi,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+10hi, %-10hi, % 10hi, %10hi, %020hi,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10hi, %-10hi, % 10hi, %10hi, %020hi,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+.10hi, %-.10hi, % .10hi, %.10hi, %.10hi,",
                         num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10hi, %-.10hi, % .10hi, %.10hi, %.10hi,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.10hi, %-10.10hi, % 10.10hi, %10.10hi, %10.10hi,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10hi, %-10.10hi, % 10.10hi, %10.10hi, %10.10hi,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+20.10hi, %-20.10hi, % 20.10hi, %20.10hi, a%20.10hi,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10hi, %-20.10hi, % 20.10hi, %20.10hi, a%20.10hi,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  short num1 = N1;
  short num2 = N2;
  short num3 = N3;
  short num4 = N6;
  short num5 = N7;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.20hi, %-10.20hi, % 10.20hi, %10.20hi, %10.20hi,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20hi, %-10.20hi, % 10.20hi, %10.20hi, %10.20hi,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_hi(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("decimal hi");

  dec = tcase_create("\tdecimal_hi\t");
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