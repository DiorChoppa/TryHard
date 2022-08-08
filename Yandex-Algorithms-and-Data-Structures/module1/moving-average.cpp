#include <iostream>
#include <vector>

template <typename T>
std::vector<double> moving_average(const std::vector<T>& v, T k){
	std::vector<double> res;
	T sum = 0;
	for(T i = 0; i < k; i++){
		sum += v[i];
	}
	res.push_back(static_cast<double>((double)sum/k));
	for(T i = 1; i <= v.size() - k; i++){
		sum = sum - v[i-1] + v[i+k-1];
		res.push_back((double)sum/k);
	}
	return res;
}

int main() {
	int n, k;
	std::vector<int> start;
	std::cin >> n;
	while(n--){
		int a;
		std::cin >> a; start.push_back(a);
	}
	std::cin >> k;
	
	std::vector<double> result = moving_average(start, k);
	for(const double& i : result){
		std::cout << i << " ";
	}
	return 0;
}