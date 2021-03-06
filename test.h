#ifndef TEST_H_SENTRY
#define TEST_H_SENTRY

#include "is_gamilton.h"
#include <chrono>
#include <iomanip>

#define TEST_AMOUNT 50
#define DIFFERENT_SIZE 10

/* Tests function -- isGamilton() */
void testTime(bool pureGamilton = false);

/* Tests function -- isGamilton() for correctness*/
void testCorrectness();

/* Deletes the graph */
void deleteGraph(int **graph, int size);

#endif
