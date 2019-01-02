#ifndef _Edge_H_
#define _Edge_H_

#include "Node.h"

typedef struct Edge_t{
	 Node * fromNode;
	 Node  * toNode;
	int weight;
}Edge;
#endif