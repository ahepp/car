#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "obj.h"
#include "pctx.h"

#define CAR_MAX_STR_LEN 1024

static int obj_to_string_helper(struct car_obj *obj, char *s, size_t mark)
{
        size_t len;
        switch (obj->type) {
        default:
                car_log(LOG_ERROR, "Attempted to free an unknown type.");
                exit(1);
        case CAR_OBJ_TYPE_SYMB:
                len = strlen(obj->symb);
                for (size_t i = 0; i < len; ++i) {
                        s[mark++] = obj->symb[i];
                }
                s[mark++] = ' ';
                break;
        case CAR_OBJ_TYPE_PAIR:
                s[mark++] = '.';
                s[mark++] = ' ';
                mark = obj_to_string_helper(obj->pair->car, s, mark);
                mark = obj_to_string_helper(obj->pair->cdr, s, mark);
                break;
        }
        return mark;
}
static void obj_to_string(struct car_obj *obj, char *s)
{
        obj_to_string_helper(obj, s, 0);
}

int main(int arg, char **argv)
{
        while (1) {
                char in[CAR_MAX_STR_LEN];
                fputs("car> ", stdout);
                fgets(in, CAR_MAX_STR_LEN, stdin);
                in[strcspn(in, "\n")] = 0; // strip newline

                int err = 0;
                struct car_pctx *pctx;
                err = car_make_pctx(&pctx, in, " ");

                struct car_obj *obj;
                err = car_make_obj(&obj, pctx);

                if (err) {
                        car_log(LOG_ERROR, "Failed to parse s-expression.\n");
                        continue;
                }

                char out[CAR_MAX_STR_LEN] = "";
                obj_to_string(obj, out);
                fputs(out, stdout);
                fputc('\n', stdout);
        }
        return 1;
}
