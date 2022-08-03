#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>

#define V 9

int minDistance(int dist[], bool sptSet[]){
	int min = INT32_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

		return min_index;
}

void printSolution(int dist[]){
	std::cout << "Vertex \t Distance from Source" << std::endl;
	for (int i = 0; i < V; i++)
		std::cout << i << " \t\t" << dist[i] << std::endl;
}

void dijkstras(int graph[V][V], int src){
	int dist[V];
	bool sptSet[V];

	for (int i = 0; i < V; i++){
		dist[i] = INT32_MAX, sptSet[i] = false;
	}
	
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++){
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		for(int v = 0; v < V; v++)
			if(!sptSet[v] && graph[u][v] && dist[u] != INT32_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}

int main() {
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstras(graph, 0);

	return 0;
}