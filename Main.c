#include <stdio.h>
#include <stdlib.h>
#include "Edge.h"
#include "PQueue.h"
#include "DAlgorithm.h"

const int INFINITY = 100000; 

int main(int argc, char ** argv){

    Node node1 = {.label = "A", .visited = 0 , .edges = malloc(sizeof(Edge *)) , .edgesCount = 0, .distanceFromOrigin = 0, .path = "A"};
    Node node2  = {.label = "B", .visited = 0, .edges = malloc(sizeof(Edge *)) , .edgesCount = 0, .distanceFromOrigin = INFINITY, .path = malloc(sizeof(char) * 200) };
    Node node3 = {.label = "C", .visited = 0,  .edges = malloc(sizeof(Edge *)) , .edgesCount = 0, .distanceFromOrigin = INFINITY, .path = malloc(sizeof(char) * 200) };
    Node node4 = {.label = "D", .visited = 0 , .edges = malloc(sizeof(Edge *)) , .edgesCount = 0, .distanceFromOrigin = INFINITY, .path = malloc(sizeof(char) * 200) };
    Node node5 = {.label = "E", .visited = 0, .edges = malloc(sizeof(Edge *)) , .edgesCount = 0, .distanceFromOrigin = INFINITY, .path = malloc(sizeof(char) * 200) };

    PQueue queue = {.nodeList = malloc(sizeof(Node) * 20) , .nodeCount = 0};

    addEdge(&node1, &node2, 1);
    addEdge(&node1, &node3, 5);
    addEdge(&node3, &node4, 1);
    addEdge(&node3, &node5, 3);
    addEdge(&node2, &node4, 2);
    addEdge(&node2, &node5, 4);
    addEdge(&node4, &node5, 1);

    push(node1, &queue);

    algorithm(&queue);



    
    /*
    push(node1, &queue);
    push(node2, &queue);
    push(node3, &queue);
    push(node4, &queue);
    push(node5, &queue);

    removeNode(node4, &queue);

   
    Node * popped2 = pop(&queue);
    printf("%s \n", popped2->label);

    Node * popped3 = pop(&queue);
    printf("%s \n", popped3->label);

    Node * popped44 = pop(&queue);
    printf("%s \n", popped44->label);

    Node * popped444 = pop(&queue);
    printf("%s \n", popped444->label);

    Node * popped43 = pop(&queue);
    printf("%s \n", popped43->label);

    Node * popped5 = pop(&queue);
    printf("%s \n", popped5->label);
*/

	return 0;

}







