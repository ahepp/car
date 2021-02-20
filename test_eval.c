#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "car.h"

void test_eval_null_expr_fails() {
    car_expr *e = NULL;
    car_expr *r = NULL;

    int err = car_eval(&r, e);
    TEST_ASSERT_TRUE(err);

    car_expr_free(r);
}

void test_eval_number_succeeds_and_returns_number() {
    car_expr *e = NULL;
    car_expr *r = NULL;
    car_parse(&e, "1");

    int err = car_eval(&r, e);
    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_TRUE(e);

    int diff = strcmp(e->tag, "1");
    TEST_ASSERT_FALSE(diff);

    TEST_ASSERT_FALSE(e->next);

    car_expr_free(e);
    car_expr_free(r);
}

void test_eval_add_two_numbers_succeeds_and_returns_sum() {
    car_expr *e = NULL;
    car_expr *r = NULL;
    car_parse(&e, "+ 1 2");

    int err = car_eval(&r, e);
    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_TRUE(0);

    car_expr_free(e);
    car_expr_free(r);
}

void test_eval() {
    RUN_TEST(test_eval_null_expr_fails);
    RUN_TEST(test_eval_number_succeeds_and_returns_number);
    RUN_TEST(test_eval_add_two_numbers_succeeds_and_returns_sum);
}

