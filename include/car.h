#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <stddef.h>

#define CAR_MAX_STR_LEN 1024

#define CAR_TYPE_SYMB 0
#define CAR_TYPE_PAIR 1
#define CAR_TYPE_CHAR 2
#define CAR_TYPE_STRM 3

typedef struct car_expr car_expr;
struct car_expr {
    int type;
    char *tag;
    car_expr *next;
};

int car_parse(car_expr **e, const char *s);
int car_eval(car_expr **r, car_expr *e);
void car_expr_copy(car_expr **dst, car_expr *src, size_t depth);
void car_expr_free(car_expr *e);

#endif // CAR_CAR_H

