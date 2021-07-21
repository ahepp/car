#include "car_util.h"

#include <stdlib.h>

#include "car.h"
#include "car_log.h"

void car_expr_free(struct car_expr *e)
{
        switch (e->type) {
        default:
                car_log(LOG_ERROR, "Attempted to free an unknown type.");
                exit(1);
        case CAR_TYPE_PAIR:
                car_expr_free(e->cpair->car);
                car_expr_free(e->cpair->cdr);
                free(e->cpair);
                break;
        case CAR_TYPE_SYMB:
                free(e->csymb);
                e->csymb = NULL;
                break;
        }
        free(e);
}
