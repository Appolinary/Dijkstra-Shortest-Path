#include "DAlgorithm.h"

void algorithm(PQueue * queue){

     Node * start = pop(queue);

     if(start == NULL){
     	return;
     }

     //first mark it as visited
     start->visited = 1;

     printf("Node : %s , distanceFromOrigin : %d \n", start->label, start->distanceFromOrigin);

     //get the neighbouring edges
     for(int i = 0; i < start->edgesCount; i++){

     	//printf("got in here again %d \n", i);

     	if( start->edges[i]->toNode->visited == 0 && start->distanceFromOrigin + start->edges[i]->weight <= start->edges[i]->toNode->distanceFromOrigin){
     		//then need to change it and push it to the queue;

     		//remove it first
     		removeNode(*(start->edges[i]->toNode), queue);

     		//change it
     		start->edges[i]->toNode->distanceFromOrigin = start->distanceFromOrigin + start->edges[i]->weight;

     		//push it again to the queue
     		push(*(start->edges[i]->toNode), queue);

     	}

     }
     algorithm(queue);


}