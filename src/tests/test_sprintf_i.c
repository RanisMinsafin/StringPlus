#include "../s21_string.h"
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
  len_original = sprintf(original, "%+*i, %-*i, % *i, %0*i, %*i,", 10, num1, 10,
                         num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*i, %-*i, % *i, %0*i, %*i,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*i, %-.*i, % .*i, %.*i, %.*i,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*i, %-.*i, % .*i, %.*i, %.*i,", 10,
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
  len_original =
      sprintf(original, "%i, %i, %i, %i, %i,", num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%i, %i, %i, %i, %i,", num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%i, %i, %i, %i, %i,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%i, %i, %i, %i, %i,", num1, num2, num3,
                            num4, num5);
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
  len_original = sprintf(original, "%10i, %10i, %10i, %10i, %10i,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10i, %10i, %10i, %10i, %10i,", num1,
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
  len_original = sprintf(original, "%.10i, %.10i, %.10i, %.10i, %.10i,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10i, %.10i, %.10i, %.10i, %.10i,", num1,
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
      sprintf(original, "%10.10i, %10.10i, %10.10i, %10.10i, %10.10i,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10i, %10.10i, %10.10i, %10.10i, %10.10i,", num1,
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
      sprintf(original, "%20.10i, %20.10i, %20.10i, %20.10i, %20.10i,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10i, %20.10i, %20.10i, %20.10i, %20.10i,", num1,
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
      sprintf(original, "%10.20i, %10.20i, %10.20i, %10.20i, %10.20i,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20i, %10.20i, %10.20i, %10.20i, %10.20i,", num1,
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
  len_original = sprintf(original, "%+i, %-i, % i, %i, %0i,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%+i, %-i, % i, %i, %0i,", num1, num2,
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
  len_original = sprintf(original, "%+10i, %-10i, % 10i, %10i, %020i,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10i, %-10i, % 10i, %10i, %020i,", num1,
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
  len_original = sprintf(original, "%+.10i, %-.10i, % .10i, %.10i, %.10i,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+.10i, %-.10i, % .10i, %.10i, %.10i,",
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
      sprintf(original, "%+10.10i, %-10.10i, % 10.10i, %10.10i, %10.10i,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.10i, %-10.10i, % 10.10i, %10.10i, %10.10i,",
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
      sprintf(original, "%+20.10i, %-20.10i, % 20.10i, %20.10i, a%20.10i,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+20.10i, %-20.10i, % 20.10i, %20.10i, a%20.10i,",
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
      sprintf(original, "%+10.20i, %-10.20i, % 10.20i, %10.20i, %10.20i,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.20i, %-10.20i, % 10.20i, %10.20i, %10.20i,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_i(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("decimal i");

  dec = tcase_create("\tdecimal_i\t");
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