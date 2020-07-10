#include <iostream>

using namespace std;

/* Creates new graph by user */
int **createGraph(int size)
{
    int **graph = new int*[size];
    for(int i = 0; i < size; ++i)
        graph[i] = new int[size];

    int input;
    cout << "\tEnter only upper triangular part of the graph" << endl;
    for(int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i != j) {
                cout << "(" << i << ", " << j << "): ";
                do {
                   cin >> input;
                } while (input < 0 || input > 1);
                graph[i][j] = input; 
                graph[j][i] = input;
            }
            else {
                graph[i][j] = 0;
            }
        }
    }
    return graph;
}

/* Creates new graph with values either one or zero*/
int **createRandomGraph(int size)
{
    int **graph = new int*[size];
    for(int i = 0; i < size; ++i)
        graph[i] = new int[size];
    
    for(int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i != j) {
                graph[i][j] = rand() % 2;
                graph[j][i] = graph[i][j];
            }
            else {
                graph[i][j] = 0;
            }
        }
    }
    return graph;
}

/* Prints graph */
void printGraph(int **graph, int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

/* Checks whether vertex was visited before */
bool isVisited(int vertex, int* visited, int visited_len)
{
	for (int i = 0; i < visited_len; ++i)
		if ((i == vertex) && (visited[i] == 1))
			return true;
	return false;
}

/* Checks whether all vertecies have been visited */ 
bool isAllVisited(int* visited, int visited_len)
{
	for (int i = 0; i < visited_len; ++i)
		if (visited[i] == 0)
			return false;
	return true;
}

/* Checks whether there is a path from current vertex to start vertex */
bool isTherePathToStart(int** graph, int startVertex, int curVertex)
{
	return graph[curVertex][startVertex];
}

/* Finds a path to another non-visited vertex */
int findAnotherVertex(int** graph, int size, 
                        int curVertex, int* visited)
{
	for (int i = 0; i < size; ++i) {
		if ((i != curVertex) && (graph[curVertex][i] == 1) 
			&& !isVisited(i, visited, size))
			return i;
	}	

	return -1;
}

/* Determines whether the graph is Gamilton's graph */
bool determineGamilton(int** graph, int size, int startVertex, 
                        int curVertex, int* visited)
{
	/* Halts if all visited and there is a path to start */
	if (isAllVisited(visited, size) && isTherePathToStart(graph, 
													startVertex, curVertex))
		return true;
	
	/* Mark the vertex we are in */
	visited[curVertex] = 1;
	
	/* Continue recursion */
	int	nextVertex = findAnotherVertex(graph, size, curVertex, visited);
	
	if (nextVertex == -1)
		return false;
	
	return determineGamilton(graph, size, startVertex, nextVertex, visited);
}

/* Interface for determining whether the graph is Gamilton's graph*/
int isGamilton(int** graph, int size)
{
	/* Storing visited vertices */
	int* visited = new int[size];
	
	/* Initializing with zeros*/	
	for (int i = 0; i < size; ++i)
		visited[i] = 0;
	
	delete[] visited;
	return determineGamilton(graph, size, 0, 0, visited);
}

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


