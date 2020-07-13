#include "is_gamilton.h"

using namespace std;

/* Creates new graph by user */
int **createGraph(int size)
{	
	srand(time(0));

    int **graph = new int*[size];
    for(int i = 0; i < size; ++i)
        graph[i] = new int[size];
	
    int input;
    cout << "\tEnter only upper triangular part of the graph" << endl;
    for(int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            cout << "(" << i << ", " << j << "): ";
            do {
               cin >> input;
            } while (input < 0 || input > 1);
            graph[i][j] = input; 
            graph[j][i] = input;
        }
    }
    return graph;
}

/* Creates new graph with values either one or zero*/
int **createRandomGraph(int size, bool pureGamilton)
{
	int edges;
    int **graph = new int*[size];
    for(int i = 0; i < size; ++i)
        graph[i] = new int[size];
	
	for(int i = 0; i < size; ++i)
		for(int j = 0; j < size; ++j)
			graph[i][j] = 0;   

	for(int i = 0; i < size; ++i) {
		edges = rand() % 3 + 1;
		for(int j = i - 1; j >= 0; --j) {
			if (rand() % 2 && edges) {
				graph[i][j] = 1;
				graph[j][i] = 1;
				edges -= 1;
			}	
		}
	}

	if(pureGamilton) {
		for(int i = 0; i < size; ++i) {
			if (i == size - 1) {
				graph[i][0] = 1;
				graph[0][i] = 1;
				break;
			}
			if (graph[i][i + 1] == 1)
				continue;
			graph[i][i + 1] = 1;
			graph[i + 1][i] = 1;
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
static bool isVisited(int vertex, int* visited, int visited_len)
{
	for (int i = 0; i < visited_len; ++i)
		if ((i == vertex) && (visited[i] == 1))
			return true;
	return false;
}

/* Checks whether all vertecies have been visited */ 
static bool isAllVisited(int* visited, int visited_len)
{
	for (int i = 0; i < visited_len; ++i)
		if (visited[i] == 0)
			return false;
	return true;
}

/* Checks whether there is a path from current vertex to start vertex */
static bool isTherePathToStart(int** graph, int startVertex, int curVertex)
{
	return graph[curVertex][startVertex];
}

/* Finds a path to another non-visited vertex */
static int findAnotherVertex(int** graph, int size, 
                        int curVertex, int* visited, int *tried)
{
	for (int i = 0; i < size; ++i) {
		if ((i != curVertex) && (graph[curVertex][i] == 1) 
			&& !isVisited(i, visited, size) && !isVisited(i, tried, size))
			return i;
	}	

	return -1;
}

/* Determines whether the graph is Gamilton's graph */
static bool determineGamilton(int** graph, int size, int startVertex, 
                        int curVertex, int* visited)
{
	/* Mark the vertex we are in */
	visited[curVertex] = 1;

	/* Halts if all visited and there is a path to start */
	if (isAllVisited(visited, size) && isTherePathToStart(graph, startVertex, curVertex)) {
		return true;
	}
	
	/* Create an array for tried vertecies */
	int *vertexTried = new int[size];	
	
	for (int i = 0; i < size; ++i) 
		vertexTried[i] = 0;

	/* Get next vertex */
	int	nextVertex = findAnotherVertex(graph, size, curVertex, visited, vertexTried);

	/* If there is no vertex then halt */
	if (nextVertex == -1) {
		delete[] vertexTried;
		visited[curVertex] = 0;
		return false;
	}
	/* Else mark the vertex we want to try */
	else {
		vertexTried[nextVertex] = 1;
	}
	
	bool result = false;
	while (nextVertex != -1 && !result) {	
		result = determineGamilton(graph, size, startVertex, nextVertex, visited);
		if (result == false) {
			nextVertex = findAnotherVertex(graph, size, curVertex, visited, vertexTried);
			if (nextVertex != -1) 
				vertexTried[nextVertex] = 1;
			continue;
		}
	}

	delete[] vertexTried;

	if (result == false) 
		visited[curVertex] = 0;

	return result;
}

/* Interface for determining whether the graph is Gamilton's graph*/
bool isGamilton(int** graph, int size)
{
	/* Storing visited vertices */
	int* visited = new int[size];
	
	/* Initializing with zeros*/	
	for (int i = 0; i < size; ++i)
		visited[i] = 0;
	
	bool result = determineGamilton(graph, size, 0, 0, visited);
	delete[] visited;
	return result;
}
