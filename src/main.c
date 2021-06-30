#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "car.h"

int main(int arg, char** argv) {
    while(1) {
        char in[CAR_MAX_STR_LEN];
        fputs("car> ", stdout);
        fgets(in, CAR_MAX_STR_LEN, stdin);
        in[strcspn(in, "\n")] = 0; // strip newline

        car_expr *e;
        car_expr *r;
        car_parse(&e, in);
        car_eval(&r, e);
        if(r)
            fputs(r->tag, stdout);
        fputc('\n', stdout);

        car_expr_free(e);
        car_expr_free(r);
    }
    return 0;
}
