#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int main(){
	int q, n;
	std::map<int, std::set<std::string>> buses;

	std::cin >> q;
	while(q-- != 0){
		std::cin >> n;
		std::vector<std::string> v(n);
		for(std::string& s : v){
			std::cin >> s;
		}
		std::set<std::string> t(begin(v), end(v));
		int c = 0, j;
		for (const auto& i : buses){
			if(i.second == t){
				c = 1;
				j = i.first;
			}
		}
		if (c != 1){
			int s = buses.size() + 1;
			buses[s] = t;
			std::cout << "New bus " << s << std::endl;
		}
		else{
			std::cout << "Already exists for " << j << std::endl;
		}
	}
	
	return 0;
}