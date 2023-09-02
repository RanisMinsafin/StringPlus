#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"

#define BS 400
#define N1 1
#define N2 0
#define N3 -1
#define N4 INT_MAX
#define N5 INT_MIN
#define N6 SHRT_MAX
#define N7 SHRT_MIN
#define N8 LONG_MAX
#define N9 LONG_MIN
#define N10 123.5678
#define N11 -123.5678
#define N12 UINT_MAX
#define N13 'A'
#define N14 USHRT_MAX
#define N15 ULONG_MAX
#define N16 'Q'
#define N17 'a'
#define N18 'A'
#define N33 123

Suite* suit_sprintf_d(void);
Suite* suit_sprintf_hd(void);
Suite* suit_sprintf_ld(void);
Suite* suit_sprintf_u(void);
Suite* suit_sprintf_hu(void);
Suite* suit_sprintf_lu(void);
Suite* suit_sprintf_f(void);
Suite* suit_sprintf_Lf(void);

Suite* suit_sprintf_e(void);
Suite* suit_sprintf_Le(void);
Suite* suit_sprintf_E(void);
Suite* suit_sprintf_LE(void);

Suite* suit_sprintf_g(void);
Suite* suit_sprintf_Lg(void);
Suite* suit_sprintf_G(void);
Suite* suit_sprintf_LG(void);

Suite* suit_sprintf_i(void);
Suite* suit_sprintf_hi(void);
Suite* suit_sprintf_li(void);

Suite* suit_sprintf_o(void);
Suite* suit_sprintf_ho(void);
Suite* suit_sprintf_lo(void);

Suite* suit_sprintf_x(void);
Suite* suit_sprintf_hx(void);
Suite* suit_sprintf_lx(void);

Suite* suit_sprintf_X(void);
Suite* suit_sprintf_hX(void);
Suite* suit_sprintf_lX(void);

Suite* suit_sprintf_p(void);
Suite* suit_sprintf_prc(void);
Suite* suit_sprintf_c(void);
Suite* suit_sprintf_s(void);
Suite* suit_sprintf_n(void);

// all functions

Suite* insert_suite(void);
Suite* memchr_suite(void);
Suite* to_upper_suite(void);
Suite* to_lower_suite(void);
Suite* strerror_suite(void);
Suite* strncat_suite(void);
Suite* strcat_suite(void);
Suite* strtok_suite(void);
Suite* strchr_suite(void);
Suite* strpbrk_suite(void);
Suite* strstr_suite(void);
Suite* sscanf_suite(void);
Suite* strrchr_suite(void);
Suite* strncmp_suite(void);
Suite* strcmp_suite(void);
Suite* memcmp_suite(void);
Suite* len_suite(void);
Suite* strspn_suite(void);
Suite* strcspn_suite(void);
Suite* s21_strcpy_suite(void);
Suite* s21_strncpy_suite(void);
Suite* s21_memcpy_suite(void);
Suite* s21_memmove_suite(void);
Suite* s21_memset_suite(void);
Suite* trim_suite(void);

void run_tests(void);
void run_testcase(Suite* testcase);

#endif  // SRC_TEST_H_
