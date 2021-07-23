#ifndef CAR_OBJECT_H
#define CAR_OBJECT_H

#include "pctx.h"

enum car_obj_type { CAR_OBJ_TYPE_PAIR, CAR_OBJ_TYPE_SYMB };

struct car_pair {
        struct car_obj *car;
        struct car_obj *cdr;
};

struct car_obj {
        enum car_obj_type type;
        union {
                char *symb;
                struct car_pair *pair;
        };
};

/**
 * Constructs an object from the current parser context.
 */
int car_make_obj(struct car_obj **obj, struct car_pctx *pctx);
void car_free_obj(struct car_obj *obj);

#endif // CAR_OBJECT_H
