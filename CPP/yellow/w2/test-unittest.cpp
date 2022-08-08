#include <iostream>
#include <cassert>

int sum(int x, int y){
	return x + y;
}

void TestSum() {
	assert(sum(2, 3) == 5);
	assert(sum(-2, -3) == -5);
	assert(sum(-2, 0) == -2);
	assert(sum(-2, 2) == 0);
	std::cout << "OK" << std::endl;
}

int main() {
	TestSum();
	return 0;
}