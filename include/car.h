#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <stddef.h>

#define CAR_MAX_STR_LEN 1024

enum car_type { CAR_TYPE_CHAR, CAR_TYPE_PAIR, CAR_TYPE_STREAM, CAR_TYPE_SYMB };

struct car_char {
        char dummy;
};

struct car_pair {
        struct car_expr *car;
        struct car_expr *cdr;
};

struct car_stream {
        char dummy;
};

struct car_expr {
        enum car_type type;
        union {
                char *csymb;
                struct car_char *cchar;
                struct car_pair *cpair;
                struct car_stream *cstream;
        };
};

//int car_eval(struct car_expr **r, struct car_expr *e);
//void car_expr_copy(struct car_expr **dst, struct car_expr *src, size_t depth);
//void car_expr_free(struct car_expr *e);

#endif // CAR_CAR_H
