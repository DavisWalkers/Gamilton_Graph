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

/* Interface for determining whether the graph is Gamilton's graph */
bool isGamilton(int **graph, int size);

#endif
