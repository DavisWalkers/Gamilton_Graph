#include <iostream>
#include "is_gamilton.h"

using namespace std;

int main()
{            
    /* Initializating the graph */  
    int size;
    int **graph;
    char ans;
    bool byUser = false;

    cout << "Do you want to input a graph manually(y or n)? ";
    do {
        cin >> ans;
    } while (ans != 'y' && ans != 'n');

    byUser = (ans == 'y') ? true : false;

    cout << "Graph size(positive integer): ";
    do {
        cin >> size;
    } while (size < 1);

    if (byUser) {
        graph = createGraph(size);
    }
    else {
        srand(time(0));
        graph = createRandomGraph(size);
        printGraph(graph, size);
    }
    
    /* Checks Gamilton's graph */
    cout << (isGamilton(graph, size) ? "yes" : "no") << endl;

    for(int i = 0; i < size; ++i)
        delete[] graph[i];

	delete[] graph;

    return 0;
}

