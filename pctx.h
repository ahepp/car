#ifndef CAR_PCTX_H
#define CAR_PCTX_H

struct car_pctx {
        int depth;
        const char *delims;
        char *tok;
};

/**
 * Constructs a parser context with the given input and delimiters.
 */
int car_make_pctx(struct car_pctx **pctx, char *input, const char *delims);
void car_free_pctx(struct car_pctx *pctx);

#endif // CAR_PCTX_H
