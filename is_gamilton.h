#ifndef IS_GAMILTON_H_SENTRY
#define IS_GAMILTON_H_SENTRY

#include <iostream>
#include <random>

/* Creates new graph by user */
int **createGraph(int size);

/* Randomly creates new graph */
int **createRandomGraph(int size);

/* Print graph */
void printGraph(int **graph, int size);

/* Checks whether the vertex has been visited before */
//static bool isVisited(int vertex, int *visited, int visited_len);

/* Checks whether all vertecies have been visited */
//static bool isAllVisited(int *visited, int visited_len);

/* Checks whether there is a path 
   from current vertex to start vertex */
//static bool isTherePathToStart(int **graph, int startVertex, int curVertex);

/* Finds a path to another non-visited vertex */
//static int findAnotherVertex(int **graph, int size,
//						int curVertex, int *visited);

/* Determines whether the graph is Gamilton's graph */
//static bool determineGamilton(int **graph, int size, int startVertex,
//						int curVertex, int *visited);

/* Interface for determining whether the graph is Gamilton's graph */
int isGamilton(int **graph, int size);

#endif
