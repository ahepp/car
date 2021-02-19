#include "car.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int car_parse(car_exp **e, const char *s) {
    size_t len = strnlen(s, CAR_MAX_STR_LEN);
    if(len + 1 > CAR_MAX_STR_LEN)
        return 1;

    car_exp **tail = e;
    char *smut = strdup(s);
    const char *delims = " ";
    char *tok = strtok(smut, delims);
    while(tok) {
        fprintf(stdout, "\"%s\" ", tok);

        car_exp *tmp = malloc(sizeof(car_exp));
        tmp->tag = strdup(tok);
        tmp->next = NULL;

        *tail = tmp;
        tail = &(tmp->next);
        tok = strtok(NULL, delims);
    }
    fprintf(stdout, "\n");

    free(smut);
    return 0;
}
