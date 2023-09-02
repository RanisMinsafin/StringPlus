#include "../s21_string.h"
#include "test.h"

START_TEST(no_flags) {
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%%, %%, %%, %%, %%,");
  len_compare = s21_sprintf(compare, "%%, %%, %%, %%, %%,");
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%%, %%, %%, %%, %%,");
  len_compare = s21_sprintf(compare, "a%%, %%, %%, %%, %%,");
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_prc(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("prc");
  dec = tcase_create("\tprc\t");
  tcase_add_test(dec, no_flags);
  suite_add_tcase(s, dec);

  return s;
}
