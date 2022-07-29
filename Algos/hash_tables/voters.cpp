#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, bool> vote_list;

void check_voter(const std::string& name) {
	auto search = vote_list.find(name);
	if (search == vote_list.end() || search->second == false){
		vote_list.insert({name, true});
		std::cout << "Let em vote!" << std::endl;
	} else {
		std::cout << "Kick em out!" << std::endl;
	}
}

int main() {
	check_voter("Tom");
	check_voter("Mike");
	check_voter("Mike");
	
	return 0;
}