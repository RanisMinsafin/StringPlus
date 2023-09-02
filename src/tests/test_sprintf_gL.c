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
  len_original = sprintf(original, "a%+*Lg, %-*Lg, % *Lg, %0*Lg, %#*Lg,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "a%+*Lg, %-*Lg, % *Lg, %0*Lg, %#*Lg,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%+.*Lg, %-.*Lg, % .*Lg, %0.*Lg, %#.*Lg,",
                         10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "b%+.*Lg, %-.*Lg, % .*Lg, %0.*Lg, %#.*Lg,",
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
  len_original = sprintf(original, "%Lg, %Lg, %Lg, %Lg, %Lg,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%Lg, %Lg, %Lg, %Lg, %Lg,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%Lg, %Lg, %Lg, %Lg, %Lg,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%Lg, %Lg, %Lg, %Lg, %Lg,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

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
  len_original = sprintf(original, "%.0Lg, %10.5Lg, %Lg, %.1Lg, %Lg,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.0Lg, %10.5Lg, %Lg, %.1Lg, %Lg,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%+Lg, %+15Lg, %-10Lg, %.10Lg, %010Lg,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%+Lg, %+15Lg, %-10Lg, %.10Lg, %010Lg,",
                            num1, num2, num3, num4, num5);
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
  len_original = sprintf(original, "%10Lg, %10Lg, %10Lg, %10Lg, %10Lg,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10Lg, %10Lg, %10Lg, %10Lg, %10Lg,", num1,
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
  len_original = sprintf(original, "%.10Lg, %.10Lg, %.10Lg, %.10Lg, %.10Lg,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10Lg, %.10Lg, %.10Lg, %.10Lg, %.10Lg,",
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
      sprintf(original, "%10.10Lg, %10.10Lg, %10.10Lg, %10.10Lg, %10.10Lg,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10Lg, %10.10Lg, %10.10Lg, %10.10Lg, %10.10Lg,",
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
      sprintf(original, "%20.10Lg, %20.10Lg, %20.10Lg, %20.10Lg, %20.10Lg,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10Lg, %20.10Lg, %20.10Lg, %20.10Lg, %20.10Lg,",
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
      sprintf(original, "%10.20Lg, %10.20Lg, %10.20Lg, %10.20Lg, %10.20Lg,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20Lg, %10.20Lg, %10.20Lg, %10.20Lg, %10.20Lg,",
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
  len_original = sprintf(original, "%+Lg, %-Lg, % Lg, %#Lg, %0Lg,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+Lg, %-Lg, % Lg, %#Lg, %0Lg,", num1,
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
  len_original = sprintf(original, "%+10Lg, %-10Lg, % 10Lg, %#10Lg, %020Lg,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%+10Lg, %-10Lg, % 10Lg, %#10Lg, %020Lg,",
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
      sprintf(original, "%+.10Lg, %-.10Lg, % .10Lg, %#.10Lg, %0.10Lg,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%+.10Lg, %-.10Lg, % .10Lg, %#.10Lg, %0.10Lg,", num1,
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
      original, "%+10.10Lg, %-10.10Lg, % 10.10Lg, %#10.10Lg, %010.10Lg,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.10Lg, %-10.10Lg, % 10.10Lg, %#10.10Lg, %010.10Lg,", num1,
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
      original, "%+20.10Lg, %-20.10Lg, % 20.10Lg, %#20.10Lg, a%020.10Lg,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+20.10Lg, %-20.10Lg, % 20.10Lg, %#20.10Lg, a%020.10Lg,", num1,
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
      original, "%+10.20Lg, %-10.20Lg, % 10.20Lg, %#10.20Lg, %010.20Lg,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%+10.20Lg, %-10.20Lg, % 10.20Lg, %#10.20Lg, %010.20Lg,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_Lg(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("double Lg");

  dec = tcase_create("\tdouble_Lg\t");
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