#include "unity.h"
#include "car.h"
#include <stdlib.h>
#include <string.h>

static void del_exp(car_exp *e) {
    while(e) {
        car_exp *tmp = e;
        e = e->next;
        free(tmp->tag);
        free(tmp);
    }
}

void setUp() {
}
void tearDown() {
}

void test_parse_empty_succeeds_and_returns_empty_token_list() {
    const char *s = "";
    car_exp *e = NULL;

    int err = car_parse(&e, s);

    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_FALSE(e);

    del_exp(e);
}
void test_parse_too_long_fails() {
    char s[CAR_MAX_STR_LEN + 1];
    memset(s, 'A', CAR_MAX_STR_LEN + 1);
    car_exp *e = NULL;

    int err = car_parse(&e, s);

    TEST_ASSERT_TRUE(err);
    TEST_ASSERT_FALSE(e);

    del_exp(e);
}
void test_parse_single_token_succeeds_and_returns_token() {
    const char *s = "a";
    car_exp *e = NULL;

    int err = car_parse(&e, s);
    int diff = strcmp(e->tag, "a");

    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_FALSE(diff);
    TEST_ASSERT_FALSE(e->next);

    del_exp(e);
}
void test_parse_two_tokens_succeeds_and_returns_tokens() {
    const char *s = "a b";
    car_exp *e = NULL;

    int err = car_parse(&e, s);
    int diff_a = strcmp(e->tag, "a");

    TEST_ASSERT_FALSE(err);
    TEST_ASSERT_FALSE(diff_a);
    TEST_ASSERT_TRUE(e->next);

    int diff_b = strcmp(e->next->tag, "b");
    TEST_ASSERT_FALSE(diff_b);
    TEST_ASSERT_FALSE(e->next->next);

    del_exp(e);
}


int main() {
    UNITY_BEGIN();

    RUN_TEST(test_parse_empty_succeeds_and_returns_empty_token_list);
    RUN_TEST(test_parse_too_long_fails);
    RUN_TEST(test_parse_single_token_succeeds_and_returns_token);
    RUN_TEST(test_parse_two_tokens_succeeds_and_returns_tokens);
    
    return UNITY_END();
}
