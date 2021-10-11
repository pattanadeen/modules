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

// typedef struct car {
// 	struct car *next;
// 	char plate[MAXREG];
// 	double price;
// 	int year;
// }  car_t;

typedef struct node {
 	struct node *next;
 	void *element;
} node_t;

typedef struct queue {
 	struct node *front;
    struct node *back;
} queue_s;

queue_t* qopen(void){
    // printf("test open\n");
    queue_s *qs = malloc(sizeof(*qs));
    qs->front = NULL;
    qs->back = NULL;
    return ((queue_t*)qs);
}

int32_t qput(queue_t *qp, void *elementp){
    // printf("success %p qp\n",qp);
    // printf("success %p &qp\n",qp);
    // printf("%p\n",&qp);
    // printf("%p\n",back);
    // printf("success %p &back\n",&back);
    if(((queue_s *)qp)->back == NULL){
        struct node *newNode = malloc(sizeof(*newNode));
        newNode->next = NULL;
        newNode->element = elementp;
        ((queue_s *)qp)->back = newNode;
        ((queue_s *)qp)->front = newNode;
        return 0;
    }
    else{
        printf("success for real\n");
        struct node *newNode = malloc(sizeof(*newNode));
        newNode->next = NULL;
        newNode->element = elementp;
        (((queue_s *)qp)->back)->next = newNode;
        ((queue_s *)qp)->back = newNode;
            // printf("%p\n",&newNode);
        free(newNode);
        return 0;
    }
}

void* qget(queue_t *qp){
    printf("%p\n", qp);

    return NULL;
}

// static car_t *make_car(char *platep,double price,int year) { 
//     car_t *cc;
// 	if(!(cc = (car_t*)malloc(sizeof(car_t)))) {
// 	    printf("[Error: malloc failed allocating car]\n");
//         return NULL;
//     }
// 	cc->next = NULL;
//     strcpy(cc->plate,platep);
//     cc->price=price;
//     cc->year=year;
//     return cc;
// }

//  int main(int argc, char *argv[]) {
//     // printf("%p qp\n",qp);
//     // printf("%p &qp\n",&qp);
//     // printf("%p back null\n",back);
//     // printf("%p &back\n",&back);
//     queue_t *qp = qopen();
//     // printf("%p qp\n",qp);
//     // printf("%p &qp\n",&qp);
//     car_t *test1 = make_car("Bill",19000,2020);
//     car_t *test2 = make_car("Sam",21000.75,2019);
//     car_t *test3 = make_car("John",20000.25,2018);
//     car_t *test4 = make_car("Fred",20000,2021);
    
//     // struct node *node1;
//     // node1->next = NULL;
//     // node1->element = test1;

//     // ((queue_s *)qp)->front = node1;
//     // ((queue_s *)qp)->back = node1;

//     // printf("%p back node1\n", back);
//     printf("%p qp1\n",((queue_s *)qp)->back);
//     int ans = qput(qp, &test2);
//     printf("%d\n", ans);
//     printf("%p qp2\n",((queue_s *)qp)->back);
//     // void *elementpp = qget(qp);
//     // struct node *testnode = back;
//     // car_t *testcar = (car_t*)testnode->element;
//     // printf("%d",testcar->year);
//     free(test1);
//     free(test2);
//     free(test3);
//     free(test4);
//     exit(EXIT_SUCCESS);
// }