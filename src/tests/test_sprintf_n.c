#include "../s21_string.h"
#include "test.h"

START_TEST(no_flags) {
  int num1 = N1;
  int num2 = N2;
  int num3 = N3;
  int num4 = N4;
  int num5 = N5;
  int n1 = 1933;
  int n2 = 1933;
  int n3 = 1933;
  int n4 = 1933;
  int n5 = 1933;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%n, a%n, a%n, a%n, a%n,", &num1, &num2,
                         &num3, &num4, &num5);
  len_compare =
      s21_sprintf(compare, "%n, a%n, a%n, a%n, a%n,", &n1, &n2, &n3, &n4, &n5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(num1, n1);
  ck_assert_int_eq(num2, n2);
  ck_assert_int_eq(num3, n3);
  ck_assert_int_eq(num4, n4);
  ck_assert_int_eq(num5, n5);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%n, a%n, a%n, a%n, a%n,", &num1, &num2,
                         &num3, &num4, &num5);
  len_compare =
      s21_sprintf(compare, "a%n, a%n, a%n, a%n, a%n,", &n1, &n2, &n3, &n4, &n5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(num1, n1);
  ck_assert_int_eq(num2, n2);
  ck_assert_int_eq(num3, n3);
  ck_assert_int_eq(num4, n4);
  ck_assert_int_eq(num5, n5);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_n(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("length");

  dec = tcase_create("\tlength\t");
  tcase_add_test(dec, no_flags);
  suite_add_tcase(s, dec);

  return s;
}
