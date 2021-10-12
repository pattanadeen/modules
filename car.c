#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"
#include ""

car_t *make_car(char *platep, double price, int year) {
    car_t *carp;
	if(!(carp = (car_t*)malloc(sizeof(car_t)))) {
	    printf("[Error: malloc failed allocating car]\n");
        return NULL;
    }
    strcpy(carp->plate, platep);
    carp->price = price;
    carp->year = year;
    return carp;
}

void print_car(car_t *carp) {
    printf("| Plate: %s, Price: %lf, Year: %d |\n", carp->plate, carp->price, carp->year);
}

void print_car_queue(void *qp) {
    node_t *p;
    
    printf("front --> ");
    for (p = ((node_t *)((queue_s *)qp)->front); p != NULL; p = p->next) {
        car_t * carp = (car_t *)p->element;
        printf("| %s, %lf, %d |", carp->plate, carp->price, carp->year);
    }
    printf(" <-- back\n");

    return;
}

void print_car_hash(void *htp) {
    int i;
    uint32_t hsize = ((hashtable_s *)htp)->size;
    queue_s *table = malloc(sizeof(queue_s) * hsize);
    table = ((hashtable_s *)htp)->table;

    for (i = 0; i < hsize; i++) {
        printf("%d -> ");
        print_car_queue((void *)&table[i]);
    }

    free(table);
    return;
}