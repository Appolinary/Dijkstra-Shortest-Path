#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PQueue.h"

int isEmpty(PQueue queue){
	if(queue.nodeCount > 0){
		return 0;
	}
	return 1;
}

Node * removeNode(Node node, PQueue * queue){

	int foundIndex = -1;

	for(int i = 0; i < queue->nodeCount; i++){
		if(strcmp(node.label, queue->nodeList[i].label) == 0){
			foundIndex = i;
			break;
		}
	}

	if(foundIndex < 0){
		return NULL;
	}

	Node * toReturn = malloc(sizeof(Node));
	*toReturn = queue->nodeList[foundIndex];

	for(int i = foundIndex; i < queue->nodeCount - 1; i++){
		queue->nodeList[i] = queue->nodeList[i + 1];
	}

	--(queue->nodeCount);

	return toReturn;

}

void push(Node node, PQueue * queue){

	queue->nodeList[queue->nodeCount] = node;
	queue->nodeCount++;

	//move up untill it is less than its parent
	int childIndex = queue->nodeCount - 1;
	int parentIndex = (childIndex - 1)/2;

	while(parentIndex >= 0 && queue->nodeList[parentIndex].distanceFromOrigin > queue->nodeList[childIndex].distanceFromOrigin){
		//swap and then keep going
		Node temp = queue->nodeList[childIndex];
		queue->nodeList[childIndex] = queue->nodeList[parentIndex];
		queue->nodeList[parentIndex] = temp;

		childIndex = parentIndex;
		parentIndex  = (childIndex - 1)/2;
	}
}

void trickleDown( PQueue * queue, int parentIndex ){
    
	//assume that left child is the smallest
	int leftChildIndex = 2*parentIndex + 1;
	int smallest = 0;

	if(leftChildIndex < queue->nodeCount && queue->nodeList[leftChildIndex].distanceFromOrigin < queue->nodeList[parentIndex].distanceFromOrigin){
		smallest = leftChildIndex;
	}

	int rightChildIndex = 2*parentIndex + 2;
	if(rightChildIndex < queue->nodeCount && queue->nodeList[rightChildIndex].distanceFromOrigin  < queue->nodeList[leftChildIndex].distanceFromOrigin){
		smallest = rightChildIndex;
	}

	if(smallest > 0){
		Node temp = queue->nodeList[smallest];
		queue->nodeList[smallest] = queue->nodeList[parentIndex];
		queue->nodeList[parentIndex] = temp;

		trickleDown(queue, smallest);
	}    
}

Node * pop(PQueue * queue){
	if(isEmpty(*queue)){
		//printf("got in there \n");
		return NULL;
	}

	 Node * toReturn = malloc(sizeof(Node)); *toReturn = queue->nodeList[0];
    //get the one at the bottom to its spot
    int n = queue->nodeCount - 1;
    Node node = queue->nodeList[n];
    (queue->nodeList[0]) = node;
    --(queue->nodeCount);
    //now from the top, heapify the graph;
    trickleDown(queue, 0);
    return toReturn;
}


Node * poll(PQueue * queue){
    if(isEmpty(*queue)){
    	return NULL;
    }
    Node * toReturn = malloc(sizeof(Node));
    *toReturn = queue->nodeList[0];

    return toReturn;
}

void printQueue(PQueue queue){	
	for(int i = 0; i < queue.nodeCount; i++){
		printf(" %s \n ", queue.nodeList[i].label);
	}
}
