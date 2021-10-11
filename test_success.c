#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "car.h"

int main(int argc, char *argv[]) {
    printf("-----Test 'put' method-----\n");
    printf("[Test] Put 4 cars\n");

    // decalre cars
    car_t *car1 = make_car("1gt7117", 2100000, 2018);
    car_t *car2 = make_car("5ab2131", 2700000, 2019);
    car_t *car3 = make_car("6ff3145", 1100000, 2015);
    car_t *car4 = make_car("4pi3142", 900000, 2017);

    // open a queue
    queue_t *qp = qopen();

    // put cars into queue
    printf("Put car ");
    print_car(car1);
    qput(qp, car1);
    printf("Put car ");
    print_car(car2);
    qput(qp, car2);
    printf("Put car ");
    print_car(car3);
    qput(qp, car3);
    printf("Put car ");
    print_car(car4);
    qput(qp, car4);

    printf("[Result] ");
    print_car_queue(qp);

    printf("\n");

    printf("-----Test 'get' method-----\n");
    printf("[Test] Get 2 times\n");

    printf("Remove car ");
    print_car((car_t *)qget(qp));
    printf("Remove car ");
    print_car((car_t *)qget(qp));
    printf("[Result] ");
    print_car_queue(qp);

    free(car1);
    free(car2);
    free(car3);
    free(car4);

    exit(EXIT_SUCCESS);
}