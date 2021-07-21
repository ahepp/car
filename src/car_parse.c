#include "car.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car_log.h"
#include "car_util.h"

int car_parse_tok(int depth, struct car_expr **e, char *tok, const char *delims)
{
        if (tok) {
                car_log(LOG_TRACE, "Depth is %d.\n", depth);
                car_log(LOG_TRACE, "Encountered token \"%s\".\n", tok);
                struct car_expr *tmp = malloc(sizeof(struct car_expr));

                if (!strcmp(tok, ".")) { // TODO strncmp
                        car_log(LOG_TRACE, "Constructing pair.\n");

                        tmp->type = CAR_TYPE_PAIR;
                        tmp->cpair = malloc(sizeof(struct car_pair));
                        int err = 0;
                        char *next_tok;

                        next_tok = strtok(NULL, delims);
                        err = car_parse_tok(depth + 1, &tmp->cpair->car,
                                            next_tok, delims);

                        if (err) {
                                car_log(LOG_ERROR,
                                        "Error parsing first element of pair.");
                                return err;
                        }

                        next_tok = strtok(NULL, delims);
                        err = car_parse_tok(depth + 1, &tmp->cpair->cdr,
                                            next_tok, delims);

                        *e = tmp;

                        next_tok = strtok(NULL, delims);
                        int tokens_remain = (next_tok != NULL);

                        return err || ((depth == 0) && tokens_remain);
                } else {
                        car_log(LOG_TRACE, "Constructing symbol \"%s\".\n",
                                tok);
                        tmp->type = CAR_TYPE_SYMB;
                        tmp->csymb = strdup(tok);
                        *e = tmp;

                        if (depth == 0) {
                                char *next_tok;
                                next_tok = strtok(NULL, delims);
                                int tokens_remain = (next_tok != NULL);
                                return tokens_remain;
                        }
                        return 0;
                }
        }
        return 1;
}

int car_parse(struct car_expr **e, const char *s)
{
        //size_t len = strnlen(s, CAR_MAX_STR_LEN);
        //if (len + 1 > CAR_MAX_STR_LEN) {
        //        car_log(LOG_ERROR, "Failed to parse input longer than CAR_MAX_STR_LEN.\n");
        //        return 1;
        //}

        //int err = 0;

        //char *smut = strdup(s);
        //const char *delims = " ";
        //char *tok = strtok(smut, delims);
        //car_parse_tok(tok, delims);

        //free(smut);
        //return err;
        return 1;
}

//int car_eval(struct car_expr **r, struct car_expr *e)
//{
//        if (e) {
//                car_expr_copy(r, e, 1);
//        } else {
//                struct car_expr *tmp = malloc(sizeof(struct car_expr));
//                tmp->type = CAR_TYPE_SYMB;
//                tmp->tag = strdup("nil");
//                tmp->next = NULL;
//                *r = tmp;
//        }
//        car_log(LOG_TRACE, "evaluated \"%s\"\n", (*r)->tag);
//        return 0;
//}

//// untested refactor
//void car_expr_free(struct car_expr *e)
//{
//        while (e) {
//                struct car_expr *tmp = e;
//                e = e->next;
//                free(tmp->tag);
//                free(tmp);
//        }
//}
//// untested refactor
//void car_expr_copy(struct car_expr **dst, struct car_expr *src, size_t depth)
//{
//        struct car_expr **tail = dst;
//        while (src && depth > 0) {
//                struct car_expr *tmp = malloc(sizeof(struct car_expr));
//                tmp->type = CAR_TYPE_SYMB;
//                tmp->tag = strdup(src->tag);
//                tmp->next = NULL;
//
//                *tail = tmp;
//                tail = &(tmp->next);
//
//                src = src->next;
//                --depth;
//        }
//}
