#ifndef CAR_PARSE_H
#define CAR_PARSE_H

#include "car.h"

int car_parse_tok(int depth, struct car_expr **e, char *tok,
                  const char *delims);
int car_parse(struct car_expr **e, const char *s);

#endif // CAR_PARSE_H
