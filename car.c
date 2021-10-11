#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"

car_t *make_car(char *platep, double price, int year) {
    car_t *carp;
	if(!(carp = (car_t*)malloc(sizeof(car_t)))) {
	    printf("[Error: malloc failed allocating car]\n");
        return NULL;
    }
    strcpy(carp->plate,platep);
    carp->price=price;
    carp->year=year;
    return carp;
}

void print_car_queue(void *qp) {
    node_t *p;
    
    printf("front --> ");
    for (p = ((node_t *)((queue_s *)qp)->front); p != NULL; p = p->next) {
        printf("| %s |", ((car_t *)p->element)->plate);
    }
    printf(" <-- back\n");

    return;
}