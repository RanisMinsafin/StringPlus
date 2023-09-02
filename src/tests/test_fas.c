#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strlen) {
  char* test = "test_string\0";
  s21_size_t res = strlen(test);
  s21_size_t res2 = s21_strlen(test);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strlen_null_str) {
  char* test = "\0";
  s21_size_t res = strlen(test);
  s21_size_t res2 = s21_strlen(test);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strlen_invalid_str) {
  char* test = "";
  s21_size_t res = strlen(test);
  s21_size_t res2 = s21_strlen(test);
  ck_assert_int_eq(res, res2);
}
END_TEST

/*strspn tests*/
START_TEST(test_s21_strspn) {
  char* test_first = "test string";
  char* test_second = "set ";
  s21_size_t res = strspn(test_first, test_second);
  s21_size_t res2 = s21_strspn(test_first, test_second);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strspn_no_matches) {
  char* test_first = "test string";
  char* test_second = "1";
  s21_size_t res = strspn(test_first, test_second);
  s21_size_t res2 = s21_strspn(test_first, test_second);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strspn_all_matches) {
  char* test_first = "test string";
  char* test_second = "set ring";
  s21_size_t res = strspn(test_first, test_second);
  s21_size_t res2 = s21_strspn(test_first, test_second);
  ck_assert_int_eq(res, res2);
}
END_TEST

/*strcspn tests*/
START_TEST(test_s21_strcspn) {
  char* test_first = "test string";
  char* test_second = "ig ";
  s21_size_t res = strcspn(test_first, test_second);
  s21_size_t res2 = s21_strcspn(test_first, test_second);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strcspn_no_matches) {
  char* test_first = "test string";
  char* test_second = "1";
  s21_size_t res = strcspn(test_first, test_second);
  s21_size_t res2 = s21_strcspn(test_first, test_second);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strcspn_null_string) {
  char* test_first = "test string";
  char* test_second = "";
  s21_size_t res = strcspn(test_first, test_second);
  s21_size_t res2 = s21_strcspn(test_first, test_second);
  ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_memchr_letterexists) {
  char test1[100] = "test_string\0";
  char test2 = '_';
  char* res = memchr(test1, test2, 10);
  char* res2 = s21_memchr(test1, test2, 10);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_memchr_letter_noexists) {
  char test1[100] = "test_string\0";
  char test2 = ' ';
  char* res = memchr(test1, test2, 10);
  char* res2 = s21_memchr(test1, test2, 10);
  ck_assert_pstr_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_strrchr_letter_exists) {
  char test1[100] = "test_string\0";
  char test2 = 's';
  char* res = strrchr(test1, test2);
  char* res2 = s21_strrchr(test1, test2);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_strrchr_letter_noexists) {
  char* test4 = " \n\0";
  char* test5 = " \0";
  char* test6 = "\n\0";

  char* res = strchr(test4, ' ');
  char* res2 = s21_strchr(test4, ' ');
  ck_assert_str_eq(res, res2);
  ck_assert_ptr_eq((s21_strrchr(test4, 'o')), strrchr(test4, 'o'));
  ck_assert_ptr_eq((strrchr(test5, ' ')), s21_strrchr(test5, ' '));
  ck_assert_ptr_eq((strrchr(test6, 'z')), s21_strrchr(test6, 'z'));
}
END_TEST

START_TEST(tests_s21_strchr_letter_exists) {
  char* strchr1 = "Hello world\0";
  char* strchr2 = "Hello world\n\0";
  char* strchr3 = "a\n\0";
  ck_assert_str_eq((strchr(strchr1, 'l')), s21_strchr(strchr1, 'l'));
  ck_assert_str_eq((strchr(strchr2, 'l')), s21_strchr(strchr2, 'l'));
  ck_assert_str_eq((strchr(strchr3, 'a')), s21_strchr(strchr3, 'a'));
}
END_TEST

START_TEST(tests_s21_strchr_letter_noexists) {
  char* strchr4 = " \n\0";
  char* strchr5 = " \0";
  char* strchr6 = "\nf\0";

  char* res = strchr(strchr4, ' ');
  char* res2 = s21_strchr(strchr4, ' ');

  ck_assert_str_eq(res, res2);
  ck_assert_str_eq((strchr(strchr5, ' ')), s21_strchr(strchr5, ' '));
  ck_assert_str_eq((strchr(strchr6, 'f')), s21_strchr(strchr6, 'f'));
}
END_TEST

START_TEST(tests_s21_strpbrk) {
  char* test1 = "Hello world\0";
  char* test2 = "Hello world\n\0";
  char* test3 = "a\n\0";
  char* test4 = " \n\0";
  char* test5 = " \0";
  char* test6 = "\n\0";

  ck_assert_pstr_eq(s21_strpbrk(test1, test1), (strpbrk(test1, test1)));
  ck_assert_pstr_eq(s21_strpbrk(test2, test1), (strpbrk(test2, test1)));
  ck_assert_pstr_eq(s21_strpbrk(test3, test1), (strpbrk(test3, test1)));
  ck_assert_pstr_eq(s21_strpbrk(test4, test1), (strpbrk(test4, test1)));
  ck_assert_pstr_eq(s21_strpbrk(test5, test1), (strpbrk(test5, test1)));
  ck_assert_pstr_eq(s21_strpbrk(test6, test1), (strpbrk(test6, test1)));
}
END_TEST

START_TEST(tests_s21_strstr) {
  char test1[100] = "test_string\0";
  char* test2 = "string";
  char* res = strstr(test1, test2);
  char* res2 = s21_strstr(test1, test2);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strstr_second_empty_str) {
  char test[20] = "test me\0 love";
  char* res = strstr(test, "");
  char* res2 = s21_strstr(test, "");
  ck_assert_str_eq(res, res2);
}

START_TEST(test_s21_strstr_first_empty_str) {
  char test[20] = "test me\0 love";
  char* res = strstr("", test);
  char* res2 = s21_strstr("", test);
  ck_assert_ptr_eq(res, res2);
}

START_TEST(tests_s21_sscanf_char) {
  char a = '\0', b = '\0';
  char a11 = '\0', b11 = '\0';
  char a1[10], b1[10];
  ck_assert_int_eq((sscanf("2", "%c", &a)), s21_sscanf("2", "%c", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("A", "%c", &a)), s21_sscanf("A", "%c", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("Zz", "%c", &a)), s21_sscanf("Zz", "%c", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("   2", "%c", &a)), s21_sscanf("   2", "%c", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("2 5", "%c%c", &a, &a11)),
                   s21_sscanf("2 5", "%c%c", &b, &b11));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a11, b11);
  ck_assert_int_eq((sscanf("2", "%1c", &a)), s21_sscanf("2", "%1c", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("  ", "%c", &a)), s21_sscanf("  ", "%c", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("Enterme", "%3c", a1)),
                   s21_sscanf("Enterme", "%3c", b1));
  a1[3] = '\0';
  b1[3] = '\0';
  ck_assert_str_eq(a1, b1);
  ck_assert_int_eq((sscanf("Enterme", "%3c", a1)),
                   s21_sscanf("Enterme", "%3c", b1));
  ck_assert_str_eq(a1, b1);
  a1[3] = '\0';
  b1[3] = '\0';
  ck_assert_int_eq((sscanf("RanisMe", "%c", a1)),
                   s21_sscanf("RanisMe", "%c", b1));
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(tests_s21_sscanf_decim) {
  int a = 0, b = 0;
  int i = 0, z = 0;
  ck_assert_int_eq((sscanf("6", "%d", &i)), s21_sscanf("6", "%d", &z));
  ck_assert_int_eq(i, z);
  ck_assert_int_eq((sscanf("6 4", "%d%d", &i, &a)),
                   s21_sscanf("6 4", "%d%d", &z, &b));
  ck_assert_int_eq(i, z);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("60000000 4213213123", "%d%d", &i, &a)),
                   s21_sscanf("60000000 4213213123", "%d%d", &z, &b));
  ck_assert_int_eq(i, z);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("6", "%d", &i)), s21_sscanf("6", "%d", &z));
  ck_assert_int_eq((sscanf("6", "%d", &i)), s21_sscanf("6", "%d", &z));
  ck_assert_int_eq(i, z);
  ck_assert_int_eq((sscanf("14", "%d", &i)), s21_sscanf("14", "%d", &z));
  ck_assert_int_eq(i, z);
  ck_assert_int_eq((sscanf("123456", "%3d", &i)),
                   s21_sscanf("123456", "%3d", &z));
  ck_assert_int_eq(i, z);
}

START_TEST(tests_s21_sscanf_int) {
  int i = 0, z = 0, a = 0, b = 0;
  long int y = 0, u = 0;
  int i1 = 0, z1 = 0, a1 = 0, b1 = 0;
  char str[100] = {'\0'}, str1[100] = {'\0'};
  ck_assert_int_eq((sscanf("-27", "%d", &a)), s21_sscanf("-27", "%d", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("+99", "%d", &a)), s21_sscanf("+99", "%d", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("-328576", "%ld", &y)),
                   s21_sscanf("-328576", "%ld", &u));
  ck_assert_int_eq(y, u);
  ck_assert_int_eq((sscanf("-27", "%i", &a)), s21_sscanf("-27", "%i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("32", "%i", &a)), s21_sscanf("32", "%i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("032", "%i", &a)), s21_sscanf("032", "%i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("0x32", "%i", &a)), s21_sscanf("0x32", "%i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("90 70 50 40", "%i%i%i%i", &a, &a1, &z, &z1)),
                   s21_sscanf("90 70 50 40", "%i%i%i%i", &b, &b1, &i, &i1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(z, i);
  ck_assert_int_eq(z1, i1);
  ck_assert_int_eq((sscanf("  90", "%i", &a)), s21_sscanf("  90", "%i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("7xFA2", "%i", &a)), s21_sscanf("7xFA2", "%i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("7xFA2", "%3i", &a)),
                   s21_sscanf("7xFA2", "%3i", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("58hello", "%i%s", &a, str)),
                   s21_sscanf("58hello", "%i%s", &b, str1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("58hello59", "%i%s%d%d", &a, str, &z1, &b1)),
                   s21_sscanf("58hello59", "%i%s%d%d", &b, str1, &i1, &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(i1, z1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(tests_s21_sscanf_e_E) {
  float a, b;
  ck_assert_int_eq((sscanf("2.0311", "%E", &a)),
                   s21_sscanf("2.0311", "%E", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2.4321412412422222222222", "%e", &a)),
                   s21_sscanf("2.4321412412422222222222", "%e", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("22234.4321412412422222222222", "%3e", &a)),
                   s21_sscanf("22234.4321412412422222222222", "%3e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST;

START_TEST(tests_s21_sscanf_f) {
  float a, b, g, c;
  a = b = g = c = 0.0;
  long double n = 0.0, m = 0.0;
  ck_assert_int_eq((sscanf("2.231", "%f", &a)), s21_sscanf("2.231", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("-2.231", "%f", &a)),
                   s21_sscanf("-2.231", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("-2.231", "%Lf", &n)),
                   s21_sscanf("-2.231", "%Lf", &m));
  ck_assert_float_eq(n, m);
  ck_assert_int_eq((sscanf("2.231", "%Lf", &n)),
                   s21_sscanf("2.231", "%Lf", &m));
  ck_assert_float_eq(n, m);
  ck_assert_int_eq((sscanf("2.200", "%5f", &a)),
                   s21_sscanf("2.200", "%5f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("b2.23.1", "%f", &a)),
                   s21_sscanf("b2.23.1", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("3124124.21312112312312", "%f", &a)),
                   s21_sscanf("3124124.21312112312312", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("123.21312112312312", "%f", &a)),
                   s21_sscanf("123.21312112312312", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2.2E", "%f", &a)), s21_sscanf("2.2E", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2.2S31", "%f", &a)),
                   s21_sscanf("2.2S31", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2.2S31", "%1f", &a)),
                   s21_sscanf("2.2S31", "%1f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("22.31E", "%f", &a)),
                   s21_sscanf("22.31E", "%f", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2222223.31E", "%f%f", &a, &g)),
                   s21_sscanf("2222223.31E", "%f%f", &b, &c));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(g, c);
}
END_TEST

START_TEST(tests_s21_sscanf_g_G) {
  float a = 0.0, b = 0.0;
  ck_assert_int_eq((sscanf("  2.0311", "%G", &a)),
                   s21_sscanf("  2.0311", "%G", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2.031231231", "%g", &a)),
                   s21_sscanf("2.031231231", "%g", &b));
  ck_assert_float_eq(a, b);
  ck_assert_int_eq((sscanf("2234.031231231", "%3g", &a)),
                   s21_sscanf("2234.031231231", "%3g", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(tests_s21_sscanf_o) {
  int a = 0, b = 0;
  int z = 0, g = 0;
  ck_assert_int_eq((sscanf("014", "%o", &a)), (s21_sscanf("014", "%o", &b)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("010", "%o", &a)), (s21_sscanf("010", "%o", &b)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("710", "%o", &a)), (s21_sscanf("710", "%o", &b)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("577", "%o", &a)), (s21_sscanf("577", "%o", &b)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("77", "%o", &a)), (s21_sscanf("77", "%o", &b)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("0", "%o", &a)), (s21_sscanf("0", "%o", &b)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq((sscanf("010 10", "%o%d", &a, &z)),
                   (s21_sscanf("010 10", "%o%d", &b, &g)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(z, g);
  ck_assert_int_eq((sscanf("     71234542 10", "%o%d", &a, &z)),
                   (s21_sscanf("     71234542 10", "%o%d", &b, &g)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(z, g);
  ck_assert_int_eq((sscanf("     71234542 10", "%3o%d", &a, &z)),
                   (s21_sscanf("     71234542 10", "%3o%d", &b, &g)));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(z, g);
}
END_TEST

START_TEST(tests_s21_sscanf_string) {
  char a[500] = {'\0'}, b[500] = {'\0'};
  char a1[50] = {'\0'}, b1[50] = {'\0'};
  char a2[50] = {'\0'}, b2[50] = {'\0'};
  char a3[50] = {'\0'}, b3[50] = {'\0'};
  char* str =
      "tthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthi"
      "sthisthisthisthis";
  ck_assert_int_eq((sscanf(str, "%s", a)), s21_sscanf(str, "%s", b));
  ck_assert_str_eq(a, b);
  ck_assert_int_eq((sscanf("that is", "%s %s", a, a1)),
                   s21_sscanf("that is", "%s %s", b, b1));
  ck_assert_str_eq(a1, b1);
  ck_assert_int_eq((sscanf("that is", "%2s %s", a, a1)),
                   s21_sscanf("that is", "%2s %s", b, b1));
  ck_assert_str_eq(a1, b1);
  ck_assert_int_eq((sscanf(" that is", "%s %s", a, a1)),
                   s21_sscanf(" that is", "%s %s", b, b1));
  ck_assert_str_eq(a1, b1);
  ck_assert_int_eq(
      (sscanf("cccheckheckcheckheckheckcheckcheckheckcheckheckheckcheck",
              "%10s", a1)),
      s21_sscanf("cccheckheckcheckheckheckcheckcheckheckcheckheckheckcheck",
                 "%10s", b1));
  ck_assert_str_eq(a1, b1);
  ck_assert_int_eq((sscanf("check check", "%*s%s", a2)),
                   s21_sscanf("check check", "%*s%s", b2));
  ck_assert_str_eq(a2, b2);
  ck_assert_int_eq((sscanf("  check check", "%*s%s", a2)),
                   s21_sscanf("  check check", "%*s%s", b2));
  ck_assert_str_eq(a2, b2);
  ck_assert_int_eq((sscanf("  check check", "%2s", a3)),
                   s21_sscanf("  check check", "%2s", b3));
  ck_assert_str_eq(a3, b3);
}
END_TEST

START_TEST(tests_s21_sscanf_u) {
  unsigned int a = 0, b = 0;
  ck_assert_int_eq((sscanf("514", "%u", &a)), (s21_sscanf("514", "%u", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf(" 10", "%u", &a)), (s21_sscanf(" 10", "%u", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf(" 80", "%u", &a)), (s21_sscanf(" 80", "%u", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("310", "%u", &a)), (s21_sscanf("310", "%u", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("310", "%2u", &a)), (s21_sscanf("310", "%2u", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("S10", "%u", &a)), (s21_sscanf("S10", "%u", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf(".10", "%u", &a)), (s21_sscanf(".10", "%u", &b)));
  ck_assert_uint_eq(a, b);
}

START_TEST(tests_s21_sscanf_x_X) {
  unsigned int a = 0, b = 0;
  long unsigned int a2, b2;
  ck_assert_int_eq((sscanf("514", "%x", &a)), (s21_sscanf("514", "%x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("  10", "%x", &a)), (s21_sscanf("  10", "%x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf(" F10F E10", "%x", &a)),
                   (s21_sscanf(" F10F E10", "%x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf(" f10f e10", "%x", &a)),
                   (s21_sscanf(" f10f e10", "%x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("AAB", "%X", &a)), (s21_sscanf("AAB", "%X", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("DEEE", "%x", &a)), (s21_sscanf("DEEE", "%x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("deee", "%2x", &a)),
                   (s21_sscanf("deee", "%2x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("abcd", "%2x", &a)),
                   (s21_sscanf("abcd", "%2x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("DEF", "%X", &a)), (s21_sscanf("DEF", "%X", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("DEF", "%2X", &a)), (s21_sscanf("DEF", "%2X", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("def", "%x", &a)), (s21_sscanf("def", "%x", &b)));
  ck_assert_uint_eq(a, b);
  ck_assert_int_eq((sscanf("def", "%lx", &a2)),
                   (s21_sscanf("def", "%lx", &b2)));
  ck_assert_uint_eq(a2, b2);
}
END_TEST

START_TEST(tests_s21_sscanf_p) {
  int val = 1234123;
  char buf[100];
  void* ptr;
  void* ptr1;
  sprintf(buf, "%p", (void*)&val);
  ck_assert_int_eq((sscanf(buf, "%p", &ptr)), s21_sscanf(buf, "%p", &ptr1));
  int* iPtr1 = ptr1;
  int* iPtr = ptr;
  ck_assert_int_eq(*iPtr1, val);
  ck_assert_ptr_eq(iPtr1, &val);
  ck_assert_ptr_eq(iPtr, &val);
  char* hello = "I am characters";
  sprintf(buf, "%p", (void*)&hello);
  ck_assert_int_eq((sscanf(buf, "%p", &ptr)), s21_sscanf(buf, "%p", &ptr1));
  char* iPr1 = ptr1;
  char* iPr = ptr;
  ck_assert_ptr_eq(iPr1, &hello);
  ck_assert_ptr_eq(iPr, &hello);
  char* hello2 = "I am man";
  sprintf(buf, "%3p", (void*)&hello2);
  ck_assert_int_eq((sscanf(buf, "%3p", &ptr)), s21_sscanf(buf, "%3p", &ptr1));
  char* iPr2 = ptr1;
  char* iPr3 = ptr;
  ck_assert_ptr_eq(iPr2, iPr3);
}
END_TEST

START_TEST(tests_s21_sscanf_n) {
  int a = 0, b = 0, a1 = 0, b1 = 0;
  int z = 0, z1 = 0;
  char str[100] = {'\0'};
  char str1[100] = {'\0'};
  char st[100] = {'\0'};
  char st1[100] = {'\0'};
  ck_assert_int_eq((sscanf("514", "%u%n", &a, &a1)),
                   s21_sscanf("514", "%u%n", &b, &b1));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq((sscanf("  312", "%u%n", &a, &a1)),
                   (s21_sscanf("  312", "%u%n", &b, &b1)));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(
      (sscanf("312 iamstring", "%u%n%s%n", &a, &a1, str, &z)),
      (s21_sscanf("312 iamstring", "%u%n%s%n", &b, &b1, str1, &z1)));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(z, z1);
  ck_assert_int_eq((sscanf("hello,enterio", "%s%n", st, &a1)),
                   s21_sscanf("hello,enterio", "%s%n", st1, &b1));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(
      (sscanf("reallybigreallybig opa ozhidal?", "%s%n", st, &a1)),
      s21_sscanf("reallybigreallybig opa ozhidal?", "%s%n", st1, &b1));
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(tests_s21_sscanf_percent) {
  char a[100] = {'\0'}, b[100] = {'\0'};
  char a1[100] = {'\0'}, b1[100] = {'\0'};
  ck_assert_int_eq((sscanf("%check  check", "%s", a)),
                   s21_sscanf("%check check", "%s", b));
  ck_assert_str_eq(a, b);
  ck_assert_int_eq((sscanf("checkcheck", "%s%%", a)),
                   s21_sscanf("checkcheck", "%s%%", b));
  ck_assert_str_eq(a, b);
  ck_assert_int_eq((sscanf("checkcheck", "%2s%%", a1)),
                   s21_sscanf("checkcheck", "%2s%%", b1));
  ck_assert_str_eq(a, b);
  ck_assert_int_eq((sscanf(" check%check", "%s", a)),
                   s21_sscanf(" check%check", "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(tests_s21_sscanf_width) {
  char a[100] = {'\0'}, b[100] = {'\0'};
  ck_assert_int_eq((sscanf("check check", "%22s", a)),
                   s21_sscanf("check check", "%22s", b));
  ck_assert_str_eq(a, b);
  ck_assert_int_eq((sscanf("checkcheck", "%s", a)),
                   s21_sscanf("checkcheck", "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(tests_s21_sscanf_length_h) {
  short int z1 = 0, v1 = 0;
  ck_assert_int_eq((sscanf("-512", "%hd", &z1)),
                   s21_sscanf("-512", "%hd", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("512", "%hi", &z1)), s21_sscanf("512", "%hd", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("2", "%2hi", &z1)), s21_sscanf("2", "%2hd", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("512", "%ho", &z1)), s21_sscanf("512", "%ho", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("512", "%hX", &z1)), s21_sscanf("512", "%hX", &v1));
  ck_assert_int_eq(z1, v1);
}
END_TEST

START_TEST(tests_s21_sscanf_length_l) {
  long int z1 = 0, v1 = 0;
  ck_assert_int_eq((sscanf("512", "%ld", &z1)), s21_sscanf("512", "%ld", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("1111512", "%ld", &z1)),
                   s21_sscanf("1111512", "%ld", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("912321512", "%ld", &z1)),
                   s21_sscanf("912321512", "%ld", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("5z2", "%ld", &z1)), s21_sscanf("5z2", "%ld", &v1));
  ck_assert_int_eq(z1, v1);
  long long ba, ga;
  ck_assert_int_eq((sscanf("5z2", "%lld", &ba)),
                   s21_sscanf("5z2", "%lld", &ga));
  ck_assert_int_eq(ba, ga);
  ck_assert_int_eq((sscanf("5.2", "%ld", &z1)), s21_sscanf("5.2", "%ld", &v1));
  ck_assert_int_eq(z1, v1);
  ck_assert_int_eq((sscanf("5 Oi Mate", "%ld", &z1)),
                   s21_sscanf("5 Oi Mate", "%ld", &v1));
  ck_assert_int_eq(z1, v1);
}
END_TEST

START_TEST(tests_s21_sscanf_length_L) {
  long double z1 = 0, v1 = 0;
  char* num =
      "512.0123456789123456789123213123123123123213123123123123124135235462";
  ck_assert_int_eq((sscanf("512.0123456789123456789", "%Lf", &z1)),
                   s21_sscanf("512.0123456789123456789", "%Lf", &v1));
  ck_assert_float_eq(z1, v1);
  ck_assert_int_eq((sscanf(num, "%Lf", &z1)), s21_sscanf(num, "%Lf", &v1));
  ck_assert_float_eq(z1, v1);
  ck_assert_int_eq((sscanf("2.0123456789123456789", "%Lf", &z1)),
                   s21_sscanf("2.0123456789123456789", "%Lf", &v1));
  ck_assert_float_eq(z1, v1);
  ck_assert_int_eq((sscanf("s   2.0123456789123456789", "%Lf", &z1)),
                   s21_sscanf("s   2.0123456789123456789", "%Lf", &v1));
  ck_assert_float_eq(z1, v1);
  ck_assert_int_eq((sscanf("9123213123123321321512", "%Lf", &z1)),
                   s21_sscanf("9123213123123321321512", "%Lf", &v1));
  ck_assert_float_eq(z1, v1);
  ck_assert_int_eq((sscanf("2.0123456789123456789", "%Lf", &z1)),
                   s21_sscanf("2.0123456789123456789", "%Lf", &v1));
  ck_assert_float_eq(z1, v1);
}
END_TEST

START_TEST(test_s21_strcat) {
  char test1[100] = "test_string\0";
  char* test2 = "second_string\0";
  char* res = strcat(test1, test2);
  char* res2 = s21_strcat(test1, test2);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strcmp) {
  char* str1 = "abcd";
  char* str2 = "Abcd";
  char* str4 = "";
  ck_assert_int_eq(s21_strcmp(str1, str1), strcmp(str1, str1));
  int a = s21_strcmp(str1, str2);
  int b = strcmp(str1, str2);
  if (a < -1) a = -1;
  if (b < -1) b = -1;
  if (a > 1) a = 1;
  if (b > 1) b = 1;
  ck_assert_int_eq(a, b);
  ck_assert((s21_strcmp(str1, str4) < 0 && strcmp(str1, str4) < 0) ||
            (s21_strcmp(str1, str4) > 0 && strcmp(str1, str4) > 0) ||
            (s21_strcmp(str1, str4) == 0 && strcmp(str1, str4) == 0));
  ck_assert((s21_strcmp(str4, str1) < 0 && strcmp(str4, str1) < 0) ||
            (s21_strcmp(str4, str1) > 0 && strcmp(str4, str1) > 0) ||
            (s21_strcmp(str4, str1) == 0 && strcmp(str4, str1) == 0));
  ck_assert((s21_strcmp(str4, str4) < 0 && strcmp(str4, str4) < 0) ||
            (s21_strcmp(str4, str4) > 0 && strcmp(str4, str4) > 0) ||
            (s21_strcmp(str4, str4) == 0 && strcmp(str4, str4) == 0));
  char* str5 = " ";
  ck_assert((s21_strcmp(str4, str5) < 0 && strcmp(str4, str5) < 0) ||
            (s21_strcmp(str4, str5) > 0 && strcmp(str4, str5) > 0) ||
            (s21_strcmp(str4, str5) == 0 && strcmp(str4, str5) == 0));
  char* str6 = "123456";
  ck_assert_int_eq(s21_strcmp(str6, str6), strcmp(str6, str6));
}
END_TEST

START_TEST(test_s21_strcmp_2) {
  char* str1 = "Abcd";
  char* str2 = "abcd";
  ck_assert((s21_strcmp(str1, str2) < 0 && strcmp(str1, str2) < 0) ||
            (s21_strcmp(str1, str2) > 0 && strcmp(str1, str2) > 0) ||
            (s21_strcmp(str1, str2) == 0 && strcmp(str1, str2) == 0));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char* str1 = "abcd";
  char* str2 = "abcdef";
  char* str3 = "Abcd";
  char* str4 = "";
  ck_assert_int_eq(s21_strncmp(str1, str1, 4), strncmp(str1, str1, 4));
  ck_assert_int_eq(s21_strncmp(str1, str1, 1), strncmp(str1, str1, 1));
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
  ck_assert((s21_strncmp(str1, str2, 5) < 0 && strncmp(str1, str2, 5) < 0) ||
            (s21_strncmp(str1, str2, 5) > 0 && strncmp(str1, str2, 5) > 0) ||
            (s21_strncmp(str1, str2, 5) == 0 && strncmp(str1, str2, 5) == 0));
  int a = s21_strncmp(str1, str3, 4);
  int b = strncmp(str1, str3, 4);
  if (a < -1) a = -1;
  if (b < -1) b = -1;
  if (a > 1) a = 1;
  if (b > 1) b = 1;
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(s21_strncmp(str1, str4, 0), strncmp(str1, str4, 0));
  ck_assert_int_eq(s21_strncmp(str4, str1, 0), strncmp(str4, str1, 0));
  ck_assert_int_eq(s21_strncmp(str4, str4, 0), strncmp(str4, str4, 0));
  char* str5 = " ";
  ck_assert_int_eq(s21_strncmp(str4, str5, 0), strncmp(str4, str5, 0));
  char* str6 = "123456";
  ck_assert_int_eq(s21_strncmp(str6, str6, 3), strncmp(str6, str6, 3));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char str1[] = "ABCDE";
  char str2[] = "5";
  char str3[] = "aBCDE";
  char str4[] = "5432";
  char str5[] = "53";
  char str6[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str7[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";

  ck_assert((s21_memcmp(str1, str1, 0) < 0 && memcmp(str1, str1, 0) < 0) ||
            (s21_memcmp(str1, str1, 0) > 0 && memcmp(str1, str1, 0) > 0) ||
            (s21_memcmp(str1, str1, 0) == 0 && memcmp(str1, str1, 0) == 0));
  // ck_assert_int_eq(s21_memcmp(str1, str1, 0), memcmp(str1, str1, 0));
  ck_assert_int_eq(s21_memcmp(str1, str1, 3), memcmp(str1, str1, 3));
  ck_assert((s21_memcmp(str1, str3, 1) < 0 && memcmp(str1, str3, 1) < 0) ||
            (s21_memcmp(str1, str3, 1) > 0 && memcmp(str1, str3, 1) > 0) ||
            (s21_memcmp(str1, str3, 1) == 0 && memcmp(str1, str3, 1) == 0));
  ck_assert_int_eq(s21_memcmp(str2, str2, 0), memcmp(str2, str2, 0));
  ck_assert_int_eq(s21_memcmp(str2, str4, 1), memcmp(str2, str4, 1));
  ck_assert_int_eq(s21_memcmp(str4, str4, 2), memcmp(str4, str4, 2));
  ck_assert((s21_memcmp(str4, str5, 2) < 0 && memcmp(str4, str5, 2) < 0) ||
            (s21_memcmp(str4, str5, 2) > 0 && memcmp(str4, str5, 2) > 0) ||
            (s21_memcmp(str4, str5, 2) == 0 && memcmp(str4, str5, 2) == 0));
  ck_assert_int_eq(s21_memcmp(str6, str6, 71), memcmp(str6, str6, 71));
  ck_assert((s21_memcmp(str6, str7, 71) < 0 && memcmp(str6, str7, 71) < 0) ||
            (s21_memcmp(str6, str7, 71) > 0 && memcmp(str6, str7, 71) > 0) ||
            (s21_memcmp(str6, str7, 71) == 0 && memcmp(str6, str7, 71) == 0));
}
END_TEST

START_TEST(test_s21_trim_both) {
  char* test1 = s21_NULL;
  test1 = s21_trim("", "");
  char* test2 = "";
  ck_assert_str_eq(test1, test2);
  if (test1) free(test1);
}
END_TEST

START_TEST(test_s21_trim_first_zero_str) {
  char* test3 = s21_NULL;
  test3 = s21_trim("", "qwer123!&$");
  char* test4 = "";
  ck_assert_str_eq(test3, test4);
  if (test3) free(test3);
}
END_TEST

START_TEST(test_s21_trim_second_zero_str) {
  char* test5 = s21_NULL;
  test5 = s21_trim("qwer123!&$", "");
  char* test6 = "qwer123!&$";
  ck_assert_str_eq(test5, test6);
  if (test5) free(test5);
}
END_TEST

START_TEST(test_s21_trim_same_str) {
  char* test7 = s21_NULL;
  test7 = s21_trim("qwer123!&$", "qwer123!&$");
  char* test8 = "";
  ck_assert_str_eq(test7, test8);
  if (test7) free(test7);
}
END_TEST

START_TEST(test_s21_trim) {
  char* test9 = s21_NULL;
  test9 = s21_trim("!!-+giga00!+", "!+-0");
  char* test10 = "giga";
  ck_assert_str_eq(test9, test10);
  if (test9) free(test9);
}
END_TEST

START_TEST(test_s21_trim_numbers) {
  char* test11 = s21_NULL;
  test11 = s21_trim("AB2CD3", "123");
  char* test12 = "AB2CD";
  ck_assert_str_eq(test11, test12);
  if (test11) free(test11);
}
END_TEST

START_TEST(test_s21_trim_2) {
  char* test13 = s21_NULL;
  test13 = s21_trim("!  ABCD3  !", "123! ");
  char* test14 = "ABCD";
  ck_assert_str_eq(test13, test14);
  if (test13) free(test13);
}
END_TEST

START_TEST(test_s21_strncat) {
  char test1[100] = "test_string\0";
  char* test2 = "second_string\0";
  char* res = strncat(test1, test2, 3);
  char* res2 = s21_strncat(test1, test2, 3);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strncat_zero) {
  char test1[100] = "test_string\0";
  char* test2 = "second_string\0";
  char* res = strncat(test1, test2, 0);
  char* res2 = s21_strncat(test1, test2, 0);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror) {
  int n = 1;
  char* res = strerror(n);
  char* res2 = s21_strerror(n);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror_linux_max) {
  int n = 133;
  char* res = strerror(n);
  char* res2 = s21_strerror(n);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror_error_0) {
  int n = 0;
  char* res = strerror(n);
  char* res2 = s21_strerror(n);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror_error_3) {
  int n = 3;
  char* res = strerror(n);
  char* res2 = s21_strerror(n);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok) {
  char test1[100] = "tik tok tik.tok\0";
  char* test2 = " .\0";
  char* res = strtok(test1, test2);
  char* res2 = s21_strtok(test1, test2);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok_double) {
  char test1[100] = "tik tok tak.tok\0";
  char test3[100] = "tik tok tak.tok\0";
  char* test2 = " .\0";
  char* res = strtok(test1, test2);
  char* res2 = s21_strtok(test3, test2);
  res = strtok(test1, test2);
  res2 = s21_strtok(test3, test2);
  res = strtok(test1, test2);
  res2 = s21_strtok(test3, test2);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok_NULL) {
  char test1[100] = "tik tok tik.tok\0";
  char test3[100] = "tik tok tik.tok\0";
  char* test2 = " .\0";
  char* res = strtok(test1, test2);
  char* res2 = s21_strtok(test3, test2);
  res = strtok(NULL, test2);
  res2 = s21_strtok(s21_NULL, test2);
  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_to_upper) {
  char* res = s21_NULL;
  char* test = "My little123 ponny";
  res = s21_to_upper(test);
  char* res2 = "MY LITTLE123 PONNY";
  ck_assert_str_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_NULL) {
  char* res = s21_NULL;
  res = s21_to_upper(s21_NULL);
  char* res2 = NULL;
  ck_assert_ptr_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_zero_str) {
  char* res1 = s21_NULL;
  res1 = s21_to_upper("a");
  ck_assert_str_eq(res1, "A");
  if (res1) free(res1);
}
END_TEST

START_TEST(test_s21_to_lower) {
  char* test = "MY LITTLE123 PONNY";
  char* res = s21_NULL;
  res = s21_to_lower(test);
  char* res2 = "my little123 ponny";
  ck_assert_str_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_NULL) {
  char* res = s21_NULL;
  res = s21_to_lower(s21_NULL);
  char* res2 = NULL;
  ck_assert_ptr_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_zero_str) {
  char* res1 = s21_NULL;
  res1 = s21_to_lower("A");
  ck_assert_str_eq(res1, "a");
  if (res1) free(res1);
}
END_TEST

START_TEST(test_s21_insert) {
  char* res = s21_NULL;
  char src[] = "I Groot";
  char str[] = "am";
  s21_size_t index = 1;
  res = s21_insert(src, str, index);
  char* res2 = "Iam Groot";
  ck_assert_str_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_index_zero) {
  char* res = s21_NULL;
  char src[] = "I Groot";
  char str[] = "am";
  s21_size_t index = 7;
  res = s21_insert(src, str, index);
  char* res2 = "I Grootam";
  ck_assert_str_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_index_greater_than_length) {
  char* res = s21_NULL;
  res = s21_insert("12345", "OK", 7);
  char* res2 = NULL;
  ck_assert_ptr_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_index_less_than_zero) {
  char* res = s21_NULL;
  res = s21_insert("12345", "OK", -2);
  char* res2 = NULL;
  ck_assert_ptr_eq(res, res2);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_strcpy) {
  char dest[10] = {0};
  const char* str = "hello";
  s21_strcpy(dest, str);
  char dest2[10] = {0};
  strcpy(dest2, str);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strcpy_info_after_null) {
  char dest[10] = {0};
  const char* str = "123 \0 123";
  s21_strcpy(dest, str);
  char dest2[10] = {0};
  strcpy(dest2, str);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strcpy_q) {
  char dest[10] = {0};
  const char* str = "\0123";
  s21_strcpy(dest, str);
  char dest2[10] = {0};
  strcpy(dest2, str);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strncpy) {
  s21_size_t num = 6;
  char dest[10] = {0};
  const char* str = "louder then";
  s21_strncpy(dest, str, num);
  char dest2[10] = {0};
  strncpy(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strncpy_info_after_null) {
  s21_size_t num = 7;
  char dest[10] = {0};
  const char* str = "123 \0 2";
  s21_strncpy(dest, str, num);
  char dest2[10] = {0};
  strncpy(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strncpy_zero_num) {
  s21_size_t num = 0;
  char dest[10] = {0};
  const char* str = "12345p";
  s21_strncpy(dest, str, num);
  char dest2[10] = {0};
  strncpy(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memcpy) {
  s21_size_t num = 6;
  char dest[10] = {0};
  const char* str = "louder then";
  s21_memcpy(dest, str, num);
  char dest2[10] = {0};
  memcpy(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_info_after_null) {
  s21_size_t num = 6;
  char dest[10] = {0};
  const char* str = "louder then";
  s21_memcpy(dest, str, num);
  char dest2[10] = {0};
  memcpy(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_zero_num) {
  s21_size_t num = 0;
  char dest[10] = {0};
  const char* str = "louder then";
  s21_memcpy(dest, str, num);
  char dest2[10] = {0};
  memcpy(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove) {
  s21_size_t num = 6;
  char dest[10] = {0};
  const char* str = "louder then";
  s21_memmove(dest, str, num);
  char dest2[10] = {0};
  memmove(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove_zero_num) {
  s21_size_t num = 0;
  char dest[10] = {0};
  const char* str = "1234";
  s21_memmove(dest, str, num);
  char dest2[10] = {0};
  memmove(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove_info_after_null) {
  s21_size_t num = 8;
  char dest[10] = {0};
  const char* str = "123 \0 34";
  s21_memmove(dest, str, num);
  char dest2[10] = {0};
  memmove(dest2, str, num);

  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove_new) {
  s21_size_t num = 8;
  char func1[10] = "123456789";
  char func2[10] = "987654321";
  char answ1[10] = {0};
  char answ2[10] = {0};
  s21_memmove(func2, func1, num);
  strcpy(answ1, func2);
  memmove(func2, func1, num);
  strcpy(answ2, func2);
  ck_assert_str_eq(answ1, answ2);
}
END_TEST

START_TEST(test_s21_memset) {
  s21_size_t num = 6;
  int c = 43;
  char str[7] = "louder";
  char str2[7] = "louder";
  s21_memset(str, c, num);
  memset(str2, c, num);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_zero_num) {
  s21_size_t num = 0;
  int c = 43;
  char str[7] = "louder";
  char str2[7] = "louder";
  s21_memset(str, c, num);
  memset(str2, c, num);

  ck_assert_str_eq(str, str2);
}
END_TEST

Suite* insert_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("insert");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_insert);
  tcase_add_test(tc_core, test_s21_insert_index_zero);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_insert_index_greater_than_length);
  tcase_add_test(tc_limits, test_s21_insert_index_less_than_zero);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* memchr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, tests_s21_memchr_letter_noexists);
  tcase_add_test(tc_core, tests_s21_memchr_letterexists);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* to_upper_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("to_upper");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_upper);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_to_upper_NULL);
  tcase_add_test(tc_limits, test_s21_to_upper_zero_str);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* to_lower_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("to_lower");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_lower);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_to_lower_NULL);
  tcase_add_test(tc_limits, test_s21_to_lower_zero_str);

  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* strerror_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strerror);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strerror_linux_max);
  tcase_add_test(tc_limits, test_s21_strerror_error_0);
  tcase_add_test(tc_limits, test_s21_strerror_error_3);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* strncat_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strcat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncat);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strncat_zero);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* strcat_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strcat");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_strcat);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* strtok_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strtok");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_strtok);
  tcase_add_test(tc_core, test_s21_strtok_NULL);
  // tcase_add_test(tc_core, test_s21_strtok_first_NULL);
  tcase_add_test(tc_core, test_s21_strtok_double);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* strchr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strchr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, tests_s21_strchr_letter_exists);
  tcase_add_test(tc_core, tests_s21_strchr_letter_noexists);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* strpbrk_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strpbrk");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, tests_s21_strpbrk);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* strstr_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, tests_s21_strstr);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strstr_first_empty_str);
  tcase_add_test(tc_limits, test_s21_strstr_second_empty_str);
  suite_add_tcase(s, tc_limits);

  return s;
}
Suite* sscanf_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("sscanf");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, tests_s21_sscanf_char);
  tcase_add_test(tc_core, tests_s21_sscanf_decim);
  tcase_add_test(tc_core, tests_s21_sscanf_int);
  tcase_add_test(tc_core, tests_s21_sscanf_e_E);
  tcase_add_test(tc_core, tests_s21_sscanf_f);
  tcase_add_test(tc_core, tests_s21_sscanf_g_G);
  tcase_add_test(tc_core, tests_s21_sscanf_o);
  tcase_add_test(tc_core, tests_s21_sscanf_string);
  tcase_add_test(tc_core, tests_s21_sscanf_u);
  tcase_add_test(tc_core, tests_s21_sscanf_x_X);
  tcase_add_test(tc_core, tests_s21_sscanf_p);
  tcase_add_test(tc_core, tests_s21_sscanf_n);
  tcase_add_test(tc_core, tests_s21_sscanf_percent);
  tcase_add_test(tc_core, tests_s21_sscanf_width);
  tcase_add_test(tc_core, tests_s21_sscanf_length_h);
  tcase_add_test(tc_core, tests_s21_sscanf_length_l);
  tcase_add_test(tc_core, tests_s21_sscanf_length_L);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* strrchr_suite(void) {
  Suite* s;
  TCase* e;

  s = suite_create("strrchr");
  e = tcase_create("e");

  tcase_add_test(e, tests_s21_strrchr_letter_exists);
  tcase_add_test(e, tests_s21_strrchr_letter_noexists);
  suite_add_tcase(s, e);

  return s;
}

Suite* strncmp_suite(void) {
  Suite* suite;
  TCase* getCase;
  suite = suite_create("strncmp");
  getCase = tcase_create("core");
  tcase_add_test(getCase, s21_strncmp_test);
  suite_add_tcase(suite, getCase);
  return suite;
}

Suite* strcmp_suite(void) {
  Suite* suite;
  TCase* getCase;
  suite = suite_create("strcmp");
  getCase = tcase_create("core");
  tcase_add_test(getCase, test_s21_strcmp);
  tcase_add_test(getCase, test_s21_strcmp_2);
  suite_add_tcase(suite, getCase);
  return suite;
}

Suite* memcmp_suite(void) {
  Suite* suite;
  TCase* getCase;
  suite = suite_create("memcmp");
  getCase = tcase_create("core");
  tcase_add_test(getCase, s21_memcmp_test);
  suite_add_tcase(suite, getCase);
  return suite;
}

Suite* len_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strlen");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strlen);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strlen_null_str);
  tcase_add_test(tc_limits, test_s21_strlen_invalid_str);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* strspn_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strpsn");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strspn);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strspn_no_matches);
  tcase_add_test(tc_limits, test_s21_strspn_all_matches);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* strcspn_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strcspn");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strcspn_no_matches);
  tcase_add_test(tc_limits, test_s21_strcspn_null_string);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* trim_suite(void) {
  Suite* suite;
  TCase* getCase;
  TCase* tc_limits;
  suite = suite_create("trim");
  getCase = tcase_create("core");
  tcase_add_test(getCase, test_s21_trim);
  tcase_add_test(getCase, test_s21_trim_2);
  tcase_add_test(getCase, test_s21_trim_numbers);
  suite_add_tcase(suite, getCase);
  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_trim_both);
  tcase_add_test(tc_limits, test_s21_trim_first_zero_str);
  tcase_add_test(tc_limits, test_s21_trim_same_str);
  tcase_add_test(tc_limits, test_s21_trim_second_zero_str);
  suite_add_tcase(suite, tc_limits);
  return suite;
}

Suite* s21_strcpy_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strcpy");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_strcpy);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strcpy_info_after_null);
  tcase_add_test(tc_limits, test_s21_strcpy_q);

  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* s21_strncpy_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("strncpy");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_strncpy);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_limits, test_s21_strncpy_info_after_null);
  tcase_add_test(tc_limits, test_s21_strncpy_zero_num);

  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* s21_memcpy_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("memcpy");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memcpy);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_core, test_s21_memcpy_info_after_null);
  tcase_add_test(tc_core, test_s21_memcpy_zero_num);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* s21_memmove_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("memmove");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memmove);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_core, test_s21_memmove_info_after_null);
  tcase_add_test(tc_core, test_s21_memmove_zero_num);
  tcase_add_test(tc_core, test_s21_memmove_new);
  suite_add_tcase(s, tc_limits);

  return s;
}

Suite* s21_memset_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_limits;

  s = suite_create("memset");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memset);
  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");
  tcase_add_test(tc_core, test_s21_memset_zero_num);
  suite_add_tcase(s, tc_limits);

  return s;
}
