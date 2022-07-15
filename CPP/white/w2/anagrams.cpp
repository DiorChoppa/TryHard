#include <iostream>
#include <map>
#include <string>

std::map<char, int> construct(const std::string& s){
	std::map<char, int> m;
	for(const char& c : s){
		++m[c];
	}
	return m;
}

int main(){
	int n;
	std::string sa;
	std::string sb;
	std::cin >> n;
	while (n-- != 0){
		std::cin >> sa >> sb;
		std::map<char, int> a = construct(sa);
		std::map<char, int> b = construct(sb);
		if(a == b) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
	
	return 0;
}