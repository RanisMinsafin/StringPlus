#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "a%*o, %-*o, %*o, %-#*o, %#*o,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "a%*o, %-*o, %*o, %-#*o, %#*o,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%.*o, %-.*o, %.*o, %-#.*o, %#.*o,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "b%.*o, %-.*o, %.*o, %-#.*o, %#.*o,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.0o, %.0o, %.0o, %.0o, %.0o,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.0o, %.0o, %.0o, %.0o, %.0o,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%o, %o, %o, %o, %o,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%o, %o, %o, %o, %o,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10o, %10o, %10o, %10o, %10o,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10o, %10o, %10o, %10o, %10o,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10o, %.10o, %.10o, %.10o, %.10o,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10o, %.10o, %.10o, %.10o, %.10o,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10o, %10.10o, %10.10o, %10.10o, %10.10o,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10o, %10.10o, %10.10o, %10.10o, %10.10o,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10o, %20.10o, %20.10o, %20.10o, %20.10o,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10o, %20.10o, %20.10o, %20.10o, %20.10o,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20o, %10.20o, %10.20o, %10.20o, %10.20o,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20o, %10.20o, %10.20o, %10.20o, %10.20o,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%o, %-o, %o, %#o, %-#o,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%o, %-o, %o, %#o, %-#o,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10o, %-10o, %10o, %#10o, %-#20o,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10o, %-10o, %10o, %#10o, %-#20o,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10o, %-.10o, %.10o, %#.10o, %-#.10o,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10o, %-.10o, %.10o, %#.10o, %-#.10o,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10o, %-10.10o, %10.10o, %#10.10o, %-#10.10o,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10o, %-10.10o, %10.10o, %#10.10o, %-#10.10o,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10o, %-20.10o, %20.10o, %#20.10o, a%-#20.10o,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10o, %-20.10o, %20.10o, %#20.10o, a%-#20.10o,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  unsigned num1 = N1;
  unsigned num2 = N2;
  unsigned num3 = N33;
  unsigned num4 = N12;
  unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20o, %-10.20o, %10.20o, %#10.20o, %-#10.20o,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20o, %-10.20o, %10.20o, %#10.20o, %-#10.20o,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_minuscount) {
  int num1 = -1;
  int num2 = -10;
  int num3 = -100;
  int num4 = -1000;
  int num5 = -10000;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20o, %-10.20o, %10.20o, %#10.20o, %-#10.20o,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20o, %-10.20o, %10.20o, %#10.20o, %-#10.20o,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST
Suite *suit_sprintf_o(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("octal");

  dec = tcase_create("\toctal\t");
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
  tcase_add_test(dec, flags_minuscount);
  suite_add_tcase(s, dec);

  return s;
}
