#include "obj.h"

#include <stdlib.h>
#include <string.h>

#include "unity/unity.h"

#include "pctx.h"

void make_obj_empty_input_error()
{
        char *s = strdup("");
        struct car_obj *obj;
        struct car_pctx *pctx;
        car_make_pctx(&pctx, s, " ");

        int err = car_make_obj(&obj, pctx);
        TEST_ASSERT_TRUE(err);

        car_free_pctx(pctx);
        free(s);
}
void make_obj_symbol()
{
        char *s = strdup("a");
        struct car_obj *obj;
        struct car_pctx *pctx;
        car_make_pctx(&pctx, s, " ");

        int err = car_make_obj(&obj, pctx);
        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(obj->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(obj->symb, "a");

        car_free_obj(obj);
        car_free_pctx(pctx);
        free(s);
}
void make_obj_two_tokens_ignores_extra()
{
        char *s = strdup("a b");
        struct car_obj *obj = NULL;
        struct car_pctx *pctx;
        car_make_pctx(&pctx, s, " ");

        int err = car_make_obj(&obj, pctx);
        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(obj->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(obj->symb, "a");

        car_free_obj(obj);
        car_free_pctx(pctx);
        free(s);
}

void make_obj_pair()
{
        char *s = strdup(". a b");
        struct car_obj *obj = NULL;
        struct car_pctx *pctx;
        car_make_pctx(&pctx, s, " ");

        int err = car_make_obj(&obj, pctx);

        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(obj->type, CAR_OBJ_TYPE_PAIR);

        struct car_obj *car = obj->pair->car;
        TEST_ASSERT_EQUAL_INT(car->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(car->symb, "a");

        struct car_obj *cdr = obj->pair->cdr;
        TEST_ASSERT_EQUAL_INT(cdr->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(cdr->symb, "b");

        car_free_obj(obj);
        car_free_pctx(pctx);
        free(s);
}

void make_obj_chained_pair()
{
        char *s = strdup(". a . b c");
        struct car_obj *obj = NULL;
        struct car_pctx *pctx;
        car_make_pctx(&pctx, s, " ");

        int err = car_make_obj(&obj, pctx);

        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(obj->type, CAR_OBJ_TYPE_PAIR);

        struct car_obj *car = obj->pair->car;
        TEST_ASSERT_EQUAL_INT(car->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(car->symb, "a");

        struct car_obj *cdr = obj->pair->cdr;
        TEST_ASSERT_EQUAL_INT(cdr->type, CAR_OBJ_TYPE_PAIR);

        struct car_obj *cdar = cdr->pair->car;
        TEST_ASSERT_EQUAL_INT(cdar->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(cdar->symb, "b");

        struct car_obj *cddr = cdr->pair->cdr;
        TEST_ASSERT_EQUAL_INT(cddr->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(cddr->symb, "c");

        car_free_obj(obj);
        car_free_pctx(pctx);
        free(s);
}

void make_obj_nested_pair()
{
        char *s = strdup(". . a b c");
        struct car_obj *obj = NULL;
        struct car_pctx *pctx;
        car_make_pctx(&pctx, s, " ");

        int err = car_make_obj(&obj, pctx);

        TEST_ASSERT_FALSE(err);
        TEST_ASSERT_EQUAL_INT(obj->type, CAR_OBJ_TYPE_PAIR);

        struct car_obj *car = obj->pair->car;
        TEST_ASSERT_EQUAL_INT(car->type, CAR_OBJ_TYPE_PAIR);

        struct car_obj *caar = car->pair->car;
        TEST_ASSERT_EQUAL_INT(caar->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(caar->symb, "a");

        struct car_obj *cadr = car->pair->cdr;
        TEST_ASSERT_EQUAL_INT(cadr->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(cadr->symb, "b");

        struct car_obj *cdr = obj->pair->cdr;
        TEST_ASSERT_EQUAL_INT(cdr->type, CAR_OBJ_TYPE_SYMB);
        TEST_ASSERT_EQUAL_STRING(cdr->symb, "c");

        car_free_obj(obj);
        car_free_pctx(pctx);
        free(s);
}

void test_obj()
{
        RUN_TEST(make_obj_empty_input_error);
        RUN_TEST(make_obj_symbol);
        RUN_TEST(make_obj_two_tokens_ignores_extra);
        RUN_TEST(make_obj_pair);
        RUN_TEST(make_obj_chained_pair);
        RUN_TEST(make_obj_nested_pair);
}
