#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


void addEdge(Node * start, Node * end, int weight){
     
     Edge edge = {.fromNode = start, .toNode = end, .weight = weight};

     //append it to the startNode
     start->edges[start->edgesCount] = malloc(sizeof(Edge));
     *(start->edges[start->edgesCount]) = edge;
     start->edgesCount++;


     //append it to the endNode but need to change the startNode and the endNode
     Edge edge2 = {.fromNode = end, .toNode = start, .weight = weight};
     end->edges[end->edgesCount] = malloc(sizeof(Edge));
     *(end->edges[end->edgesCount] ) = edge2;
     end->edgesCount++;

}


