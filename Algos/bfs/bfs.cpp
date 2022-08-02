#include <iostream>
#include <map>
#include <vector>
#include <queue>

template <typename T>
class Graph {
	std::map<T, std::vector<T>> adjList;

	public:
		Graph() {}
	
	void addEdge(T u, T v, bool bidir=true){
		adjList[u].push_back(v);
		if(bidir) adjList[v].push_back(u);
	}

	void printAdjList(){
		for (const auto& key : adjList){
			std::cout << key.first << " —> ";
			for (const auto& neighbour : key.second){
				std::cout << neighbour << ", ";
			}
			std::cout << std::endl;
		}
	}

	void bfs(T src){
		std::queue<T> q;
		std::map<T, bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T node = q.front();
			std::cout << node << ", ";
			q.pop();

			for(const auto neighbour : adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
};

int main() {
	Graph<int> G;

	G.addEdge(0, 1);
	G.addEdge(1,2);
    G.addEdge(0,4);
    G.addEdge(2,4);
    G.addEdge(2,3);
    G.addEdge(3,5);
    G.addEdge(3,4);

    std::cout << "The Graph is" << std::endl;
    G.printAdjList();
    std::cout << std::endl;

	std::cout << "The Breadth First Search from Node 0" << std::endl;
	G.bfs(0);

	return 0;
}