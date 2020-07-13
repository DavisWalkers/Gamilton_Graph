#include "test.h"
#include "is_gamilton.h"

using namespace std;
using namespace chrono;

/* Deteles the graph `*/
void deleteGraph(int **graph, int size)
{
    for(int i = 0; i < size; ++i)
        delete[] graph[i];

    delete[] graph;
}

void testCorrectness()
{
    cout << "\tTest for correctness" << endl;

    /* Test 1, size = 3 */
    // 0, 1, 1 
    // 1, 0, 1 
    // 1, 1, 0

    int size = 3;
    int **graph = new int*[size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];

    graph[0][0] = 0, graph[0][1] = 1, graph[0][2] = 1;
    graph[1][0] = 1, graph[1][1] = 0, graph[1][2] = 1;
    graph[2][0] = 1, graph[2][1] = 1, graph[2][2] = 0;

    bool actual = isGamilton(graph, size);
    bool expected = true;
    cout << "Test 1: " << ((actual == expected) ? "passed" : "not passed") << endl;
    deleteGraph(graph, size);

    /* Test 2, size = 5 */
    // 0, 1, 1, 0, 0, 
    // 1, 0, 1, 1, 1, 
    // 1, 1, 0, 0, 0, 
    // 0, 1, 0, 0, 0, 
    // 0, 1, 0, 0, 0, 

    size = 5;
    graph = new int*[size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];

    graph[0][0] = 0, graph[0][1] = 1, graph[0][2] = 1, graph[0][3] = 0, graph[0][4] = 0;
    graph[1][0] = 1, graph[1][1] = 0, graph[1][2] = 1, graph[1][3] = 1, graph[1][4] = 1;
    graph[2][0] = 1, graph[2][1] = 1, graph[2][2] = 0, graph[2][3] = 0, graph[2][4] = 0;
    graph[3][0] = 0, graph[3][1] = 1, graph[3][2] = 0, graph[3][3] = 0, graph[3][4] = 0;
    graph[4][0] = 0, graph[4][1] = 1, graph[4][2] = 0, graph[4][3] = 0, graph[4][4] = 0;

    actual = isGamilton(graph, size);
    expected = false;
    cout << "Test 2: " << ((actual == expected) ? "passed" : "not passed") << endl;
    deleteGraph(graph, size);
     
    /* Test 3, size = 7 */
    // 0, 1, 1, 0, 1, 0, 0, 
    // 1, 0, 1, 1, 1, 0, 0, 
    // 1, 1, 0, 0, 0, 0, 0, 
    // 0, 1, 0, 0, 0, 0, 1, 
    // 1, 1, 0, 0, 0, 1, 0, 
    // 0, 0, 0, 0, 1, 0, 1, 
    // 0, 0, 0, 1, 0, 1, 0, 

    size = 7;
    graph = new int*[size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];

    graph[0][0] = 0, graph[0][1] = 1, graph[0][2] = 1, graph[0][3] = 0, graph[0][4] = 1, graph[0][5] = 0, graph[0][6] = 0;
    graph[1][0] = 1, graph[1][1] = 0, graph[1][2] = 1, graph[1][3] = 1, graph[1][4] = 1, graph[1][5] = 0, graph[1][6] = 0;
    graph[2][0] = 1, graph[2][1] = 1, graph[2][2] = 0, graph[2][3] = 0, graph[2][4] = 0, graph[2][5] = 0, graph[2][6] = 0;
    graph[3][0] = 1, graph[3][1] = 1, graph[3][2] = 0, graph[3][3] = 0, graph[3][4] = 0, graph[3][5] = 0, graph[3][6] = 0;
    graph[4][0] = 1, graph[4][1] = 1, graph[4][2] = 0, graph[4][3] = 0, graph[4][4] = 0, graph[4][5] = 1, graph[4][6] = 0;
    graph[5][0] = 0, graph[5][1] = 0, graph[5][2] = 0, graph[5][3] = 0, graph[5][4] = 1, graph[5][5] = 0, graph[5][6] = 1;
    graph[6][0] = 0, graph[6][1] = 0, graph[6][2] = 0, graph[6][3] = 1, graph[6][4] = 0, graph[6][5] = 1, graph[6][6] = 0;
 
    actual = isGamilton(graph, size);
    expected = true;
    cout << "Test 3: " << ((actual == expected) ? "passed" : "not passed") << endl;
    deleteGraph(graph, size);

    /* Test 4, size = 10 */
    //     0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 
    //     1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
    //     1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 
    //     0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 
    //     1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 
    //     0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 
    //     0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 
    //     0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 
    //     0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 
    //     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 

    size = 10;
    graph = new int*[size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];

    graph[0][0] = 0, graph[0][1] = 1, graph[0][2] = 1, graph[0][3] = 0, graph[0][4] = 0, graph[0][5] = 0, graph[0][6] = 0, graph[0][7] = 0, graph[0][8] = 0, graph[0][9] = 0;
    graph[1][0] = 1, graph[1][1] = 0, graph[1][2] = 1, graph[1][3] = 1, graph[1][4] = 1, graph[1][5] = 0, graph[1][6] = 0, graph[1][7] = 0, graph[1][8] = 0, graph[1][9] = 0;
    graph[2][0] = 1, graph[2][1] = 1, graph[2][2] = 0, graph[2][3] = 0, graph[2][4] = 0, graph[2][5] = 0, graph[2][6] = 0, graph[2][7] = 1, graph[2][8] = 0, graph[2][9] = 0;
    graph[3][0] = 0, graph[3][1] = 1, graph[3][2] = 0, graph[3][3] = 0, graph[3][4] = 0, graph[3][5] = 0, graph[3][6] = 1, graph[3][7] = 0, graph[3][8] = 0, graph[3][9] = 0;
    graph[4][0] = 1, graph[4][1] = 1, graph[4][2] = 0, graph[4][3] = 0, graph[4][4] = 0, graph[4][5] = 1, graph[4][6] = 0, graph[4][7] = 0, graph[4][8] = 0, graph[4][9] = 0;
    graph[5][0] = 0, graph[5][1] = 0, graph[5][2] = 0, graph[5][3] = 0, graph[5][4] = 1, graph[5][5] = 0, graph[5][6] = 1, graph[5][7] = 0, graph[5][8] = 0, graph[5][9] = 0;
    graph[6][0] = 0, graph[6][1] = 0, graph[6][2] = 0, graph[6][3] = 1, graph[6][4] = 0, graph[6][5] = 1, graph[6][6] = 0, graph[6][7] = 0, graph[6][8] = 0, graph[6][9] = 0;
    graph[7][0] = 0, graph[7][1] = 1, graph[7][2] = 0, graph[7][3] = 0, graph[7][4] = 0, graph[7][5] = 0, graph[7][6] = 0, graph[7][7] = 0, graph[7][8] = 1, graph[7][9] = 0;
    graph[8][0] = 0, graph[8][1] = 0, graph[8][2] = 0, graph[8][3] = 0, graph[8][4] = 0, graph[8][5] = 0, graph[8][6] = 0, graph[8][7] = 1, graph[8][8] = 0, graph[8][9] = 1;
    graph[9][0] = 0, graph[9][1] = 0, graph[9][2] = 0, graph[9][3] = 0, graph[9][4] = 0, graph[9][5] = 0, graph[9][6] = 0, graph[9][7] = 0, graph[9][8] = 1, graph[9][9] = 0;
 
    actual = isGamilton(graph, size);
    expected = false;
    cout << "Test 4: " << ((actual == expected) ? "passed" : "not passed") << endl;
    deleteGraph(graph, size);
}

void test()
{
}
 
