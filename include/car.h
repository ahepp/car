#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <stddef.h>

#define CAR_MAX_STR_LEN 1024

typedef enum car_type {
    CAR_TYPE_CHAR,
    CAR_TYPE_PAIR,
    CAR_TYPE_STRE,
    CAR_TYPE_SYMB
} car_type;

typedef struct car_expr car_expr;
struct car_expr {
    char *tag;
    car_type type;
    car_expr *next;
};

int car_parse(car_expr **e, const char *s);
int car_eval(car_expr **r, car_expr *e);
void car_expr_copy(car_expr **dst, car_expr *src, size_t depth);
void car_expr_free(car_expr *e);

#endif // CAR_CAR_H

