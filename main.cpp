#include <iostream>
#include <chrono>
#include "is_gamilton.h"

using namespace std;
using namespace chrono;

static bool measureTime(int **graph, int size)
{
    auto start = high_resolution_clock::now(); 
    bool result = isGamilton(graph, size);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function (size = " << size << "): "
         << duration.count() << " microseconds" << endl;
    return result;
}

static void deleteGraph(int **graph, int size)
{
    for(int i = 0; i < size; ++i)
        delete[] graph[i];

    delete graph;
}

int main()
{            
    /* Testing function correctness */
    int size = 5;
    int **graph = new int*[size];

    for(int i = 0; i < size; ++i)
        graph[i] = new int[size];

    /* Manually fill in the graph */
    /* Test 1*/
    /*
        | 0 1 0 0 1 |
        | 1 0 1 1 0 |
        | 0 1 0 1 1 |
	| 0 1 1 0 0 |
	| 1 0 1 0 0 |
    */
    graph[0][0] = 0, graph[0][1] = 1, graph[0][2] = 0, graph[0][3] = 0, graph[0][4] = 1;
    graph[1][0] = 1, graph[1][1] = 0, graph[1][2] = 1, graph[1][3] = 1, graph[1][4] = 0;
    graph[2][0] = 0, graph[2][1] = 1, graph[2][2] = 0, graph[2][3] = 1, graph[2][4] = 1;
    graph[3][0] = 0, graph[3][1] = 1, graph[3][2] = 1, graph[3][3] = 0, graph[3][4] = 0;
    graph[4][0] = 1, graph[4][1] = 0, graph[4][2] = 1, graph[4][3] = 0, graph[4][4] = 0;
    
    /* Calculating result */
    bool result = isGamilton(graph, size);
    bool expected = true;

    cout << "Test 1: " << ((result == expected) ? "Passed" : "Not Passed") << endl;

    /* Test 2 */
    /*
        | 0 0 1 |
        | 0 0 1 |
        | 1 1 0 |
    */
	deleteGraph(graph, size);
	size = 3;	
	graph = new int*[size];
	for (int i = 0; i < size; ++i)
		graph[i] = new int[size];

    graph[0][0] = 0, graph[0][1] = 0, graph[0][2] = 1;
    graph[1][0] = 0, graph[1][1] = 0, graph[1][2] = 1;
    graph[2][0] = 1, graph[2][1] = 1, graph[2][2] = 0;

    /* Calculating result */
    result = isGamilton(graph, size);
    expected = false;

    cout << "Test 2: " << ((result == expected) ? "Passed" : "Not Passed") << endl;

    /* Measuring time on arbitrary graphs */
    /* Test 1: size = 5 */
    size = 5;
    graph = createRandomGraph(size);
    result = measureTime(graph, size);
	deleteGraph(graph, size);

    /* Test 2: size = 20 */
    size = 20;
    graph = createRandomGraph(size);
    result = measureTime(graph, size);
	deleteGraph(graph, size);

    /* Test 3: size = 100 */
    size = 100;
    graph = createRandomGraph(size);
    result = measureTime(graph, size);
	deleteGraph(graph, size);

    /* Test 4: size = 1000 */
    size = 1000;
    graph = createRandomGraph(size);
    result = measureTime(graph, size);
	deleteGraph(graph, size);

    return 0;
}

