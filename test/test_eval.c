#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "car.h"

//static int eval_str_returns_no_error(struct car_expr **r, const char *s)
//{
//        struct car_expr *e = NULL;
//        car_parse(&e, s);
//        int err = car_eval(r, e);
//        car_expr_free(e);
//        return !err;
//}
//
//void test_eval_empty_succeeds_and_returns_symbol_nil()
//{
//        struct car_expr *r = NULL;
//
//        TEST_ASSERT_TRUE(eval_str_returns_no_error(&r, ""));
//        TEST_ASSERT_EQUAL_INT(r->type, CAR_TYPE_SYMB);
//        TEST_ASSERT_EQUAL_STRING(r->tag, "nil");
//
//        car_expr_free(r);
//}
//
//void test_eval_t_succeeds_and_returns_symbol_t()
//{
//        struct car_expr *r = NULL;
//
//        TEST_ASSERT_TRUE(eval_str_returns_no_error(&r, "t"));
//        TEST_ASSERT_EQUAL_INT(r->type, CAR_TYPE_SYMB);
//        TEST_ASSERT_EQUAL_STRING(r->tag, "t");
//
//        car_expr_free(r);
//}
//
//void test_eval_nil_succeeds_and_returns_symbol_nil()
//{
//        struct car_expr *r = NULL;
//
//        TEST_ASSERT_TRUE(eval_str_returns_no_error(&r, "nil"));
//        TEST_ASSERT_EQUAL_INT(r->type, CAR_TYPE_SYMB);
//        TEST_ASSERT_EQUAL_STRING(r->tag, "nil");
//
//        car_expr_free(r);
//}
//
//void test_eval_o_succeeds_and_returns_symbol_o()
//{
//        struct car_expr *r = NULL;
//
//        TEST_ASSERT_TRUE(eval_str_returns_no_error(&r, "o"));
//        TEST_ASSERT_EQUAL_INT(r->type, CAR_TYPE_SYMB);
//        TEST_ASSERT_EQUAL_STRING(r->tag, "o");
//
//        car_expr_free(r);
//}
//
//void test_eval_apply_succeeds_and_returns_symbol_apply()
//{
//        struct car_expr *r = NULL;
//
//        TEST_ASSERT_TRUE(eval_str_returns_no_error(&r, "apply"));
//        TEST_ASSERT_EQUAL_INT(r->type, CAR_TYPE_SYMB);
//        TEST_ASSERT_EQUAL_STRING(r->tag, "apply");
//
//        car_expr_free(r);
//}
//
//void test_eval()
//{
//        RUN_TEST(test_eval_empty_succeeds_and_returns_symbol_nil);
//        RUN_TEST(test_eval_t_succeeds_and_returns_symbol_t);
//        RUN_TEST(test_eval_nil_succeeds_and_returns_symbol_nil);
//        RUN_TEST(test_eval_o_succeeds_and_returns_symbol_o);
//        RUN_TEST(test_eval_apply_succeeds_and_returns_symbol_apply);
//}
