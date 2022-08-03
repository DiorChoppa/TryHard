#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <limits>

int main(){
	using node_t = std::string;
	using node_cost_t = std::unordered_map<node_t, unsigned>;
	using graph_t = std::unordered_map<node_t, node_cost_t>;
	using parent_graph_t = std::unordered_map<node_t, node_t>;

	// Setup the graph
	graph_t graph;
	graph.reserve(4U);
	graph.emplace("start", node_cost_t{{"A", 6}, {"B", 2}});
	graph.emplace("A", node_cost_t{{"finish", 1}});
	graph.emplace("B", node_cost_t{{"A", 3}, {"finish", 5}});
	graph.emplace("finish", node_cost_t{});

	// Setup costs table
	node_cost_t costs{{"A", 6}, {"B", 2}, {"finish", std::numeric_limits<unsigned>::max()}};

	// Setup parents table
	parent_graph_t parents{{"A", "start"}, {"B", "start"}};

	// Vector of processed nodes
	std::vector<node_t> processed;
	processed.reserve(3U);

	// Lambda function to find the lowest cost node
	const auto find_lowest_cost_node = [&processed](const node_cost_t& costs){
		auto lowest_cost = std::numeric_limits<unsigned>::max();
		node_t lowest_cost_node{};
		for (const auto& nodeCost : costs){
			const auto& node = nodeCost.first;
			const auto& cost = nodeCost.second;

			if(cost < lowest_cost && std::find(processed.cbegin(), processed.cend(), node) == processed.cend()){
				lowest_cost = cost;
				lowest_cost_node = node;
			}
		}
		return lowest_cost_node;
	};
	
	// Node is B
	auto node = find_lowest_cost_node(costs);
	while(!node.empty()){
		const auto costSoFar = costs[node];
		const auto& neighbours = graph[node];

		for(const auto& neighbour : neighbours){
			const auto& currentNeighbourName = neighbour.first;
			const auto newCost = costSoFar + neighbour.second;

			if(newCost < costs[currentNeighbourName]){
				costs[currentNeighbourName] = newCost;
				parents[currentNeighbourName] = node;
			}
		}
		processed.push_back(node);

		node = find_lowest_cost_node(costs);
	}

	std::cout << "Cost form the start to each node: " << std::endl;

	// Prints finish 6 B 2 a 5
	for(const auto& cost : costs){
		std::cout << cost.first << " " << cost.second << std::endl;
	}
	return 0;
}