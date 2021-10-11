#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "car.h"

void fn(void *elementp) {
    car_t *carp = (car_t*)elementp;
    carp->price = 420.01;
}

int main(int argc, char *argv[]) {
    // printf("%p qp\n",qp);
    // printf("%p &qp\n",&qp);
    // printf("%p back null\n",back);
    // printf("%p &back\n",&back);
    queue_t *qp = qopen();
    // printf("%p qp\n",qp);
    // printf("%p &qp\n",&qp);
    car_t *test1 = make_car("Bill",19000,2020);
    car_t *test2 = make_car("Sam",21000.75,2019);
    car_t *test3 = make_car("John",20000.25,2018);
    car_t *test4 = make_car("Fred",20000,2021);
    qput(qp, &test1);
    qput(qp, &test2);
    qput(qp, &test3);
    qput(qp, &test4);

    qapply(qp,fn);

    // printf("%p qp1\n",((queue_s *)qp)->back);

    // int ans = qput(qp, &test2);

    // car_t *c0 = (car_t*)((((queue_s *)qp)->front)->element);
    // printf("%d year front after put test2\n",(c0->year));

    // int anss = qput(qp, &test3);

    // car_t *c4 = (car_t*)((((queue_s *)qp)->back)->element);
    // printf("%d year back after put test3\n",(c4->year));

    // printf("%d\n", ans);
    // printf("%d\n", anss);

    // // printf("%p qp2\n",((queue_s *)qp)->back);
    // // printf("%p front1\n",((queue_s *)qp)->front);
    // car_t *c1 = (car_t*)((((queue_s *)qp)->front)->element);
    // printf("%s year front\n",(c1->plate));
    // void *elementpp = qget(qp);
    // car_t *cc = (car_t*)elementpp;
    // printf("%s element pp\n",(cc->plate));
    // // printf("%p front2\n",((queue_s *)qp)->front);
    // car_t *c2 = (car_t*)((((queue_s *)qp)->front)->element);
    // printf("%s year front after get2\n",(c2->plate));
    // // struct node *testnode = back;
    // // car_t *testcar = (car_t*)testnode->element;
    // // printf("%d",testcar->year);
    free(test1);
    free(test2);
    free(test3);
    free(test4);

    exit(EXIT_SUCCESS);
}