#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "a%+*Le, %-*Le, % *Le, %0*Le, %#*Le,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "a%+*Le, %-*Le, % *Le, %0*Le, %#*Le,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%+.*Le, %-.*Le, % .*Le, %0.*Le, %#.*Le,",
                         10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "b%+.*Le, %-.*Le, % .*Le, %0.*Le, %#.*Le,",
                            10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%Le, %Le, %Le, %Le, %Le,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%Le, %Le, %Le, %Le, %Le,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%Le, %Le, %Le, %Le, %Le,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%Le, %Le, %Le, %Le, %Le,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST
START_TEST(minus_fn) {
  long double num1 = -N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = -N10;
  long double num5 = -N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%Le, %+Le, %.0Le, %.1Le, %10Le,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%Le, %+Le, %.0Le, %.1Le, %10Le,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%+Le, %.Le, %#.0Le, %10.14Le, %-10Le,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%+Le, %.Le, %#.0Le, %10.14Le, %-10Le,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}

START_TEST(fraction) {
  long double num1 = 0.4681;
  long double num2 = -0.4681;
  long double num3 = 0.0000041;
  long double num4 = -0.000041;
  long double num5 = 0.00000874;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+Le, %Le, %Le, %Le, %Le,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+Le, %Le, %Le, %Le, %Le,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%Le, %+Le, %Le, %Le, %Le,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%Le, %+Le, %Le, %Le, %Le,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST
START_TEST(wid) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10Le, %10Le, %10Le, %10Le, %10Le,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10Le, %10Le, %10Le, %10Le, %10Le,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10Le, %.10Le, %.10Le, %.10Le, %.10Le,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10Le, %.10Le, %.10Le, %.10Le, %.10Le,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10Le, %10.10Le, %10.10Le, %10.10Le, %10.10Le,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10Le, %10.10Le, %10.10Le, %10.10Le, %10.10Le,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10Le, %20.10Le, %20.10Le, %20.10Le, %20.10Le,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10Le, %20.10Le, %20.10Le, %20.10Le, %20.10Le,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20Le, %10.20Le, %10.20Le, %10.20Le, %10.20Le,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20Le, %10.20Le, %10.20Le, %10.20Le, %10.20Le,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+Le, %-Le, % Le, %#Le, %0Le,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+Le, %-Le, % Le, %#Le, %0Le,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%+10Le, %-10Le, % 10Le, %#10Le, %020Le,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10Le, %-10Le, % 10Le, %#10Le, %020Le,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%+.10Le, %-.10Le, % .10Le, %#.10Le, %0.10Le,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10Le, %-.10Le, % .10Le, %#.10Le, %0.10Le,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%+10.10Le, %-10.10Le, % 10.10Le, %#10.10Le, %010.10Le,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10Le, %-10.10Le, % 10.10Le, %#10.10Le, %010.10Le,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%+20.10Le, %-20.10Le, % 20.10Le, %#20.10Le, a%020.10Le,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10Le, %-20.10Le, % 20.10Le, %#20.10Le, a%020.10Le,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  long double num1 = N1;
  long double num2 = N2;
  long double num3 = N3;
  long double num4 = N10;
  long double num5 = N11;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%+10.20Le, %-10.20Le, % 10.20Le, %#10.20Le, %010.20Le,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20Le, %-10.20Le, % 10.20Le, %#10.20Le, %010.20Le,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_Le(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("double Le");

  dec = tcase_create("\tdouble_Le\t");
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