#ifndef CAR_CAR_H
#define CAR_CAR_H

#define CAR_MAX_STR_LEN 1024

typedef struct car_expr car_expr;
struct car_expr {
    char *tag;
    car_expr *next;
};

int car_parse(car_expr **e, const char *s);
int car_eval(car_expr **r, car_expr *e);
void car_expr_free(car_expr *e);

#endif // CAR_CAR_H

