/* queue.c --- test
 * 
 * 
 * Author: Chayisara Sakunkoo
 * Created: Sat Oct  9 16:57:46 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "queue.h"

#define MAXREG 10

typedef struct car {
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;
}  car_t;

typedef struct node {
 	struct node *next;
 	void *element;
} node_t;

typedef struct queue {
 	struct node *front;
    struct node *back;
} queue_s;

queue_t* qopen(void){
    queue_s *qs = malloc(sizeof(queue_s));
    qs->front = NULL;
    qs->back = NULL;
    return ((queue_t*)qs);
}

int32_t qput(queue_t *qp, void *elementp){
    if(qp == NULL || elementp == NULL){
        return 1;
    }
    else{
        if(((queue_s *)qp)->back == NULL){
            struct node *newNode = malloc(sizeof(node_t));
            newNode->next = NULL;
            newNode->element = elementp;
            ((queue_s *)qp)->back = newNode;
            ((queue_s *)qp)->front = newNode;
            return 0;
        }
        else{
            struct node *newNode = malloc(sizeof(node_t));
            newNode->next = NULL;
            newNode->element = elementp;
            (((queue_s *)qp)->back)->next = newNode;
            ((queue_s *)qp)->back = newNode;
            return 0;
        }
    }
}

void* qget(queue_t *qp){
    if(qp == NULL){
        return 1;
    }
    struct node *newNode = ((queue_s *)qp)->front;
    ((queue_s *)qp)->front = (((queue_s *)qp)->front)->next;
    (((queue_s *)qp)->front)->next = NULL;

    return newNode->element;
}

void qapply(queue_t *qp, void (*fn)(void* elementp)){
    if(qp == NULL){
        return 1;
    }
    struct node *newNode = malloc(sizeof(node_t));
    for (newNode = (node_t*)(((queue_s *)qp)->front); newNode != NULL; newNode = newNode->next) {
        fn(newNode->element);
    }
}