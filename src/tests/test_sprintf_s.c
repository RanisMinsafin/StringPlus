#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%*s, %-*s, %*s, %*s, %*s,", 10, num1, 10,
                         num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%*s, %-*s, %*s, %*s, %*s,", 10, num1, 10,
                            num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%.*s, %-.*s, %.*s, %.*s, %.*s,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%.*s, %.*s, %.*s, %.*s, %.*s,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%s, %s, %s, %s, %s,", num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%s, %s, %s, %s, %s,", num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%s, %s, %s, %s, %s,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%s, %s, %s, %s, %s,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10s, %10s, %10s, %10s, %10s,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10s, %10s, %10s, %10s, %10s,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10s, %.10s, %.10s, %.10s, %.10s,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10s, %.10s, %.10s, %.10s, %.10s,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10s, %10.10s, %10.10s, %10.10s, %10.10s,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10s, %10.10s, %10.10s, %10.10s, %10.10s,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10s, %20.10s, %20.10s, %20.10s, %20.10s,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10s, %20.10s, %20.10s, %20.10s, %20.10s,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20s, %10.20s, %10.20s, %10.20s, %10.20s,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20s, %10.20s, %10.20s, %10.20s, %10.20s,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%s, %-s, %s, %s, %s,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%s, %-s, %s, %s, %s,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10s, %-10s, %10s, %10s, %20s,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10s, %-10s, %10s, %10s, %20s,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10s, %-.10s, %.10s, %.10s, %.10s,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10s, %-.10s, %.10s, %.10s, %.10s,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10s, %-10.10s, %10.10s, %10.10s, %10.10s,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10s, %-10.10s, %10.10s, %10.10s, %10.10s,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10s, %-20.10s, %20.10s, %20.10s, a%20.10s,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10s, %-20.10s, %20.10s, %20.10s, a%20.10s,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  char num1[6] = {"hello"};
  char num2[6] = {"he\0ll"};
  char num3[6] = {"hel\n"};
  char num4[6] = {"h\t"};
  char num5[6] = {""};
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20s, %-10.20s, %10.20s, %10.20s, %10.20s,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20s, %-10.20s, %10.20s, %10.20s, %10.20s,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite* suit_sprintf_s(void) {
  Suite* s;
  TCase* dec;

  s = suite_create("string");

  dec = tcase_create("\tstring\t");
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
