#include "car.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// untested refactor
static void car_expr_copy(car_expr **dst, car_expr *src, size_t depth) {
    car_expr **tail = dst;
    while(src && depth > 0) {
        car_expr *tmp = malloc(sizeof(car_expr));
        tmp->tag = strdup(src->tag);
        tmp->next = NULL;

        *tail = tmp;
        tail = &(tmp->next);
        
        src = src->next;
        --depth;
    }
}

int car_parse(car_expr **e, const char *s) {
    size_t len = strnlen(s, CAR_MAX_STR_LEN);
    if(len + 1 > CAR_MAX_STR_LEN)
        return 1;

    car_expr **tail = e;
    char *smut = strdup(s);
    const char *delims = " ";
    char *tok = strtok(smut, delims);
    while(tok) {
        fprintf(stderr, "\"%s\" ", tok);

        car_expr *tmp = malloc(sizeof(car_expr));
        tmp->tag = strdup(tok);
        tmp->next = NULL;

        *tail = tmp;
        tail = &(tmp->next);
        tok = strtok(NULL, delims);
    }
    fprintf(stderr, "\n");

    free(smut);
    return 0;
}

int car_eval(car_expr **r, car_expr *e) {
    if(e) {
        car_expr_copy(r, e, 1);
        return 0;
    }
    return 1;
}

void car_expr_free(car_expr *e) {
    while(e) {
        car_expr *tmp = e;
        e = e->next;
        free(tmp->tag);
        free(tmp);
    }
}
