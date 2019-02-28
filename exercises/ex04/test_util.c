
#include <stdio.h>
#include "minunit.h"
#include "util.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>


int tests_run = 0;

static char * test_1() {
  char *res = Calloc(0, 1);
    char *message = "test1 failed: (\"icmpcode_v4\", \"0\") should return \"network unreachable\"";
    mu_assert(message, strcmp(res, "network unreachable") == 0);
    return NULL;
}

static char *all_1_tests() {
	mu_run_test(test_1);

	return NULL;
}

int main() {
    char *result = all_1_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
