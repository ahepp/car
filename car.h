#ifndef CAR_CAR_H
#define CAR_CAR_H

#define CAR_MAX_STR_LEN 1024

typedef struct car_exp car_exp;
struct car_exp {
    char *tag;
    car_exp *next;
};

int car_parse(car_exp **e, const char *s);

#endif // CAR_CAR_H

