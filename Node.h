#ifndef _NODE_H_
#define _NODE_H_

typedef struct Edge_t Edge;

typedef struct Node_t{
     char * label;
     int visited; // 0 for not visited and 1 for visited
     Edge ** edges;
     int edgesCount;
     int distanceFromOrigin;
     char * path;
}Node;

typedef Node NULL_NODE;

void markVisited(Node node);
void unMarkVisited(Node node);
void changeLabel(Node node, char * newLabel);
void printNode(Node node);

#endif