#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+*G, %-*G, % *G, %0*G, %#*G,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*G, %-*G, % *G, %0*G, %#*G,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*G, %-.*G, % .*G, %0.*G, %#.*G,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*G, %-.*G, % .*G, %0.*G, %#.*G,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%G, %G, %G, %G, %G,", num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%G, %G, %G, %G, %G,", num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%G, %G, %G, %G, %G,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%G, %G, %G, %G, %G,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(fraction) {
  double num1 = 0.4681;
  double num2 = -0.4681;
  double num3 = 0.0000041;
  double num4 = -0.000041;
  double num5 = 0.00000874;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.0G, %10.5G, %G, %.1G, %G,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.0G, %10.5G, %G, %.1G, %G,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%+G, %+G, %-10G, %.10G, %010G,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%+G, %+G, %-10G, %.10G, %010G,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10G, %10G, %10G, %10G, %10G,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10G, %10G, %10G, %10G, %10G,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10G, %.10G, %.10G, %.10G, %.10G,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10G, %.10G, %.10G, %.10G, %.10G,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10G, %10.10G, %10.10G, %10.10G, %10.10G,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10G, %10.10G, %10.10G, %10.10G, %10.10G,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10G, %20.10G, %20.10G, %20.10G, %20.10G,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10G, %20.10G, %20.10G, %20.10G, %20.10G,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20G, %10.20G, %10.20G, %10.20G, %10.20G,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20G, %10.20G, %10.20G, %10.20G, %10.20G,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+G, %-G, % G, %#G, %0G,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%+G, %-G, % G, %#G, %0G,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+10G, %-10G, % 10G, %#10G, %020G,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10G, %-10G, % 10G, %#10G, %020G,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+.10G, %-.10G, % .10G, %#.10G, %0.10G,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+.10G, %-.10G, % .10G, %#.10G, %0.10G,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.10G, %-10.10G, % 10.10G, %#10.10G, %010.10G,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.10G, %-10.10G, % 10.10G, %#10.10G, %010.10G,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+20.10G, %-20.10G, % 20.10G, %#20.10G, a%020.10G,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+20.10G, %-20.10G, % 20.10G, %#20.10G, a%020.10G,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  double num1 = N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = N10;
  double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+10.20G, %-10.20G, % 10.20G, %#10.20G, %010.20G,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.20G, %-10.20G, % 10.20G, %#10.20G, %010.20G,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_G(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("double G");

  dec = tcase_create("\tdouble_G\t");
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