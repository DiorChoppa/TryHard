#include <iostream>
#include <vector>
#include <map>

template <typename T>
T sqr(T val){
	return val * val;
}

template <typename T>
std::vector<T> sqr(std::vector<T> v){
	std::vector<T> result;
	for (const T& i : v){
		result.push_back(i*i);
	}
	return result;
}

template <typename Key, typename Value>
std::map<Key, Value> sqr(std::map<Key, Value> m){
	std::map<Key, Value> result;
	for(const auto& p : m)
		result[p.first] = sqr(p.second);
	return result;
}

template <typename First, typename Second>
std::pair<First, Second> sqr(std::pair<First, Second>& p){
	return {sqr(p.first), sqr(p.second)};
}

int main() {
	std::vector<int> v = {1, 2, 3};
	std::cout << "vector:";
	for (int x : sqr(v)) {
	std::cout << ' ' << x;
	}
	std::cout << std::endl;

	std::map<int, std::pair<int, int>> map_of_pairs = {
	{4, {2, 2}},
	{7, {4, 3}}
	};
	std::cout << "map of pairs:" << std::endl;
	for (const auto& x : sqr(map_of_pairs)) {
	std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
	}
}