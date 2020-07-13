#include "test.h"

using namespace std;
using namespace chrono;

/* Deteles the graph `*/
void deleteGraph(int **graph, int size)
{
    for(int i = 0; i < size; ++i)
        delete[] graph[i];

    delete[] graph;
}

/* Measures time for an arbitrary graph					    */
/* - Returns pair (number of Gamilton graphs, average time) */
static long *testOnGraph(int size, int testAmount = TEST_AMOUNT)
{
	long *resultPair = new long[2]; 
	resultPair[0] = 0, resultPair[1] = 0;
	int **graph = NULL;

	for (int i = 0; i < testAmount; ++i) 
	{
		graph = createRandomGraph(size);
    	auto start = high_resolution_clock::now();
    	bool result = isGamilton(graph, size);
   		auto stop = high_resolution_clock::now();
   		auto duration = duration_cast<microseconds>(stop - start);
		resultPair[1] += duration.count();
    	if (result) 
			resultPair[0]++;	
		deleteGraph(graph, size);
	}
	resultPair[1] /= size;
	return resultPair;
}

void test()
{
	int size;
	long *testResult = NULL;

	cout << "The following test operate on " << TEST_AMOUNT 
			<< " graph" << endl;
	for (int i = 0; i < DIFFERENT_SIZE; ++i)
	{
		size = rand() % 20 + 1;
		testResult = testOnGraph(size);
		cout << setw(5) << left << "Test: " << setw(2) << i + 1;
		cout << setw(6) << " | size: ";
		cout << setw(3) << size;
		cout << setw(14) << " | average time(mcsec): ";
		cout << setw(5) << setprecision(3) << testResult[1];
		cout << setw(20) << " | Gamilton's graphs: " << testResult[0];
		cout << endl;
	}
}
 
