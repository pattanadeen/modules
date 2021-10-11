#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "car.h"

int main(int argc, char *argv[]) {
    printf("-----Test 'put' method-----\n");
    printf("[Test] Create cars\n");

    car_t *car1 = make_car("1gt7117", 2100000, 2018);
    car_t *car2 = make_car("5ab2131", 2700000, 2019);
    car_t *car3 = make_car("6ff3145", 1100000, 2015);
    car_t *car4 = make_car("4pi3142", 900000, 2017);

    printf("[Test] Open queue\n");
    queue_t *qp = qopen();

    printf("[Test] put car\n");
    qput(qp, car1);
    qput(qp, car2);
    qput(qp, car3);
    qput(qp, car4);
    
    print_car_queue(qp);

    free(car1);
    free(car2);
    free(car3);
    free(car4);

    exit(EXIT_SUCCESS);
}