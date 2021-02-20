#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "car.h"

void test_parse_empty_succeeds_and_returns_empty_token_list() {
    const char *s = "";
    car_expr *e = NULL;

    int err = car_parse(&e, s);

    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_FALSE(e);

    car_expr_free(e);
}
void test_parse_too_long_fails() {
    char s[CAR_MAX_STR_LEN + 1];
    memset(s, 'A', CAR_MAX_STR_LEN + 1);
    car_expr *e = NULL;

    int err = car_parse(&e, s);

    TEST_ASSERT_TRUE(err);
    TEST_ASSERT_FALSE(e);

    car_expr_free(e);
}
void test_parse_single_token_succeeds_and_returns_token() {
    const char *s = "a";
    car_expr *e = NULL;

    int err = car_parse(&e, s);
    int diff = strcmp(e->tag, "a");

    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_FALSE(diff);
    TEST_ASSERT_FALSE(e->next);

    car_expr_free(e);
}
void test_parse_two_tokens_succeeds_and_returns_tokens() {
    const char *s = "a b";
    car_expr *e = NULL;

    int err = car_parse(&e, s);
    int diff_a = strcmp(e->tag, "a");

    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_FALSE(diff_a);
    TEST_ASSERT_TRUE(e->next);

    int diff_b = strcmp(e->next->tag, "b");
    TEST_ASSERT_FALSE(diff_b);
    TEST_ASSERT_FALSE(e->next->next);

    car_expr_free(e);
}

void test_parse() {
    RUN_TEST(test_parse_empty_succeeds_and_returns_empty_token_list);
    RUN_TEST(test_parse_too_long_fails);
    RUN_TEST(test_parse_single_token_succeeds_and_returns_token);
    RUN_TEST(test_parse_two_tokens_succeeds_and_returns_tokens);
}
