#include <iostream>
#include <string>
#include <vector>

void printVector(std::vector<std::string> p){
	for(auto& c : p){
		std::cout << c << " ";
	}
	std::cout << std::endl;
}

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

int getSize(std::string str){
	int count = 0;
	for(char& c : str){
		count++;
	}
	return count;
}

std::vector<std::string> palindromFilter(const std::vector<std::string>& words, int min){
	std::vector<std::string> mew;
	for(auto& s : words){
		if (getSize(s) < min || palindrom(s) == false) continue;
		else mew.push_back(s);
	}
	return mew;
}

int main(){
	std::vector<std::string> v1 = {"abacaba", "aba"};
	std::vector<std::string> v2 = {"abacaba", "aba"};
	std::vector<std::string> v3 = {"weew", "bro", "code"};

	printVector(palindromFilter(v1, 5));
	printVector(palindromFilter(v2, 2));
	printVector(palindromFilter(v3, 4));

	return 0;
}