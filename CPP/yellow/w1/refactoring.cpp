#include <iostream>
#include <vector>
#include <map>
#include <sstream>

template <typename Collection>
std::string Join (const Collection& c, char d){
	std::stringstream ss;
	bool first = true;
	for(const auto& i : c){
		if(!first)
			ss << d;
		first = false;
		ss << i;
	}
	return ss.str();
}

template <typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const std::pair<First, Second>& p){
	return out << "(" << p.first << "," << p.second << ")";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vi){
	return out << "[" << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& out, const std::map<Key, Value>& m){
	return out << '{' << Join(m, ',') << '}';
}

int main() {
	std::vector<std::vector<int>> vi = {{1, 4}, {2, 3}};
	std::pair<int, int> m1 = {1, 2};
	std::map<double, double> m2 = {{1.4, 2.1}, {3.4, 4}};
	std::cout << vi << std::endl << m1 << std::endl << m2;
	return 0;
}