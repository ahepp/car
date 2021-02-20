#include "car.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car_util.h"

int car_parse(car_expr **e, const char *s) {
    size_t len = strnlen(s, CAR_MAX_STR_LEN);
    if(len + 1 > CAR_MAX_STR_LEN)
        return 1;

    car_expr **tail = e;
    char *smut = strdup(s);
    const char *delims = " ";
    char *tok = strtok(smut, delims);
    while(tok) {
        car_log(LOG_TRACE, "parsed \"%s\"\n", tok);

        car_expr *tmp = malloc(sizeof(car_expr));
        tmp->tag = strdup(tok);
        tmp->next = NULL;

        *tail = tmp;
        tail = &(tmp->next);
        tok = strtok(NULL, delims);
    }

    free(smut);
    return 0;
}

int car_eval(car_expr **r, car_expr *e) {
    if(e) {
        car_expr_copy(r, e, 1);
    } else {
        car_expr *tmp = malloc(sizeof(car_expr));
        tmp->tag = strdup("nil");
        tmp->next = NULL;
        *r = tmp;
    }
    car_log(LOG_TRACE, "evaluated \"%s\"\n", (*r)->tag);
    return 0;
}

// untested refactor
void car_expr_free(car_expr *e) {
    while(e) {
        car_expr *tmp = e;
        e = e->next;
        free(tmp->tag);
        free(tmp);
    }
}
// untested refactor
void car_expr_copy(car_expr **dst, car_expr *src, size_t depth) {
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
