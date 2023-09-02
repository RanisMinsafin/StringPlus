#include "../s21_string.h"
#include "test.h"

START_TEST(no_flags) {
  char num1 = N2;
  char num2 = N13;
  char num3 = N16;
  char num4 = N17;
  char num5 = N18;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%c, %c, %c, %c, %c,", num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%c, %c, %c, %c, %c,", num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%c, %c, %c, %c, %c,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%c, %c, %c, %c, %c,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  char num1 = N2;
  char num2 = N13;
  char num3 = N16;
  char num4 = N17;
  char num5 = N18;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10c, %10c, %10c, %10c, %10c,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10c, %10c, %10c, %10c, %10c,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  char num1 = N2;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%-c", num1);
  len_compare = s21_sprintf(compare, "%-c", num1);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  char num1 = N2;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%-10c", num1);
  len_compare = s21_sprintf(compare, "%-10c", num1);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_c(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("char");

  dec = tcase_create("\tchar\t");
  tcase_add_test(dec, no_flags);
  tcase_add_test(dec, wid);
  tcase_add_test(dec, flags);
  tcase_add_test(dec, flags_wid);
  suite_add_tcase(s, dec);

  return s;
}
