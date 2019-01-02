#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


void markVisited(Node node){
      node.visited = 1;
}

void unMarkVisited(Node  node){
	node.visited = 0;
}

void changeLabel(Node node, char * newLabel){
	node.label = newLabel;
}

void printNode(Node node){
	printf("name : %s\n",  node.label);
	printf("visited : %d\n", node.visited);
}