#include "pctx.h"

#include <stdlib.h>
#include <string.h>

int car_make_pctx(struct car_pctx **pctx, char *input, const char *delims)
{
        struct car_pctx *tmp = malloc(sizeof(struct car_pctx));
        tmp->depth = 0;
        tmp->delims = delims;
        tmp->tok = strtok(input, delims);
        *pctx = tmp;
        return 0;
}
void car_free_pctx(struct car_pctx *pctx)
{
        free(pctx);
}
