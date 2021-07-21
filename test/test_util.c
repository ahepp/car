#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "car_util.h"

void test_expr_free_symbol_returns()
{
        struct car_expr *e;
        e = malloc(sizeof(struct car_expr));
        e->type = CAR_TYPE_SYMB;
        e->csymb = strdup("a");
        car_expr_free(e);
}

void test_util()
{
        RUN_TEST(test_expr_free_symbol_returns);
}
