#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::unordered_set<std::string> operator & (const std::unordered_set<std::string>& a,
											const std::unordered_set<std::string>& b){
	std::unordered_set<std::string> result;
	for(const auto& i : a){
		for(const auto& j : b){
			if (i==j)
				result.insert(i);
		}
	}
	return result;
}

void operator -= (std::unordered_set<std::string>& a,
			const std::unordered_set<std::string>& b){
	for (auto j = b.begin(); j != b.end(); j++){
		for (auto i = a.begin(); i != a.end();)
			if(*i == *j) i = a.erase(i);
			else i++;
	}
}

int main() {
	std::unordered_set<std::string> statesNeeded({"mt", "wa", "or", "if", "nv", "ut", "ca", "az"});

	std::unordered_map<std::string, std::unordered_set<std::string>> stations;
	stations.insert({"kone", {"id", "nv", "ut"}});
	stations.insert({"ktwo", {"wa", "id", "mt"}});
	stations.insert({"kthree", {"or", "nv", "ca"}});
	stations.insert({"kfour", {"nv", "ut"}});
	stations.insert({"kfive", {"ca", "az"}});

	std::unordered_set<std::string> finalStations;

	while(!statesNeeded.empty()){
		std::string bestStation;
		std::unordered_set<std::string> statesCovered;
		for(const auto& i : stations){
			std::unordered_set<std::string> coverage = i.second & statesNeeded;
			if (coverage.size() > statesCovered.size()){
				bestStation = i.first;
				statesCovered = coverage;
			}
		}
		statesNeeded -= statesCovered;
		finalStations.insert(bestStation);
	}

	for(const auto& i : finalStations){
		std::cout << i << std::endl;
	}

	// system("pause");
	return 0;
}