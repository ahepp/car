#include "car.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car_util.h"

//int car_eval(struct car_expr **r, struct car_expr *e)
//{
//        if (e) {
//                car_expr_copy(r, e, 1);
//        } else {
//                struct car_expr *tmp = malloc(sizeof(struct car_expr));
//                tmp->type = CAR_TYPE_SYMB;
//                tmp->tag = strdup("nil");
//                tmp->next = NULL;
//                *r = tmp;
//        }
//        car_log(LOG_TRACE, "evaluated \"%s\"\n", (*r)->tag);
//        return 0;
//}

//// untested refactor
//void car_expr_free(struct car_expr *e)
//{
//        while (e) {
//                struct car_expr *tmp = e;
//                e = e->next;
//                free(tmp->tag);
//                free(tmp);
//        }
//}
//// untested refactor
//void car_expr_copy(struct car_expr **dst, struct car_expr *src, size_t depth)
//{
//        struct car_expr **tail = dst;
//        while (src && depth > 0) {
//                struct car_expr *tmp = malloc(sizeof(struct car_expr));
//                tmp->type = CAR_TYPE_SYMB;
//                tmp->tag = strdup(src->tag);
//                tmp->next = NULL;
//
//                *tail = tmp;
//                tail = &(tmp->next);
//
//                src = src->next;
//                --depth;
//        }
//}
