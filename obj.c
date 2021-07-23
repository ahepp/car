#include "obj.h"

#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "pctx.h"

static int set_obj_type(struct car_obj *obj, struct car_pctx *pctx)
{
        // TODO: Use safer string functions.
        if (!strcmp(pctx->tok, ".")) {
                obj->type = CAR_OBJ_TYPE_PAIR;
                pctx->tok = strtok(NULL, pctx->delims);
        } else {
                obj->type = CAR_OBJ_TYPE_SYMB;
        }
        return 0;
}
int car_make_obj(struct car_obj **obj, struct car_pctx *pctx)
{
        car_log(LOG_TRACE, "Depth is %d.\n", pctx->depth);
        car_log(LOG_TRACE, "Making object from token \"%s\".\n", pctx->tok);

        if (pctx->tok == NULL) {
                car_log(LOG_ERROR,
                        "Attempted to make object from empty string.\n");
                return 1;
        }

        struct car_obj *tmp = malloc(sizeof(struct car_obj));
        set_obj_type(tmp, pctx);

        int err = 0;
        switch (tmp->type) {
        default:
                car_log(LOG_ERROR, "Attempted to make an unknown type.");
                exit(1);
        case CAR_OBJ_TYPE_PAIR:
                car_log(LOG_TRACE, "Constructing pair.\n", pctx->tok);
                tmp->pair = malloc(sizeof(struct car_pair));
                pctx->depth++;
                err |= car_make_obj(&tmp->pair->car, pctx);
                err |= car_make_obj(&tmp->pair->cdr, pctx);
                pctx->depth--;
                break;
        case CAR_OBJ_TYPE_SYMB:
                car_log(LOG_TRACE, "Constructing symbol \"%s\".\n", pctx->tok);
                tmp->symb = strdup(pctx->tok);
                pctx->tok = strtok(NULL, pctx->delims);
                break;
        }

        if (!err) {
                *obj = tmp;
        } else {
                // TODO: Clean up in case of failure.
        }
        return err;
}

static void free_pair(struct car_pair *pair)
{
        car_free_obj(pair->car);
        car_free_obj(pair->cdr);
}

void car_free_obj(struct car_obj *obj)
{
        switch (obj->type) {
        default:
                car_log(LOG_ERROR, "Attempted to free an unknown type.");
                exit(1);
        case CAR_OBJ_TYPE_PAIR:
                free_pair(obj->pair);
                free(obj->pair);
                break;
        case CAR_OBJ_TYPE_SYMB:
                free(obj->symb);
                break;
        }
        free(obj);
}
