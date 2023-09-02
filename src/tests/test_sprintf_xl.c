#include "../s21_string.h"
#include "test.h"

START_TEST(stars) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "a%*lx, %-*lx, %*lx, %-#*lx, %#*lx,", 10,
                         num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "a%*lx, %-*lx, %*lx, %-#*lx, %#*lx,", 10,
                            num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "b%.*lx, %-.*lx, %.*lx, %-#.*lx, %#.*lx,",
                         10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  len_compare = s21_sprintf(compare, "b%.*lx, %-.*lx, %.*lx, %-#.*lx, %#.*lx,",
                            10, num1, 10, num2, 10, num3, 10, num4, 10, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(no_flags) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%lx, %lx, %lx, %lx, %lx,", num1, num2, num3,
                         num4, num5);
  len_compare = s21_sprintf(compare, "%lx, %lx, %lx, %lx, %lx,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);

  len_original = sprintf(original, "a%lx, %lx, %lx, %lx, %lx,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "a%lx, %lx, %lx, %lx, %lx,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wid) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10lx, %10lx, %10lx, %10lx, %10lx,", num1,
                         num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10lx, %10lx, %10lx, %10lx, %10lx,", num1,
                            num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(acc) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%.10lx, %.10lx, %.10lx, %.10lx, %.10lx,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%.10lx, %.10lx, %.10lx, %.10lx, %.10lx,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wa) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10lx, %10.10lx, %10.10lx, %10.10lx, %10.10lx,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.10lx, %10.10lx, %10.10lx, %10.10lx, %10.10lx,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(Wa) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%20.10lx, %20.10lx, %20.10lx, %20.10lx, %20.10lx,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%20.10lx, %20.10lx, %20.10lx, %20.10lx, %20.10lx,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(wA) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20lx, %10.20lx, %10.20lx, %10.20lx, %10.20lx,",
              num1, num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%10.20lx, %10.20lx, %10.20lx, %10.20lx, %10.20lx,",
                  num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%lx, %-lx, %lx, %#lx, %-#lx,", num1, num2,
                         num3, num4, num5);
  len_compare = s21_sprintf(compare, "%lx, %-lx, %lx, %#lx, %-#lx,", num1, num2,
                            num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wid) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(original, "%10lx, %-10lx, %10lx, %#10lx, %-#20lx,",
                         num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(compare, "%10lx, %-10lx, %10lx, %#10lx, %-#20lx,",
                            num1, num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_acc) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%.10lx, %-.10lx, %.10lx, %#.10lx, %-#.10lx,", num1,
              num2, num3, num4, num5);
  len_compare =
      s21_sprintf(compare, "%.10lx, %-.10lx, %.10lx, %#.10lx, %-#.10lx,", num1,
                  num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wa) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.10lx, %-10.10lx, %10.10lx, %#10.10lx, %-#10.10lx,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%10.10lx, %-10.10lx, %10.10lx, %#10.10lx, %-#10.10lx,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_Wa) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long unsigned num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original = sprintf(
      original, "%20.10lx, %-20.10lx, %20.10lx, %#20.10lx, a%-#20.10lx,", num1,
      num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%20.10lx, %-20.10lx, %20.10lx, %#20.10lx, a%-#20.10lx,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_wA) {
  long unsigned num1 = N1;
  long unsigned num2 = N2;
  long unsigned num3 = N33;
  long unsigned num4 = N12;
  long num5 = N2 + 1;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20lx, %-10.20lx, %10.20lx, %#10.20lx, %-#10.20lx,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%10.20lx, %-10.20lx, %10.20lx, %#10.20lx, %-#10.20lx,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

START_TEST(flags_minuscount) {
  long num1 = -1;
  long num2 = -10;
  long num3 = -100;
  long num4 = -1000;
  long num5 = -10000;
  char original[BS] = {0};
  char compare[BS] = {0};
  int len_original = 1933;
  int len_compare = 1933;
  len_original =
      sprintf(original, "%10.20lx, %-10.20lx, %10.20lx, %#10.20lx, %-#10.20lx,",
              num1, num2, num3, num4, num5);
  len_compare = s21_sprintf(
      compare, "%10.20lx, %-10.20lx, %10.20lx, %#10.20lx, %-#10.20lx,", num1,
      num2, num3, num4, num5);
  ck_assert_str_eq(original, compare);
  ck_assert_int_eq(len_original, len_compare);
}
END_TEST

Suite *suit_sprintf_lx(void) {
  Suite *s;
  TCase *dec;

  s = suite_create("hexadecimal l");

  dec = tcase_create("\thexadecimal_l\t");
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
