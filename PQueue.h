#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include "Edge.h"

typedef struct PQUEUE_t
{
	Node * nodeList;
	int nodeCount; 
}PQueue;

Node * pop(PQueue * queue);
Node * poll(PQueue * queue);
void push(Node node, PQueue * queue);
void printQueue(PQueue queue);
int isEmpty(PQueue queue);
Node * removeNode(Node node, PQueue * queue);
#endif