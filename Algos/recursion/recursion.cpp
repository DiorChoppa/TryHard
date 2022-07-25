#include <iostream>

int factorial(int x){
	if (x == 1) return 1;
	else {
		return x * factorial(x - 1);
	}
}

int main (){
	std::cout << factorial(5) << std::endl;
	std::cout << factorial(6) << std::endl;
	std::cout << factorial(7) << std::endl;
}