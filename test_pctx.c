#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "car_parse.h"
#include "car_util.h"

int car_make_pctx(struct car_pctx **pctx, char *s, const char *delims)
{
        struct car_pctx *tmp = malloc(sizeof(struct car_pctx));
        tmp->tok = strtok(s, delims);
        return 0;
}

void make_pctx_empty_delims_error()
{
        char *s = strdup("");
        struct car_pctx *pctx;

        int err = car_make_pctx(&pctx, s, "");
        TEST_ASSERT_TRUE(err);

        free(s);
}
void make_pctx_space_delims()
{
        char *s = strdup("");
        struct car_pctx *pctx;

        int err = car_make_pctx(&pctx, s, " ");
        TEST_ASSERT_FALSE(err);

        free(s);
}
// TODO: These tests are *woefully* incomplete.

void test()
{
        RUN_TEST(make_pctx_empty_delims_error);
        RUN_TEST(make_pctx_space_delims);
}
