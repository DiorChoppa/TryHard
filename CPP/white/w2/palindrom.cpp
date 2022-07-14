#include <iostream>
#include <vector>
#include <string>

bool palindrom(std::string str){
	std::vector<char> list;
	for(auto &c : str){
		list.push_back(c);
	}
	for(int i = 0; i < list.size() / 2; ++i){
		if(list[i] != list[list.size() - i - 1])
			return false;
	}
	return true;
}

int main(){
	std::string a;
	std::cin >> a;
	std::cout << palindrom(a);
	
	return 0;
}