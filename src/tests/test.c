#include "test.h"

int main(void) {
  Suite *list_cases[] = {suit_sprintf_d(),
                         suit_sprintf_hd(),
                         suit_sprintf_ld(),
                         suit_sprintf_u(),
                         suit_sprintf_hu(),
                         suit_sprintf_lu(),
                         suit_sprintf_f(),
                         suit_sprintf_Lf(),
                         suit_sprintf_e(),
                         suit_sprintf_Le(),
                         suit_sprintf_E(),
                         suit_sprintf_LE(),
                         suit_sprintf_g(),
                         suit_sprintf_Lg(),
                         suit_sprintf_G(),
                         suit_sprintf_LG(),
                         suit_sprintf_i(),
                         suit_sprintf_hi(),
                         suit_sprintf_li(),
                         suit_sprintf_o(),
                         suit_sprintf_ho(),
                         suit_sprintf_lo(),
                         suit_sprintf_x(),
                         suit_sprintf_hx(),
                         suit_sprintf_lx(),
                         suit_sprintf_X(),
                         suit_sprintf_hX(),
                         suit_sprintf_lX(),
                         suit_sprintf_p(),
                         suit_sprintf_prc(),
                         suit_sprintf_c(),
                         suit_sprintf_s(),
                         suit_sprintf_n(),
                         insert_suite(),
                         memchr_suite(),
                         to_upper_suite(),
                         to_lower_suite(),
                         strerror_suite(),
                         strncat_suite(),
                         strcat_suite(),
                         strtok_suite(),
                         strchr_suite(),
                         strpbrk_suite(),
                         strstr_suite(),
                         sscanf_suite(),
                         strrchr_suite(),
                         strncmp_suite(),
                         strcmp_suite(),
                         memcmp_suite(),
                         len_suite(),
                         strspn_suite(),
                         strcspn_suite(),
                         s21_strcpy_suite(),
                         s21_strncpy_suite(),
                         s21_memcpy_suite(),
                         s21_memmove_suite(),
                         s21_memset_suite(),
                         trim_suite(),
                         NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    Suite *s = list_cases[i];
    SRunner *runner = srunner_create(s);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}
