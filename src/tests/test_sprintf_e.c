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
  len_original = sprintf(original, "%+*e, %-*e, % *e, %0*e, %#*e,", 10, num1,
                         10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+*e, %-*e, % *e, %0*e, %#*e,", 10, num1,
                            10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "%+.*e, %-.*e, % .*e, %0.*e, %#.*e,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "%+.*e, %-.*e, % .*e, %0.*e, %#.*e,", 10,
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
      sprintf(original, "%e, %e, %e, %e, %e,", num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%e, %e, %e, %e, %e,", num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%e, %e, %e, %e, %e,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%e, %e, %e, %e, %e,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(minus_fn) {
  double num1 = -N1;
  double num2 = N2;
  double num3 = N3;
  double num4 = -N10;
  double num5 = -N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%e, %+e, %.0e, %.1e, %10e,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%e, %+e, %.0e, %.1e, %10e,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%+e, %.e, %#.0e, %10.14e, %-10e,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%+e, %.e, %#.0e, %10.14e, %-10e,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(fraction) {
  double num1 = 0.4681;
  double num2 = -0.4681;
  double num3 = 10000000000000.33;
  double num4 = -0.00000000000000000041;
  double num5 = 0.00000874;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+e, %e, %e, %e, %e,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+e, %e, %e, %e, %e,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original =
      sprintf(original, "a%e, %+e, %e, %e, %e,", num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%e, %+e, %e, %e, %e,", num1, num2, num3,
                            num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

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
  len_original = sprintf(original, "%10e, %10e, %10e, %10e, %10e,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10e, %10e, %10e, %10e, %10e,", num1,
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
  len_original = sprintf(original, "%.10e, %.10e, %.10e, %.10e, %.10e,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10e, %.10e, %.10e, %.10e, %.10e,", num1,
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
      sprintf(original, "%10.10e, %10.10e, %10.10e, %10.10e, %10.10e,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10e, %10.10e, %10.10e, %10.10e, %10.10e,", num1,
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
      sprintf(original, "%20.10e, %20.10e, %20.10e, %20.10e, %20.10e,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10e, %20.10e, %20.10e, %20.10e, %20.10e,", num1,
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
      sprintf(original, "%10.20e, %10.20e, %10.20e, %10.20e, %10.19e,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20e, %10.20e, %10.20e, %10.20e, %10.19e,", num1,
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
  len_original = sprintf(original, "%+e, %-e, % e, %#e, %0e,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%+e, %-e, % e, %#e, %0e,", num1, num2,
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
  len_original = sprintf(original, "%+10e, %-10e, % 10e, %#10e, %020e,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10e, %-10e, % 10e, %#10e, %020e,", num1,
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
  len_original = sprintf(original, "%+.10e, %-.10e, % .10e, %#.10e, %0.10e,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+.10e, %-.10e, % .10e, %#.10e, %0.10e,",
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
      sprintf(original, "%+10.10e, %-10.10e, % 10.10e, %#10.10e, %010.10e,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.10e, %-10.10e, % 10.10e, %#10.10e, %010.10e,",
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
      sprintf(original, "%+20.10e, %-20.10e, % 20.10e, %#20.10e, a%020.10e,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+20.10e, %-20.10e, % 20.10e, %#20.10e, a%020.10e,",
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
      sprintf(original, "%+10.20e, %-10.20e, % 10.20e, %#10.20e, %010.20e,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+10.20e, %-10.20e, % 10.20e, %#10.20e, %010.20e,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_e(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("double e");

  dec = tcase_create("\tdouble e\t");
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
  tcase_add_test(dec, minus_fn);
  tcase_add_test(dec, fraction);
  suite_add_tcase(s, dec);

  return s;
}