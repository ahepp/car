#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "car_parse.h"
#include "car_util.h"

void test_parse_tok_empty_fails_and_returns_null()
{
        const char *s = "";
        struct car_expr *e = NULL;

        char *smut = strdup(s);
        const char *delims = " ";
        char *tok = strtok(smut, delims);

        int err = car_parse_tok(0, &e, tok, delims);

        TEST_ASSERT_TRUE(err);
        TEST_ASSERT_FALSE(e);

        free(smut);
}
void test_parse_tok_single_token_succeeds_and_returns_symbol()
{
        const char *s = "a";
        struct car_expr *e = NULL;

        char *smut = strdup(s);
        const char *delims = " ";
        char *tok = strtok(smut, delims);

        int err = car_parse_tok(0, &e, tok, delims);

        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(e->type, CAR_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(e->csymb, "a");

        car_expr_free(e);
        free(smut);
}
void test_parse_tok_two_tokens_fails_and_returns_first_symbol()
{
        const char *s = "a b";
        struct car_expr *e = NULL;

        char *smut = strdup(s);
        const char *delims = " ";
        char *tok = strtok(smut, delims);

        int err = car_parse_tok(0, &e, tok, delims);

        TEST_ASSERT_TRUE(err);
        TEST_ASSERT_EQUAL_INT(e->type, CAR_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(e->csymb, "a");

        car_expr_free(e);
        free(smut);
}

void test_parse_tok_pair_of_tokens_succeeds_and_returns_pair_of_symbols()
{
        const char *s = ". a b";
        struct car_expr *e = NULL;

        char *smut = strdup(s);
        const char *delims = " ";
        char *tok = strtok(smut, delims);

        int err = car_parse_tok(0, &e, tok, delims);
        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(e->type, CAR_TYPE_PAIR);

        struct car_expr *car = e->cpair->car;
        TEST_ASSERT_EQUAL_INT(car->type, CAR_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(car->csymb, "a");

        struct car_expr *cdr = e->cpair->cdr;
        TEST_ASSERT_EQUAL_INT(cdr->type, CAR_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(cdr->csymb, "b");

        car_expr_free(e);
        free(smut);
}

void test_parse_too_long_fails()
{
        char s[CAR_MAX_STR_LEN + 1];
        memset(s, 'A', CAR_MAX_STR_LEN + 1);
        struct car_expr *e = NULL;

        int err = car_parse(&e, s);

        TEST_ASSERT_TRUE(err);
        TEST_ASSERT_FALSE(e);
}

void test_parse()
{
        RUN_TEST(test_parse_tok_empty_fails_and_returns_null);
        RUN_TEST(test_parse_tok_single_token_succeeds_and_returns_symbol);
        RUN_TEST(test_parse_tok_two_tokens_fails_and_returns_first_symbol);
        RUN_TEST(
                test_parse_tok_pair_of_tokens_succeeds_and_returns_pair_of_symbols);
        RUN_TEST(test_parse_too_long_fails);
}
