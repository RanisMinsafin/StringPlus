#include "../s21_string.h"
#include "test.h"

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
  len_original = sprintf(original, "%p, %p, %p, %p, %p,", &num1, &num2, &num3,
                         &num4, &num5);
  len_compare = s21_sprintf(compare, "%p, %p, %p, %p, %p,", &num1, &num2, &num3,
                            &num4, &num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%p, %p, %p, %p, %p,", &num1, &num2, &num3,
                         &num4, &num5);
  len_compare = s21_sprintf(compare, "a%p, %p, %p, %p, %p,", &num1, &num2,
                            &num3, &num4, &num5);
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
  len_original = sprintf(original, "%10p, %10p, %10p, %10p, %10p,", &num1,
                         &num2, &num3, &num4, &num5);
  len_compare = s21_sprintf(compare, "%10p, %10p, %10p, %10p, %10p,", &num1,
                            &num2, &num3, &num4, &num5);
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
  len_original = sprintf(original, "%p, %-p, %p, %p, %p,", &num1, &num2, &num3,
                         &num4, &num5);
  len_compare = s21_sprintf(compare, "%p, %-p, %p, %p, %p,", &num1, &num2,
                            &num3, &num4, &num5);
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
  len_original = sprintf(original, "%10p, %-10p, %10p, %10p, %20p,", &num1,
                         &num2, &num3, &num4, &num5);
  len_compare = s21_sprintf(compare, "%10p, %-10p, %10p, %10p, %20p,", &num1,
                            &num2, &num3, &num4, &num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_p(void) {
  Suite *s;
  TCase *dec;
  s = suite_create("pointer");
  dec = tcase_create("\tpointer\t");
  tcase_add_test(dec, no_flags);
  tcase_add_test(dec, wid);
  tcase_add_test(dec, flags);
  tcase_add_test(dec, flags_wid);
  suite_add_tcase(s, dec);

  return s;
}
