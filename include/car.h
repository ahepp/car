#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <stddef.h>

#define CAR_MAX_STR_LEN 1024

enum car_type { CAR_TYPE_CHAR, CAR_TYPE_PAIR, CAR_TYPE_STRE, CAR_TYPE_SYMB };

struct car_expr {
        char *tag;
        enum car_type type;
        struct car_expr *next;
};

int car_parse(struct car_expr **e, const char *s);
int car_eval(struct car_expr **r, struct car_expr *e);
void car_expr_copy(struct car_expr **dst, struct car_expr *src, size_t depth);
void car_expr_free(struct car_expr *e);

#endif // CAR_CAR_H
